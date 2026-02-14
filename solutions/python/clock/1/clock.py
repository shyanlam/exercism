class Clock:
    MINUTES_IN_DAY = 24 * 60

    @staticmethod
    def hm_to_m(hour: int, minute: int) -> int:
        return (hour * 60 + minute) % Clock.MINUTES_IN_DAY

    @staticmethod
    def m_to_hm(minutes: int) -> tuple[int, int]:
        return divmod(minutes % Clock.MINUTES_IN_DAY, 60)

    def __init__(self, hour, minute):
        self.hour, self.minute = Clock.m_to_hm(Clock.hm_to_m(hour, minute))

    def __repr__(self):
        return f"Clock({self.hour}, {self.minute})"

    def __str__(self):
        return f"{self.hour:02}:{self.minute:02}"

    def __eq__(self, other):
        return self.hour == other.hour and self.minute == other.minute

    def to_minutes(self) -> int:
        return self.hour * 60 + self.minute

    def __add__(self, minutes) -> Clock:
        return Clock(*Clock.m_to_hm(self.to_minutes() + minutes))

    def __sub__(self, minutes) -> Clock:
        return Clock(*Clock.m_to_hm(self.to_minutes() + Clock.MINUTES_IN_DAY - minutes))

