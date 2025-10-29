"""Functions which helps the locomotive engineer to keep track of the train."""


def get_list_of_wagons(*wagons_list: int) -> list[int]:
    """Return a list of wagons.

    :param: int arbitrary number of wagons.
    :return: list[int] - list of wagons.
    """
    return list(wagons_list)


def fix_list_of_wagons(each_wagons_id: list[int], missing_wagons: list[int]) -> list[int]:
    """Fix the list of wagons.

    :param each_wagons_id: list[int] - the list of wagons.
    :param missing_wagons: list[int] - the list of missing wagons.
    :return: list[int] - list of wagons.
    """
    a, b, c, *rest = each_wagons_id
    return [c, *missing_wagons, *rest, a, b]


def add_missing_stops(*route: dict[str, str], **stops: dict[str, str]) -> dict[str, str]:
    """Add missing stops to route dict.

    :param route: dict[str, str] - the dict of routing information.
    :param: dict[str, str] arbitrary number of stops.
    :return: dict[str, str] - updated route dictionary.
    """
    return route[0] | {"stops": list(stops.values())}


def extend_route_information(route: dict[str, str], more_route_information: dict[str, str]) -> dict[str, str]:
    """Extend route information with more_route_information.

    :param route: dict[str, str] - the route information.
    :param more_route_information: dict[str, str] -  extra route information.
    :return: dict[str, str] - extended route information.
    """
    return route | more_route_information



def fix_wagon_depot(wagons_rows: list[list[tuple[int, str]]]) -> list[list[tuple[int, str]]]:
    """Fix the list of rows of wagons.

    :param wagons_rows: list[list[tuple[int, str]] - the list of rows of wagons.
    :return: list[list[tuple[int, str]] - list of rows of wagons.
    """
    return list(list(x) for x in zip(*wagons_rows))

