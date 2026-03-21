import datetime
import re
import calendar


def delivery_date(start: str, description: str) -> str:
    meeting = datetime.datetime.fromisoformat(start)
    if description == "NOW":
        return (meeting + datetime.timedelta(hours=2)).isoformat()
    if description == "ASAP":
        if meeting.time().hour < 13:
            return (meeting.replace(hour=17, minute=0, second=0)).isoformat()
        else:
            return (meeting + datetime.timedelta(days=1)).replace(hour=13, minute=0, second=0).isoformat()
    if description == "EOW":
        if meeting.isoweekday() in [1, 2, 3]:
            delta_day = 5 - meeting.isoweekday()
            return (meeting + datetime.timedelta(days=delta_day)).replace(hour=17, minute=0, second=0).isoformat()
        elif meeting.isoweekday() in [4, 5]:
            delta_day = 7 - meeting.isoweekday()
            return (meeting + datetime.timedelta(days=delta_day)).replace(hour=20, minute=0, second=0).isoformat()
    if (match := re.match(r"([1-9]|1[012])M", description)) is not None:
        month = int(match.group(1))
        delivery = datetime.datetime(year=meeting.year if meeting.month < month else meeting.year + 1,
                                   month=month, day=1, hour=8)
        if delivery.isoweekday() in [6, 7]:
            delivery += datetime.timedelta(days=8 - delivery.isoweekday())
        return delivery.isoformat()
    if (match := re.match(r"Q([1-4])", description)) is not None:
        quarter = int(match.group(1))
        meeting_quarter = (meeting.month // 3) + 1
        year = meeting.year if meeting_quarter <= quarter else meeting.year + 1
        quarter_end_month = quarter * 3
        _, last_day = calendar.monthrange(year, quarter_end_month)
        delivery = datetime.datetime(year=year, month=quarter_end_month, day=last_day, hour=8)
        if delivery.isoweekday() in [6, 7]:
            delivery -= datetime.timedelta(days=delivery.isoweekday() - 5)
        return delivery.isoformat()

    raise ValueError("invalid description")

#
# if __name__ == "__main__":
#     def do_delivery_date(start: str, description: str, expected: str):
#         print(f"delivery_date({start}, {description}) = ", end="")
#         print(f"{delivery_date(start, description)}")
#         print("expected =", expected)
#
#
#     # do_delivery_date("2013-11-21T15:30:00", "11M", "2014-11-03T08:00:00")
#     do_delivery_date("2008-12-21T14:50:00", "ASAP", "2008-12-22T13:00:00")
#     do_delivery_date("2003-01-01T10:45:00", "Q1", "2003-03-31T08:00:00")
