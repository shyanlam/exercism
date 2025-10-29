"""Functions to manage a users shopping cart items."""
from typing import Iterable

def add_item(current_cart: dict, items_to_add: Iterable[str]) -> dict[str, int]:
    """Add items to shopping cart.

    :param current_cart: dict[str, int] - the current shopping cart.
    :param items_to_add: iterable[str] - items to add to the cart.
    :return: dict - the updated user cart dictionary.
    """
    for item in items_to_add:
        current_cart.setdefault(item, 0)
        current_cart[item] += 1

    return current_cart


def read_notes(notes: Iterable[str]) -> dict[str, int]:
    """Create user cart from an iterable notes entry.

    :param notes: iterable of items to add to cart.
    :return: dict - a user shopping cart dictionary.
    """

    return dict.fromkeys(notes,1)


def update_recipes(ideas: dict[str, dict[str, int]], recipe_updates: Iterable[tuple[str, dict[str, int]]]) -> dict[
    str, dict[str, int]]:
    """Update the recipe ideas dictionary.

    :param ideas: dict - The "recipe ideas" dict.
    :param recipe_updates: iterable -  with updates for the ideas section.
    :return: dict - updated "recipe ideas" dict.
    """

    ideas.update(recipe_updates)
    return ideas


def sort_entries(cart: dict[str, int]) -> dict[str, int]:
    """Sort a users shopping cart in alphabetically order.

    :param cart: dict[str, int] - a users shopping cart dictionary.
    :return: dict[str, int] - users shopping cart sorted in alphabetical order.
    """

    return dict(sorted(cart.items()))


def send_to_store(cart: dict[str, int], aisle_mapping: dict[str, list[str | bool]]) -> dict[
    str, list[int | str | bool]]:
    """Combine users order to aisle and refrigeration information.

    :param cart: dict[str, in] - users shopping cart dictionary.
    :param aisle_mapping: dict[str, list[str|bool] - aisle and refrigeration information dictionary.
    :return: dict[str, int] - fulfillment dictionary ready to send to store.
    """

    result = {item: [count] + aisle_mapping[item] for item, count in cart.items()}
    return dict(sorted(result.items(), reverse=True))


def update_store_inventory(fulfillment_cart: dict[str, list[int | str | bool]],
                           store_inventory: dict[str, list[int | str | bool]]) -> dict[str, list[int | str | bool]]:
    """Update store inventory levels with user order.

    :param fulfillment_cart: dict[str, list[int | str | bool] - fulfillment cart to send to store.
    :param store_inventory: dict[str, list[int | str | bool] - store available inventory
    :return: dict[str, list[int | str | bool] - store_inventory updated.
    """

    for item, cart_info in fulfillment_cart.items():
        inventory = store_inventory.get(item)
        inventory[0] = inventory[0] - cart_info[0]
        if inventory[0] == 0:
            inventory[0] = "Out of Stock"
    return store_inventory
