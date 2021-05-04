## 57:69:74:68:20:4C:4F:56:45
##	  _____   _    _   __    __     ____     __    _
##	 / ____| | |  | | |  \  /  |   /    \   |  \  | |
##	 | |___  | |  | | |   \/   |  /   _  \  | . \ | |
##	 \____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
##	 ____| | | \__/ | | |    | | |   __   | | | \ ` |
##	 |_____/ \______/ |_|    |_| |__|  |__| |_|  \__|
## 

from functools      import reduce
from fractions      import Fraction
from statistics     import mean, median, mode
from collections    import deque, OrderedDict, defaultdict
from re             import compile, findall, escape, search, match
from sys            import stdin, stdout, stderr, setrecursionlimit
from math           import pi, sqrt, gcd, ceil, floor, log2, log10, factorial
from random         import choice, getrandbits, randint, random, randrange, shuffle
from itertools      import combinations, combinations_with_replacement, permutations
from collections    import Counter, namedtuple, ChainMap, UserDict, UserList, UserString
from math           import cos, acos, tan, atan, atan2, sin, asin, radians, degrees, hypot
from bisect         import insort, insort_left, insort_right, bisect_left, bisect_right, bisect
from heapq          import heapify, heappop, heappush, heappushpop, heapreplace, merge, nlargest, nsmallest
# from numpy import dot, trace, argmax, argmin, array, cumprod, cumsum, matmul

size = 2 * (10 ** 6 + 1)

# Scope for Global Variables
# 
# 


def preCompute():
    # Precompute some values here
    # 
    pass


def solve():
    # Solve Test Cases here
    # 
    pass


def main():

    testcases = 0

    # testcases += 1

    if testcases == 0:
        testcases = io.Int()

    preCompute()

    for test in range(testcases):

        # io.write("Case #%d: "%(test+1), end="")
        # Use the following lines to write any logic if needed
        # 
        # 
        solve()


class IO:
    def input(self):
        return stdin.readline().strip()
    def String(self):
        return self.input()
    def StringList(self):
        return list(map(str, self.input().split()))
    def Int(self):
        return int(self.input())
    def Float(self):
        return float(self.input())
    def List(self):
        return list(map(int, self.input().split()))
    def Tuple(self):
        return tuple(map(int, self.input().split()))
    def debug(self, *obj, sep = " ", end = "\n"):
        string = sep.join([str(item) for item in obj]) + end
        stderr.write(string)
    def write(self, *obj, sep = " ", end = '\n'):
        string = sep.join([str(item) for item in obj]) + end
        stdout.write(string)
    def put(self, val: str):
        stdout.write(val + '\n')
    def yes(self):
        self.write("yes")
    def Yes(self):
        self.write("Yes")
    def YES(self):
        self.write("YES")
    def no(self):
        self.write("no")
    def No(self):
        self.write("No")
    def NO(self):
        self.write("NO")

io = IO()
shit = 998244353
mod = 10 ** 9 + 7
hell = 10 ** 9 + 9
inf = 10 ** 18
lcm = lambda x, y: ((x * y) // gcd(x, y))
add = lambda x, y, p: (x % p + y % p + p) % p
sub = lambda x, y, p: ((x % p - y % p) + p) % p
mul = lambda x, y, p: ((x % p) * (y % p)) % p
inverse = lambda x, p: (pow(x, p - 2, p))
setBitCount = lambda x: bin(x).count("1")
sumOfDigits = lambda x: sum([int(i) for i in str(x)])

dc = [1, 0, 0, -1, -1, -1, 1, 1]
dr = [0, 1, -1, 0, -1, 1, -1, 1]

def abort(s):
    raise AssertionError(s)

setrecursionlimit(size)

main()