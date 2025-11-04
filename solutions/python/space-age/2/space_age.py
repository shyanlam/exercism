class SpaceAge:
    EARTH_YEAR_IN_SECONDS = 365.25 * 24 * 60 * 60
    ORBITAL_PERIOD_IN_EARTH_YEAR: dict[str, float] = {
        "Mercury": 0.2408467,
        "Venus": 0.61519726,
        "Earth": 1.0,
        "Mars": 1.8808158,
        "Jupiter": 11.862615,
        "Saturn": 29.447498,
        "Uranus": 84.016846,
        "Neptune": 164.79132
    }

    def __init__(self, seconds):
        self.earth_years = seconds / self.EARTH_YEAR_IN_SECONDS

    def __planet_years(self, planet: str) -> float:
        return round(self.earth_years / self.ORBITAL_PERIOD_IN_EARTH_YEAR[planet], 2)

    def on_mercury(self) -> float:
        return self.__planet_years("Mercury")

    def on_venus(self) -> float:
        return self.__planet_years("Venus")

    def on_earth(self) -> float:
        return self.__planet_years("Earth")

    def on_mars(self) -> float:
        return self.__planet_years("Mars")

    def on_jupiter(self) -> float:
        return self.__planet_years("Jupiter")

    def on_saturn(self) -> float:
        return self.__planet_years("Saturn")

    def on_uranus(self) -> float:
        return self.__planet_years("Uranus")

    def on_neptune(self) -> float:
        return self.__planet_years("Neptune")
