## 57:69:74:68:20:4C:4F:56:45

# from functools      import reduce
# from fractions      import Fraction
# from statistics     import mean, median, mode
# from re             import compile, findall, escape, search, match
# from random         import choice, getrandbits, random, randrange, shuffle
# from itertools      import combinations, combinations_with_replacement, permutations
# from collections    import OrderedDict, namedtuple, ChainMap, UserDict, UserList, UserString
# from math           import cos, acos, tan, atan, atan2, sin, asin, radians, degrees, hypot
# from bisect         import insort, insort_left, insort_right, bisect_left, bisect_right, bisect
# from heapq          import heapify, heappop, heappush, heappushpop, heapreplace, merge, nlargest, nsmallest
# from numpy import dot, trace, argmax, argmin, array, cumprod, cumsum, matmul
from random         import randint
from collections    import deque, defaultdict, Counter
from sys            import stdin, stdout, stderr, setrecursionlimit
from math           import pi, sqrt, gcd, ceil, floor, log2, log10, factorial

size = 2 * (10 ** 6 + 1)

def preCompute():
    return


def solve():
    return


def main():
    testcases = 0
    # testcases += 1
    if testcases == 0:
        testcases = io.Int()
    preCompute()
    for test in range(testcases):
        # io.write("Case #%d: "%(test+1), end="")
        solve()


class IO:
    def String(self):
        return stdin.readline().strip()
    def Int(self):
        return int(self.String())
    def Float(self):
        return float(self.String())
    def List(self):
        return list(map(int, self.String().split()))
    def Tuple(self):
        return tuple(map(int, self.String().split()))
    def debug(self, *obj, sep = ' ', end = '\n'):
        string = sep.join([str(item) for item in obj]) + end
        stderr.write(string)
    def write(self, *obj, sep = ' ', end = '\n'):
        string = sep.join([str(item) for item in obj]) + end
        stdout.write(string)

io              = IO()
shit            = 998244353
mod             = 10 ** 9 + 7
hell            = 10 ** 9 + 9
inf             = 10 ** 18 + 3
lcm             = lambda x, y: ((x * y) // gcd(x, y))
add             = lambda x, y, p: (x % p + y % p + p) % p
sub             = lambda x, y, p: ((x % p - y % p) + p) % p
mul             = lambda x, y, p: ((x % p) * (y % p)) % p
inverse         = lambda x, p: (pow(x, p - 2, p))
setBitCount     = lambda x: bin(x).count("1")
sumOfDigits     = lambda x: sum([int(i) for i in str(x)])

dc = [1, 0, 0, -1, -1, -1, 1, 1]
dr = [0, 1, -1, 0, -1, 1, -1, 1]

def abort(s):
    raise AssertionError(s)

setrecursionlimit(size)

main()