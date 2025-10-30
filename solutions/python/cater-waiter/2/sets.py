"""Functions for compiling dishes and ingredients for a catering company."""


from sets_categories_data import (VEGAN,
                                  VEGETARIAN,
                                  KETO,
                                  PALEO,
                                  OMNIVORE,
                                  ALCOHOLS,
                                  SPECIAL_INGREDIENTS)


def clean_ingredients(dish_name: str, dish_ingredients: list[str]) -> tuple[str, set[str]]:
    """Remove duplicates from `dish_ingredients`.

    :param dish_name: str - containing the dish name.
    :param dish_ingredients: list[str] - dish ingredients.
    :return: tuple[str,set[str]] - containing (dish_name, ingredient set).

    This function should return a `tuple` with the name of the dish as the first item,
    followed by the de-duped `set` of ingredients as the second item.
    """

    return dish_name, set(dish_ingredients)


def check_drinks(drink_name: str, drink_ingredients: list[str]) -> str:
    """Append "Cocktail" (alcohol)  or "Mocktail" (no alcohol) to `drink_name`, based on `drink_ingredients`.

    :param drink_name: str - name of the drink.
    :param drink_ingredients: list[str] - ingredients in the drink.
    :return: str - drink_name appended with "Mocktail" or "Cocktail".

    The function should return the name of the drink followed by "Mocktail" (non-alcoholic) and drink
    name followed by "Cocktail" (includes alcohol).

    """
    drink_type: str = "Cocktail" if len(ALCOHOLS.intersection(drink_ingredients)) > 0 else "Mocktail"
    return f"{drink_name} {drink_type}"


def categorize_dish(dish_name: str, dish_ingredients: set[str]) -> str:
    """Categorize `dish_name` based on `dish_ingredients`.

    :param dish_name: str - dish to be categorized.
    :param dish_ingredients: set[str] - ingredients for the dish.
    :return: str - the dish name appended with ": <CATEGORY>".

    This function should return a string with the `dish name: <CATEGORY>` (which meal category the dish belongs to).
    `<CATEGORY>` can be any one of  (VEGAN, VEGETARIAN, PALEO, KETO, or OMNIVORE).
    All dishes will "fit" into one of the categories imported from `sets_categories_data.py`

    """
    categories: dict[str, set[str]] = {"VEGAN": VEGAN, "VEGETARIAN": VEGETARIAN, "PALEO": PALEO, "KETO": KETO, "OMNIVORE": OMNIVORE}
    for name, category in categories.items():
        if dish_ingredients.issubset(category):
            return f"{dish_name}: {name}"

    return f"{dish_name} UNKNOWN"


def tag_special_ingredients(dish: tuple[str, list[str]|set[str]]):
    """Compare `dish` ingredients to `SPECIAL_INGREDIENTS`.

    :param dish: tuple[str, list[str]|set[str]] - of (dish name, list of dish ingredients).
    :return: tuple[str, set[str]] - containing (dish name, dish special ingredients).

    Return the dish name followed by the `set` of ingredients that require a special note on the dish description.
    For the purposes of this exercise, all allergens or special ingredients that need to be tracked are in the
    SPECIAL_INGREDIENTS constant imported from `sets_categories_data.py`.
    """

    dish_name: str
    ingredients: list[str]|set[str]
    dish_name, ingredients = dish
    special_ingredients: set[set] = SPECIAL_INGREDIENTS.intersection(ingredients)
    return dish_name, special_ingredients


def compile_ingredients(dishes: list[set[str]]) -> set[str]:
    """Create a master list of ingredients.

    :param dishes: list - of dish ingredient sets.
    :return: set - of ingredients compiled from `dishes`.

    This function should return a `set` of all ingredients from all listed dishes.
    """

    return set().union(*dishes)


def separate_appetizers(dishes: list[str], appetizers: list[str]) -> list[str]:
    """Determine which `dishes` are designated `appetizers` and remove them.

    :param dishes: list[str] - of dish names.
    :param appetizers: list[str] - of appetizer names.
    :return: list[str] - of dish names that do not appear on appetizer list.

    The function should return the list of dish names with appetizer names removed.
    Either list could contain duplicates and may require de-duping.
    """

    return list(set(dishes).difference(appetizers))


def singleton_ingredients(dishes: list[set[str]], intersection: set[str]) -> set[str]:
    """Determine which `dishes` have a singleton ingredient (an ingredient that only appears once across dishes).

    :param dishes: list[set[str]] - of ingredient sets.
    :param intersection: constant set[str] - can be one of `<CATEGORY>_INTERSECTIONS` constants imported from `sets_categories_data.py`.
    :return: set[str] - containing singleton ingredients.

    Each dish is represented by a `set` of its ingredients.

    Each `<CATEGORY>_INTERSECTIONS` is an `intersection` of all dishes in the category. `<CATEGORY>` can be any one of:
        (VEGAN, VEGETARIAN, PALEO, KETO, or OMNIVORE).

    The function should return a `set` of ingredients that only appear in a single dish.
    """
    result = set()
    for dish in dishes:
        result = dish ^ result
    return result - intersection
