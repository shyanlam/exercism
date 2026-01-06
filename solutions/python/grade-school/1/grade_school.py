class School:
    def __init__(self) -> None:
        self._students : list[tuple[str, int, bool]] = []

    def _entry_exists(self, name) -> bool:
        return any(map(lambda x: x == name, [student[0] for student in self._students]))

    def add_student(self, name, grade):
        name = name.title()
        exists = self._entry_exists(name)
        self._students.append((name, grade, not exists))

    def grade_sorted_roster(self) -> dict[int, list[str]]:
        result : dict[int, list[str]] = {}
        for n, g, ok in self._students:
            if ok:
                result.setdefault(g, []).append(n)
        result = dict(sorted(result.items()))
        for _, names in result.items():
            names.sort()
        return result

    def roster(self):
        sorted_roster = self.grade_sorted_roster()
        return [n for names in sorted_roster.values() for n in names]

    def grade(self, grade_number):
        sorted_roster = self.grade_sorted_roster()
        return sorted_roster.get(grade_number, [])

    def added(self) -> list[bool]:
        return [student[2] for student in self._students]

