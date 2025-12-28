def egg_count(display_value: int) ->int:
    # return display_value.bit_count()
    bit_count = 0
    while display_value:
        display_value &= display_value - 1
        bit_count += 1
    return bit_count