from collections import defaultdict


class Record:
    def __init__(self, record_id: int, parent_id: int):
        self.record_id = record_id
        self.parent_id = parent_id

    def __str__(self) -> str:
        return f"(record_id = {self.record_id}, parent_id = {self.parent_id})"

    def __repr__(self) -> str:
        return f"Record(record_id = {self.record_id}, parent_id = {self.parent_id})"


class Node:
    def __init__(self, node_id: int):
        self.node_id = node_id
        self.children: list[Node] = []

    def __repr__(self) -> str:
        children_str = "[" + ", ".join([str(child) for child in self.children]) + "]"
        return f"(node_id = {self.node_id}, children = {children_str})"


def BuildTree(records: list[Record]) -> Node | None:
    if records is None or len(records) == 0:
        return None

    records.sort(key=lambda x: x.record_id)
    # validate records
    for index, record in enumerate(records):
        if record.record_id != index:
            raise ValueError("Record id is invalid or out of order.")
        if record.record_id < record.parent_id:
            raise ValueError("Node parent_id should be smaller than its record_id.")
        if record.record_id != 0 and record.record_id == record.parent_id:
            raise ValueError("Only root should have equal record and parent id.")

    assert records[0].parent_id == records[0].parent_id == 0

    # build tree
    nodes: list[Node] = [Node(record.record_id) for record in records]
    for record in records[1:]:
        if record.record_id == record.parent_id:
            raise ValueError("")

        parent = nodes[record.parent_id]
        parent.children.append(nodes[record.record_id])
    return nodes[0]

