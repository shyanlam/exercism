from unittest import case
from itertools import count

ZERO = [
    ' _ ',  #
    '| |',  # 0
    '|_|',  #
    '   ']  # the fourth row is always blank]

ONE = [
    '   ',  #
    '  |',  # 1
    '  |',  #
    '   ']  # (blank fourth row)

TWO = [
    ' _ ',  #
    ' _|',  # 2
    '|_ ',  #
    '   ']  # (blank fourth row)

THREE = [
    ' _ ',  #
    ' _|',  # 3
    ' _|',  #
    '   ']  # (blank fourth row)

FOUR = [
    '   ',  #
    '|_|',  # 4
    '  |',  #
    '   ']  # (blank fourth row)

FIVE = [
    ' _ ',  #
    '|_ ',  # 5
    ' _|',  #
    '   ']  # (blank fourth row)

SIX = [
    ' _ ',  #
    '|_ ',  # 6
    '|_|',  #
    '   ']  # (blank fourth row)

SEVEN = [
    ' _ ',  #
    '  |',  # 7
    '  |',
    '   ']  # (blank fourth row)

EIGHT = [
    ' _ ',  #
    '|_|',  # 8
    '|_|',  #
    '   ']  # (blank fourth row)

NINE = [
    ' _ ',  #
    '|_|',  # 9
    ' _|',  #
    '   ']  # (blank fourth row)

OCR_LOOKUP = {
    tuple(ZERO): "0",
    tuple(ONE): "1",
    tuple(TWO): "2",
    tuple(THREE): "3",
    tuple(FOUR): "4",
    tuple(FIVE): "5",
    tuple(SIX): "6",
    tuple(SEVEN): "7",
    tuple(EIGHT): "8",
    tuple(NINE): "9"
}

def convert_single(pattern: list[str]) -> str:
    return OCR_LOOKUP.get(tuple(pattern), "?")

OCR_HEIGHT = 4
OCR_WIDTH = 3

def convert(input_grid: list[str]) -> str:
    if len(input_grid) % 4 != 0:
        raise ValueError("Number of input lines is not a multiple of four")
    if any(map(lambda row: len(row) % 3, input_grid)):
        raise ValueError("Number of input columns is not a multiple of three")

    row_count = len(input_grid)
    row_length = len(input_grid[0])
    row = col = 0
    result = ""
    for row in range(0, row_count, OCR_HEIGHT):
        if row > 0:
            result += ","
        for col in range(0, row_length, OCR_WIDTH):
            result += convert_single([line[col: col + OCR_WIDTH] for line in input_grid[row: row + OCR_HEIGHT]])
    return result
