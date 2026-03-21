from datetime import datetime, timedelta
import re
from calendar import monthrange, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
from unittest import case


def new_datetime(dt: datetime, hour: int) -> datetime:
    return datetime(dt.year, dt.month, dt.day, hour)


def quarter_delivery(dt: datetime, quarter: int) -> datetime:
    month = quarter * 3
    year = dt.year if dt.month <= month else dt.year + 1
    _, last_day = monthrange(year, month)
    delivery = datetime(year=year, month=month, day=last_day, hour=8)
    if delivery.weekday() in [SATURDAY, SUNDAY]:
        delivery -= timedelta(days=delivery.weekday() - FRIDAY)
    return delivery


def delivery_date(start: str, description: str) -> str:
    meeting = datetime.fromisoformat(start)
    delivery: datetime = None
    match description:
        case "NOW":
            delivery = meeting + timedelta(hours=2)
        case "ASAP" if meeting.hour < 13:
            delivery = new_datetime(meeting, 17)
        case "ASAP":
            delivery = new_datetime(meeting + timedelta(days=1), 13)
        case "EOW" if meeting.weekday() in [MONDAY, TUESDAY, WEDNESDAY]:
            delivery = new_datetime(meeting + timedelta(days=5 - meeting.isoweekday()), 17)
        case "EOW":
            delivery = new_datetime(meeting + timedelta(days=7 - meeting.isoweekday()), 20)
        case "Q1":
            delivery = quarter_delivery(meeting, 1)
        case "Q2":
            delivery = quarter_delivery(meeting, 2)
        case "Q3":
            delivery = quarter_delivery(meeting, 3)
        case "Q4":
            delivery = quarter_delivery(meeting, 4)
        case _:  # <N>M
            month = int(description[:-1])
            year = meeting.year if meeting.month < month else meeting.year + 1
            delivery = datetime(year=year, month=month, day=1, hour=8)
            if delivery.weekday() in [SATURDAY, SUNDAY]:
                delivery += timedelta(days=7 - delivery.weekday())

    return delivery.isoformat()
