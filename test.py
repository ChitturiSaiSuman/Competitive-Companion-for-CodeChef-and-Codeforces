
#  _____   _    _   __    __     ____     __    _
# / ____| | |  | | |  \  /  |   /    \   |  \  | |
# | |___  | |  | | |   \/   |  /   _  \  | . \ | |
# \____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
# ____| | | \__/ | | |    | | |   __   | | | \ ` |
# |_____/ \______/ |_|    |_| |__|  |__| |_|  \__|
# 

from sys import stdin, stdout, stderr, setrecursionlimit
from math import pi, sqrt, gcd, ceil, floor, log2, log10, factorial
from math import cos, acos, tan, atan, atan2, sin, asin, radians, degrees, hypot
from bisect import insort, insort_left, insort_right, bisect_left, bisect_right, bisect
from functools import reduce
from itertools import combinations, combinations_with_replacement, permutations
from fractions import Fraction
from random import choice, getrandbits, randint, random, randrange, shuffle
from re import compile, findall, escape, search, match
from statistics import mean, median, mode
from heapq import heapify, heappop, heappush, heappushpop, heapreplace, merge, nlargest, nsmallest
from collections import deque, OrderedDict, defaultdict
from collections import Counter, namedtuple, ChainMap, UserDict, UserList, UserString
# from numpy import dot, trace, argmax, argmin, array, cumprod, cumsum, matmul

size = 2 * (10 ** 6 + 1)

setrecursionlimit(size)

def abort(s):
    raise AssertionError(s)

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
        testcases = io.nextInt()

    preCompute()

    for test in range(testcases):

        # io.write("Case #%d: "%(test+1), end="")
        # Write any logic here, if needed
        # 
        solve()


class IO:
    def next(self):
        return stdin.readline().strip()
    def nextLine(self):
        return self.next()
    def String(self):
        return self.next()
    def nextStrings(self):
        return list(map(str, self.next().split()))
    def nextInt(self):
        return int(self.next())
    def Int(self):
        return self.nextInt()
    def nextFloat(self):
        return float(self.next())
    def Float(self):
        return self.nextFloat()
    def nextList(self):
        return list(map(int, self.next().split()))
    def List(self):
        return self.nextList()
    def nextTuple(self):
        return tuple(map(int, self.next().split()))
    def Tuple(self):
        return self.nextTuple()
    def debug(self, *obj, sep = " ", end = "\n"):
        string = sep.join([str(item) for item in obj])+end
        stderr.write(string)
    def print(self, *obj, sep = " ", end = '\n', flush = False):
        string = sep.join([str(item) for item in obj])+end
        stdout.write(string)
        if flush:
            stdout.flush()
    def write(self, *obj, sep = " ", end = "\n", flush = False):
        self.print(*obj, sep = sep, end = end, flush = flush)
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
mod = 10**9 + 7
hell = 10**9 + 9
inf = 10**18
lcm = lambda x, y: ((x * y) // gcd(x, y))
add = lambda x, y, p: (x % p + y % p) % p
sub = lambda x, y, p: ((x % p - y % p) + p) % p
mul = lambda x, y, p: ((x % p) * (y % p)) % p
inverse = lambda x, p: (pow(x, p - 2, p))
setBitCount = lambda x: bin(x).count("1")
sumOfDigits = lambda x: sum([int(i) for i in str(x)])

main()