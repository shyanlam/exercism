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
        self.seconds = seconds

    def __seconds_to_years(self) -> float:
        return self.seconds / self.EARTH_YEAR_IN_SECONDS

    def __age_on_planet(self, planet: str) -> float:
        return round(self.__seconds_to_years() / self.ORBITAL_PERIOD_IN_EARTH_YEAR[planet], 2)

    def on_mercury(self) -> float:
        return self.__age_on_planet("Mercury")

    def on_venus(self) -> float:
        return self.__age_on_planet("Venus")

    def on_earth(self) -> float:
        return self.__age_on_planet("Earth")

    def on_mars(self) -> float:
        return self.__age_on_planet("Mars")

    def on_jupiter(self) -> float:
        return self.__age_on_planet("Jupiter")

    def on_saturn(self) -> float:
        return self.__age_on_planet("Saturn")

    def on_uranus(self) -> float:
        return self.__age_on_planet("Uranus")

    def on_neptune(self) -> float:
        return self.__age_on_planet("Neptune")
