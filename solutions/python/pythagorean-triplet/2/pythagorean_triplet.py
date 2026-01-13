import math
is_even = lambda x: not (x & 1)
divide_by_2 = lambda x: x >> 1
two_to_the_power = lambda n: 2 << (n - 1)

def make_odd(x: int) -> int:
    while is_even(x):
        x = divide_by_2(x)
    return x

def gcd(a:int, b:int) -> int:
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
    global is_even
    results: list[list[int]] = []
    done = False
    for m in range(2, number):
        if done: break
        # m_2 = m * m
        for n in range(1, m):
            if (is_even(m) != is_even(n)) and gcd(m, n) == 1:
                # a + b + c = m*m - n*n + 2mn + m*m - n*n
                #           = 2m(m+n) # primitive
                #
                sum_abc = 2 * m * (m + n)
                k, r = divmod(number, sum_abc)
                if k == 0 and n == 1:
                    done = True
                    break
                elif r == 0:
                    if (found := sorted([(m*m - n*n)*k, 2*m*n*k, (m*m + n*n)*k])) not in results:
                        results.append(found)

    return sorted(results)

def do_triplets_with_sum(number: int):
    print(f"triplets_with_sum({number}) = ", triplets_with_sum(number))

do_triplets_with_sum(12)
do_triplets_with_sum(90) # [9, 40, 41], [15, 36, 39]
do_triplets_with_sum(840) # [40, 399, 401],
                          # [56, 390, 394],
                          # [105, 360, 375],
                          # [120, 350, 370],
                          # [140, 336, 364],
                          # [168, 315, 357],
                          # [210, 280, 350],
                          # [240, 252, 348],
do_triplets_with_sum(30000) # [1200, 14375, 14425],
                            # [1875, 14000, 14125],
                            # [5000, 12000, 13000],
                            # [6000, 11250, 12750],
                            # [7500, 10000, 12500],
