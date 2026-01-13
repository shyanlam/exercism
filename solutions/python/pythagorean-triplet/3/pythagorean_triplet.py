import math
is_even = lambda x: not (x & 1)
divide_by_2 = lambda x: x >> 1
two_to_the_power = lambda n: 2 << (n - 1)

def make_odd(x: int) -> int:
    while is_even(x):
        x = divide_by_2(x)
    return x

def gcd(a:int, b:int) -> int:
    # https://en.wikipedia.org/wiki/Greatest_common_divisor
    global is_even, divide_by_2, two_to_the_power
    d = 0
    while is_even(a) and is_even(b):
        a, b = divide_by_2(a), divide_by_2(b)
        d += 1

    a = make_odd(a)
    b = make_odd(b)

    while a != b:
        if a > b:
            a = make_odd(a - b)
        elif a < b:
            b = make_odd(b - a)
    return 2**d * a

def triplets_with_sum(number: int) -> list[list[int]]:
    # https: // en.wikipedia.org / wiki / Pythagorean_triple
    global is_even
    results: list[list[int]] = []
    done = False
    for m in range(2, number):
        if done: break
        m_2 = m * m
        for n in range(1, m):
            if (is_even(m) != is_even(n)) and gcd(m, n) == 1:
                n_2 = n * n
                a = m_2 - n_2
                b = 2 * m * n
                c = m_2 + n_2
                k, r = divmod(number, a + b + c)
                if k == 0 and n == 1:
                    done = True
                    break
                elif r == 0:
                    if (found := sorted([a*k, b*k, c*k])) not in results:
                        results.append(found)

    return sorted(results)
