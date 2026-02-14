class Clock:
    MINUTES_IN_DAY = 24 * 60

    def __init__(self, hour, minute):
        self._minute = (hour * 60 + minute) % Clock.MINUTES_IN_DAY

    @property
    def minute(self):
        return self._minute % 60

    @property
    def hour(self):
        return self._minute // 60

    def __repr__(self):
        return f"Clock({self.hour}, {self.minute})"

    def __str__(self):
        return f"{self.hour:02}:{self.minute:02}"

    def __eq__(self, other):
        return self._minute == other._minute

    def __add__(self, minutes):
        return Clock(0, self._minute + minutes)

    def __sub__(self, minutes):
        return Clock(0, self._minute + Clock.MINUTES_IN_DAY - (minutes % Clock.MINUTES_IN_DAY))

