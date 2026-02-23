""" Implement a LIFO stack """

class EmptyListException(Exception):
    """ Exception raised when list is empty.
        message: explanation of the error
    """

    def __init__(self, message: str) -> None:
        self.message = message


class Node:
    def __init__(self, value: int, next: Node = None):
        self.__value = value
        self.__next = next

    def _value(self) -> int:
        return self.__value

    def _next(self):
        return self.__next

    def __str__(self) -> str:
        return str(self.__value)


class LinkedList:
    def __init__(self, values: list[int] | None = None):
        self._head = None
        if values is not None:
            for value in values:
                self.push(value)

    def __iter__(self):
        node = self._head
        while node:
            yield node._value()
            node = node._next()

    def __len__(self):
        node, count = self._head, 0
        while node:
            count += 1
            node = node._next()
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
        self._head = self.head()._next()
        return node._value()

    def reversed(self) -> list[int]:
        result = []
        node = self._head
        while node:
            result.insert(0, node._value())
            node = node._next()
        return result

# if __name__ == "__main__":
#     def LinkedList_Test(values: list[int] | None) -> None:
#         ll = LinkedList(values)
#         for v in ll:
#             print(v)
#         print(ll)
#         print("ll.pop() =", ll.pop())
#         print("len(ll) =", len(ll))
#         print("ll.head().value() =", ll.head()._value())
#
#
#     LinkedList_Test([3, 4, 5])
