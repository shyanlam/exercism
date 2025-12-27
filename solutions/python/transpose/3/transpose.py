def transpose(text: str) -> str:
    str_list = text.splitlines()
    result = []
    for row, line in enumerate(str_list):
        for col, char in enumerate(line):
            if col >= len(result):
                result.append([]) # add column
            if len(result[col]) < row:
                result[col] += [' ' for n in range(row - len(result[col]))]
            result[col].append(char)

    return '\n'.join([''.join(x) for x in result])
