"""Functions for calculating steps in exchanging currency.

Python numbers documentation: https://docs.python.org/3/library/stdtypes.html#numeric-types-int-float-complex

Overview of exchanging currency when travelling: https://www.compareremit.com/money-transfer-tips/guide-to-exchanging-currency-for-overseas-travel/
"""
from math import floor


def exchange_money(budget : float, exchange_rate : float) -> float:
    """
    return the exchanged foreign currency.
    :param budget: float - amount of domestic currency you are planning to exchange.
    :param exchange_rate: float - amount of domestic currency to one unit of foreign currency.
    :return: float - exchanged value of the foreign currency you can receive.
    """

    return budget / exchange_rate


def get_change(budget : float, exchanging_value : float) -> float:
    """
    return the amount of money left after exchanged.
    :param budget: float - amount of money you own.
    :param exchanging_value: float - amount of your money you want to exchange now.
    :return: float - amount left of your starting currency after exchanging.
    """

    return budget - exchanging_value


def get_value_of_bills(denomination, number_of_bills) -> int:
    """
    return the total amount of value of the bills.
    :param denomination: int - the value of a bill.
    :param number_of_bills: int - total number of bills.
    :return: int - calculated value of the bills.
    """

    return denomination * number_of_bills


def get_number_of_bills(amount : float, denomination : int) -> int:
    """
    return the number of bills received given the denomination of each bill.
    :param amount: float - the total starting value.
    :param denomination: int - the value of a single bill.
    :return: int - number of bills that can be obtained from the amount.
    """

    return floor(amount / denomination)


def get_leftover_of_bills(amount : float, denomination : int) -> float:
    """
    return the "leftover" amount out of get_number_of_bills().
    :param amount: float - the total starting value.
    :param denomination: int - the value of a single bill.
    :return: float - the amount that is "leftover", given the current denomination.
    """

    return amount - get_number_of_bills(amount, denomination) * denomination


def exchangeable_value(budget, exchange_rate, spread, denomination):
    """
    return the amount of money one gets given the exchange rate, spread and denomination.
    :param budget: float - the amount of your money you are planning to exchange.
    :param exchange_rate: float - the unit value of the foreign currency.
    :param spread: int - percentage that is taken as an exchange fee.
    :param denomination: int - the value of a single bill.
    :return: int - maximum value you can get.
    """

    effective_rate = exchange_rate * (1 + spread/100)
    foreign_amount = exchange_money(budget, effective_rate)
    return get_value_of_bills(denomination, get_number_of_bills(foreign_amount, denomination))
