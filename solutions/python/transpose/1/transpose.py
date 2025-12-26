def transpose(text: str) -> str:
    str_list = text.split("\n")
    row_count = len(str_list)
    # print(f"{str_list = }")
    len_list = list(map(len, str_list))
    for right in range(len(len_list)-1, 0, -1):
        for left in range(right):
            if len_list[left] < len_list[right]:
                str_list[left] += ' ' * (len_list[right] - len_list[left])
                len_list[left] = len_list[right]
    max_len = max(len_list)
    max_len_index = len_list.index(max_len)
    # Before:
    #    <r0c0>, <r0c1>, <r0c2>, <r0c3>
    #    <r1c0>, <r1c1>, <r1c2>, <r1c3>
    #    <r2c0>, <r2c1>, <r2c2>, <r2c3>
    # After:
    #    <r0c0>, <r1c0>, <r2c0>
    #    <r0c1>, <r1c1>, <r2c1>,
    #    <r0c2>, <r1c2>, <r2c2>,
    #    <r0c3>, <r1c3>, <r2c3>,
    result: list[str] = list()
    for col in range(max_len):
        new_str = ""
        for row in range(row_count):
            try:
                new_str += str_list[row][col]
            except IndexError:
                break

        result.append(new_str)
    return "\n".join(result)
