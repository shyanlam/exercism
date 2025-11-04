import datetime

ONE_GIGA_SECOND = datetime.timedelta(seconds=1_000_000_000)


def add(moment: datetime) -> datetime:
    return moment + ONE_GIGA_SECOND