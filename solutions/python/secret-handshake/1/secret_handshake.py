HANDSHAKE: list[tuple[int, str]] = [
    (0b00001, "wink"),
    (0b00010, "double blink"),
    (0b00100, "close your eyes"),
    (0b01000, "jump"),
    #(0b10000, "reverse"),
]

def commands(binary_str: str) -> list[str]:
    binary_value = int(binary_str, 2)
    actions: list[str] = []
    for value, action in HANDSHAKE:
        if value & binary_value:
            actions.append(action)

    if binary_value & 0b10000:
        actions.reverse()

    return actions
