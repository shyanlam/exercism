"""Functions for organizing and calculating student exam scores."""


def round_scores(student_scores: list[float]) -> list[int]:
    """Round all provided student scores.

    :param student_scores: list[float] - float or int of student exam scores.
    :return: list[int] - student scores *rounded* to nearest integer value.
    """

    return [round(score) for score in student_scores]


FAILED_SCORE: int = 40


def count_failed_students(student_scores: list[int]) -> int:
    """Count the number of failing students out of the group provided.

    :param student_scores: list[int] - containing int student scores.
    :return: int - count of student scores at or below 40.
    """
    # failed_count = 0
    # for score in student_scores:
    #     if score <= FAILED_SCORE:
    #         failed_count += 1
    #
    # return failed_count
    return len([failed_score for failed_score in student_scores if failed_score <= FAILED_SCORE])


def above_threshold(student_scores: list[int], threshold: int) -> list[int]:
    """Determine how many of the provided student scores were 'the best' based on the provided threshold.

    :param student_scores: list - of integer scores.
    :param threshold: int - threshold to cross to be the "best" score.
    :return: list - of integer scores that are at or above the "best" threshold.
    """

    return [score for score in student_scores if score >= threshold]


def letter_grades(highest: int) -> list[int]:
    """Create a list of grade thresholds based on the provided highest grade.

    :param highest: int - value of highest exam score.
    :return: list - of lower threshold scores for each D-A letter grade interval.
            For example, where the highest score is 100, and failing is <= 40,
            The result would be [41, 56, 71, 86]:

            41 <= "D" <= 55
            56 <= "C" <= 70
            71 <= "B" <= 85
            86 <= "A" <= 100
    """

    step = (highest - FAILED_SCORE) // 4
    min_score = FAILED_SCORE + 1
    return [score for score in range(min_score, highest, step)]


def student_ranking(student_scores: list[int], student_names: list[str]) -> list[str]:
    """Organize the student's rank, name, and grade information in descending order.

    :param student_scores: list - of scores in descending order.
    :param student_names: list - of string names by exam score in descending order.
    :return: list - of strings in format ["<rank>. <student name>: <score>"].
    """

    # result = []
    # for index, score in enumerate(student_scores):
    #     result.append(f"{index + 1}. {student_names[index]}: {student_scores[index]}")
    # return result
    return [f"{index + 1}. {student_names[index]}: {score}" for index, score in enumerate(student_scores)]


def perfect_score(student_info: list[list[str|int]]) -> list[str|int]:
    """Create a list that contains the name and grade of the first student to make a perfect score on the exam.

    :param student_info: list - of [<student name>, <score>] lists.
    :return: list - first `[<student name>, 100]` or `[]` if no student score of 100 is found.
    """

    for info in student_info:
        if info[1] == 100:
            return info
    return []

