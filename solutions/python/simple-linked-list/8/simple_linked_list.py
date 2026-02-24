""" Implement a LIFO stack """
from typing import Self


class EmptyListException(Exception):
    """ Exception raised when list is empty.
        message: explanation of the error
    """

    def __init__(self, message: str) -> None:
        self.message = message


class Node:
    def __init__(self, value: int, next: None):
        self._value = value
        self._next = next

    def value(self) -> int:
        return self._value

    def next(self) -> Self:
        return self._next

    def __str__(self) -> str:
        return str(self.value)


class LinkedList:
    def __init__(self, values: list[int] | None = None):
        self._head = None
        if values is not None:
            for value in values:
                self.push(value)

    def __iter__(self):
        node = self._head
        while node:
            yield node.value()
            node = node.next()

    def __len__(self):
        node, count = self._head, 0
        while node:
            count += 1
            node = node.next()
        return count

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
        node = Node(value, self._head)
        self._head = node

    def pop(self):
        node = self.head()
        self._head = self.head().next()
        return node.value()

    def reversed(self) -> list[int]:
        result = []
        node = self._head
        while node:
            result.insert(0, node.value())
            node = node.next()
        return result
