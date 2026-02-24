""" Implement a LIFO stack """
from typing import Self


class EmptyListException(Exception):
    """ Exception raised when list is empty.
        message: explanation of the error
    """

    def __init__(self, message: str) -> None:
        self.message = message


class Node:
    """ A linked list's node.
    """
    def __init__(self, value: int, next_node: None):
        self._value = value
        self._next = next_node

    def value(self) -> int:
        return self._value

    def next(self) -> Self:
        return self._next

    def __str__(self) -> str:
        return str(self.value)


class LinkedList:
    """ A singly linked list."""

    def __init__(self, values: list[int] | Self | None = None) -> None:
        self._head = None
        self._count = 0
        if values is not None:
            for value in values:
                self.push(value)

    def __iter__(self):
        node = self._head
        while node:
            yield node.value()
            node = node.next()

    def __len__(self):
        return self._count

    def __str__(self):
        result = "["
        node = self._head
        if node is not None:
            result += str(node)
            node = node.next()
            while node is not None:
                result += ", " + str(node)
                node = node.next()
        result += "]"
        return result

    def head(self) -> Node:
        if self._head is None:
            raise EmptyListException("The list is empty.")
        return self._head

    def push(self, value):
        self._head = Node(value, self._head)
        self._count += 1

    def pop(self):
        value = self.head().value()
        self._head = self.head().next()
        self._count -= 1
        return value

    def reversed(self) -> Self:
        return LinkedList(self)
