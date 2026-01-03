# Globals for the directions
# Change the values as you see fit
from unittest import case

NORTH = 0
EAST = 1
SOUTH = 2
WEST = 3

DIRECTION_ADVANCE = {NORTH: (0, 1), EAST: (1, 0), SOUTH: (0, -1), WEST: (-1, 0)}

class Robot:
    def __init__(self, direction=NORTH, x_pos=0, y_pos=0):
        self._direction = direction
        self._x_pos = x_pos
        self._y_pos = y_pos

    @property
    def direction(self):
        """ Direction of the robot"""
        return self._direction

    @property
    def x_pos(self):
        """ X position of the robot"""
        return self._x_pos

    @property
    def y_pos(self):
        """ Y position of the robot"""
        return self._y_pos

    @property
    def coordinates(self) -> tuple[int, int]:
        return self._x_pos, self._y_pos

    def move(self, commands: str):
        for cmd in commands:
            if cmd in ("R", "L"):
                self._direction = (4 + self._direction + (1 if cmd == "R" else -1)) % 4

            elif cmd == "A":
                self._x_pos += DIRECTION_ADVANCE[self.direction][0]
                self._y_pos += DIRECTION_ADVANCE[self.direction][1]
            else:
                raise ValueError(cmd)
