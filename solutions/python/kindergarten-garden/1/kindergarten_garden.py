class Garden:
    Plants = {"G": "Grass", "C": "Clover", "R": "Radishes", "V": "Violets"}

    def __init__(self, diagram: str, students: list[str] = None):
        self.diagram = diagram
        if students is None:
            students = ["Alice", "Bob", "Charlie", "David", "Eve", "Fred",
                        "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"]
        self.students = sorted(students)
        student_count = len(self.students)
        self.diagram: list[str] = diagram.split()
        diagram_len = list(map(len, self.diagram))
        if not all(map(lambda x: x == diagram_len[0], diagram_len)):
            raise ValueError("Invalid diagram format")

    def plants(self, student: str) -> list[str]:
        if student not in self.students:
            raise ValueError(f"'{student}' not found")
        index = self.students.index(student) * 2
        return [Garden.Plants.get(self.diagram[0][index], "unknown"),
                Garden.Plants.get(self.diagram[0][index + 1], "unknown"),
                Garden.Plants.get(self.diagram[1][index], "unknown"),
                Garden.Plants.get(self.diagram[1][index + 1], "unknown")]

