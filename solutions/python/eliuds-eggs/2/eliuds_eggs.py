def egg_count(display_value: int) ->int:
    # return display_value.bit_count()
    return bin(display_value).count('1')
