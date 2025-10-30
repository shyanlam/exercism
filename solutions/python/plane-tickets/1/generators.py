"""Functions to automate Conda airlines ticketing system."""
from typing import Generator

def generate_seat_letters(number: int) -> Generator[str, None, None]:
    """Generate a series of letters for airline seats.

    :param number: int - total number of seat letters to be generated.
    :return: generator - generator that yields seat letters.

    Seat letters are generated from A to D.
    After D it should start again with A.

    Example: A, B, C, D

    """

    for n in range(number):
        yield "ABCD"[n % 4]


def generate_seats(number: int) -> Generator[str, None, None]:
    """Generate a series of identifiers for airline seats.

    :param number: int - total number of seats to be generated.
    :return: generator - generator that yields seat numbers.

    A seat number consists of the row number and the seat letter.

    There is no row 13.
    Each row has 4 seats.

    Seats should be sorted from low to high.

    Example: 3C, 3D, 4A, 4B

    """
    row: int = 1
    counter: int = 0
    seats = generate_seat_letters(number)
    while counter < number:
        if row == 13:
            row = 14
        for c in range(counter, min(counter + 4, number)):
            seat: str = next(seats)
            yield f"{row}{seat}"
        row += 1
        counter += 4


def assign_seats(passengers: list[str]) -> dict[str, str]:
    """Assign seats to passengers.

    :param passengers: list[str] - a list of strings containing names of passengers.
    :return: dict - with the names of the passengers as keys and seat numbers as values.

    Example output: {"Adele": "1A", "Björk": "1B"}

    """
    seat = generate_seats(len(passengers))
    return dict([(passenger, next(seat)) for passenger in passengers])


def generate_codes(seat_numbers: list[str], flight_id: str) -> Generator[str, None, None]:
    """Generate codes for a ticket.

    :param seat_numbers: list[str] - list of seat numbers.
    :param flight_id: str - string containing the flight identifier.
    :return: generator - generator that yields 12 character long ticket codes.

    """

    for seat_number in seat_numbers:
        yield f"{f'{seat_number}{flight_id}':<012}"
