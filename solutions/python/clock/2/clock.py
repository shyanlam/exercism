class Clock:
    MINUTES_IN_DAY = 24 * 60

    def __init__(self, hour, minute):
        self.hour = (hour + minute // 60) % 24
        self.minute = minute % 60

    def __repr__(self):
        return f"Clock({self.hour}, {self.minute})"

    def __str__(self):
        return f"{self.hour:02}:{self.minute:02}"

    def __eq__(self, other):
        return self.hour == other.hour and self.minute == other.minute

    def __add__(self, minutes) -> Clock:
        return Clock(self.hour, self.minute + minutes)

    def __sub__(self, minutes) -> Clock:
        return Clock(self.hour, (self.minute + Clock.MINUTES_IN_DAY) - (minutes % Clock.MINUTES_IN_DAY))
