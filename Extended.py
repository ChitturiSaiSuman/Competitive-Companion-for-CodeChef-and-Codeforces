from sys import stdin,stdout,stderr,setrecursionlimit
from math import pi,sqrt,gcd,ceil,floor,log2,log10,factorial,cos,acos,tan,atan,atan2,sin,asin,radians,degrees,hypot
from bisect import insort,insort_left,insort_right,bisect_left,bisect_right,bisect
from functools import reduce
from itertools import combinations,combinations_with_replacement,permutations
from fractions import Fraction
from random import choice,getrandbits,randint,random,randrange,shuffle
from re import compile,findall,escape,search,match
from statistics import mean,median,mode
from heapq import heapify,heappop,heappush,heappushpop,heapreplace,merge,nlargest,nsmallest
from collections import deque,OrderedDict,defaultdict,Counter,namedtuple,ChainMap,UserDict,UserList,UserString
from numpy import dot,trace,argmax,argmin,array,cumprod,cumsum,matmul

# Next Greater in left using stack
def nextGreaterInLeft(a, n):
    stack = []
    left_index = [-1] * n
    for i in range(n - 1, -1, -1):
        while stack != [] and a[i] > a[stack[-1]]:
            left_index[stack.pop()] = i
        stack.append(i)
    return left_index

# Next Greater in Right using stack
def nextGreaterInRight(a, n):
    stack = []
    right_index = [n] * n
    for i in range(n):
        while stack != [] and a[i] > a[stack[-1]]:
            right_index[stack.pop()] = i
        stack.append(i)
    return right_index

# Next Smaller in Left using stack

def nextSmallerInLeft(a, n):
    stack = []
    left_index = [-1] * n
    for i in range(n - 1, -1, -1):
        while stack != [] and a[i] < a[stack[-1]]:
            left_index[stack.pop()] = i
        stack.append(i)
    return left_index

# Next Smaller in Right using stack

def nextSmallerInRight(a, n):
    stack = []
    right_index = [n] * n
    for i in range(n):
        while stack != [] and a[i] < a[stack[-1]]:
            right_index[stack.pop()] = i
        stack.append(i)
    return right_index

# Sieve for prime generation, sum of primes, count of primes
def sieve(size):
    prime=[0]*size
    prime[2]=1
    for i in range(3,size,2):
        prime[i]=1
    for i in range(3,int(sqrt(size))+1,2):
        if prime[i]==1:
            for j in range(i*i,size,i):
                prime[j]=0
    count=[0]*size
    sum=[0]*size
    for i in range(1,size):
        count[i]=count[i-1]+prime[i]
        sum[i]=sum[i-1]+prime[i]*i
    obj=[(prime[i],count[i],sum[i]) for i in range(size)]
    return obj
# Maximum Subsequence Sum
def max_subsequence_sum(a,n):
    this_sum=0
    max_sum=0
    for i in range(n):
        this_sum+=a[i]
        if this_sum>max:
            max_sum=this_sum
        elif this_sum<0:
            this_sum=0
    return max_sum
# Check whether prime or not
def is_prime(n):
    if n==0 or n==1:
        return False
    elif n==2 or n==3:
        return True
    elif n%2==0 or n%3==0:
        return False
    for i in range(5,int(sqrt(n))+1,6):
        if n%i==0 or n%(i+2)==0:
            return False
    return True
# Binary search
def binary_search(a,lb,ub,key):
    while lb<=ub:
        mid=(lb+ub)//2
        if a[mid]==key:
            return mid
        elif a[mid]<key:
            lb=mid+1
        else:
            ub=mid-1
    return -1
# nCr mod p using fermat's principle
size = 10**6
fact=[1]*size
mod=10**9+7
for i in range(1,size):
    fact[i]=(fact[i-1]*i)%mod
def ncr_mod_p(n,r,p):
    global fact
    if r==0:
        return 1
    return ((fact[n]*pow(fact[r],p-2,p))%p * pow(fact[n-r],p-2,p))%p
# Factorisation in sqrt(n)
def factor(n):
    ans=1
    c=0
    while n%2==0:
        n//=2
        c+=1
    ans*=c+1
    c=0
    while n%3==0:
        n//=3
        c+=1
    ans*=c+1
    for i in range(3,int(sqrt(n))+1,2):
        c=0
        while n%i==0:
            n//=i
            c+=1
        ans*=c+1
        c=0
        while n%(i+2)==0:
            n//=i
            c+=1
        ans*=c+1
    if n>2:
        ans*=2
    return ans
# Sieve in O(n log n) for spf
size=10**5
spf=[i for i in range(size)]
for i in range(2,size,2):
    spf[i]=2
for i in range(3,int(sqrt(size)),2):
    if spf[i]==i:
        for j in range(i*i,size,i):
            if spf[j]==j:
                spf[j]=i
def factorise(n):
    global spf
    ans=1
    while n>1:
        c=0
        k=spf[n]
        while k==spf[n]:
            n//=spf[n]
            c+=1
        ans*=c+1
    return ans
# Euler's Totient Function
phi=[i for i in range(size)]
for i in range(2,size):
    if phi[i]==i:
        for j in range(i,size,i):
            phi[j]-=phi[j]//i
# Nth Fibonacci in O(log(n))
def matmul(a,b,res,moD = 10**30):
    m = len(a)
    n = len(a[0])
    p = len(b[0])
    result = [[0 for i in range(p)] for j in range(m)]
    for i in range(m):
        for j in range(p):
            result[i][j] = 0
            for k in range(n):
                result[i][j] += a[i][k] * b[k][j]
            result[i][j] %= moD
    for i in range(m):
        for j in range(p):
            res[i][j] = result[i][j]
    
def nthFibonacci(n):
    base = [[1,1],[1,0]]
    result = [[1,0],[0,1]]
    while n>0:
        if n&1 == 1:
            matmul(base,result,result,10**9+7)
        matmul(base,base,base,10**9+7)
        n >>= 1
    return result[0][1]
# Graph
class Graph:
    def __init__(self,V,E):
        self.V = V
        self.E = E
        self.graph = defaultdict(list)

    def addEdge(self,a,b):
        self.graph[a].append(b)
        self.graph[b].append(a)
    
    def bfs(self,start):
        visited = [False]*(self.V)
        queue = [start]
        visited[start] = True
        while queue:
            start = queue.pop(0)
            for node in self.graph[start]:
                if not visited[node]:
                    visited[node] = True
                    queue.append(node)
    
    # def bfs(self,start,end):
    #     visited = [False]*(self.V)
    #     queue = [start]
    #     visited[start] = True
    #     while not visited[end] and queue:
    #         start = queue.pop(0)
    #         for node in self.graph[start]:
    #             if not visited[node]:
    #                 visited[node] = True
    #                 queue.append(node)
    
    # def bfs(self,start,end,visited):
    #     queue = [start]
    #     visited[start] = True
    #     while not visited[end] and queue:
    #         start = queue.pop(0)
    #         for node in self.graph[start]:
    #             if not visited[node]:
    #                 visited[node] = True
    #                 queue.append(node)
    
    # def dfs(self,start):
    #     stack = [start]
    #     visited = [False]*(self.V)
    #     while stack:
    #         start = stack.pop()
    #         for node in self.graph[start]:
    #             if not visited[node]:
    #                 visited[node] = True
    #                 stack.append(node)
    
    # def dfs(self,start,end):
    #     stack = [start]
    #     visited = [False]*(self.V)
    #     while not visited[end] and stack:
    #         start = stack.pop()
    #         for node in self.graph[start]:
    #             if not visited[node]:
    #                 visited[node] = True
    #                 stack.append(node)
    
    # def dfs(self,start,end,visited):
    #     stack = [start]
    #     while not visited[end] and stack:
    #         start = stack.pop()
    #         for node in self.graph[start]:
    #             if not visited[node]:
    #                 visited[node] = True
    #                 stack.append(node)
# Disjoint Set Union
class DSU:
    def __init__(self,nax):
        nax += 1
        self.nax = nax
        self.weight = [i for i in range(nax)]
        self.parent = [i for i in range(nax)]
    def root(self,item):
        while self.parent[item]!=item:
            self.parent[item] = self.parent[self.parent[item]]
            item = self.parent[item]
        return item
    def find(self,item1,item2):
        return self.root(item1)==self.root(item2)
    def union(self,item1,item2):
        parent1 = self.root(item1)
        parent2 = self.root(item2)
        if self.weight[parent1]<self.weight[parent2]:
            self.parent[parent1] = self.parent[parent2]
            self.weight[parent2] += self.weight[parent1]
        else:
            self.parent[parent2] = self.parent[parent1]
            self.weight[parent1] += self.weight[parent2]

# Tree
class Tree:
    def __init__(self,V):
        self.V = V
        self.graph = defaultdict(list)
    def addEdge(self,a,b):
        self.graph[a].append(b)
    def bfs(self,start):
        queue = [start]
        while queue:
            start = queue.pop(0)
            for i in self.graph[start]:
                queue.append(i)
    def dfs(self,start):
        for i in self.graph[start]:
            self.dfs(i)
# Sum of paths from root to every node
class Tree:
    def __init__(self,V,values):
        self.V = V
        self.values = values
        self.tree = defaultdict(list)
        self.ans = 0
    def addEdge(self,a,b):
        self.tree[a].append(b)
    def recurse(self,start,initial):
        if self.tree[start] == []:
            initial = initial*10 + self.values[start]
            self.ans += initial
        else:
            initial = initial*10
            initial += self.values[start]
            for i in self.tree[start]:
                self.recurse(i,initial)
    """
    v = int(input())
    values = list(map(int,input().split()))
    g = Tree(v,values)
    for i in range(v-1):
        a,b = map(int,input().split())
        g.addEdge(a,b)
    g.recurse(0,0)
    print(g.ans)
    """

class Trie:
    class Node:
        def __init__(self):
            self.next = [None for i in range(26)]
            self.isTerminalNode = False
            self.samePrefixCount = 0

    def __init__(self):
        self.__root = Trie.Node()
        self.__lcp = []
        self.__count = 0
        self.__lcpLength = 0
        self.__preset = 'a'

    def __len__(self) -> int:
        return self.__count

    def setPreset(self, ch: str) -> None:
        self.__preset = ch

    def insert(self, string: str) -> None:
        self.__insert(self.__root, string, len(string))
        self.__count += 1
        if (self.__count == 1):
            self.__lcp = [i for i in string]
        else:
            i = 0
            length = min(len(self.__lcp), len(string))
            while i < length and self.__lcp[i] == string[i]:
                i += 1
            self.__lcp = self.__lcp[:i]
            self.__lcpLength = i

    def __insert(self, node: Node, string: str, length: int) -> None:
        for i in range(length):
            ch = string[i]
            ind = ord(ch) - ord(self.__preset)
            if (node.next[ind] == None):
                node.next[ind] = Trie.Node()
            node.next[ind].samePrefixCount += 1
            node = node.next[ind]
        node.isTerminalNode = True

    def remove(self, string: str) -> None:
        if not self.contains(string):
            return
        self.__remove(self.__root, string, len(string))

    def __remove(self, node: Node, string: str, length: int) -> None:
        for i in range(length):
            ch = string[i]
            ind = ord(ch) - ord(self.__preset)
            node = node.next[ind]
        node.isTerminalNode = False
        self.__count -= 1

    def contains(self, string: str) -> bool:
        return self.__find(self.__root, string, len(string))

    def __find(self, node: Node, string: str, length: int) -> bool:
        for i in range(length):
            ch = string[i]
            ind = ord(ch) - ord(self.__preset)
            if (node.next[ind] == None):
                return False
            node = node.next[ind]
        return node.isTerminalNode

    def prefixCount(self, prefix: str) -> int:
        return self.__prefixCount(self.__root, prefix, len(prefix))

    def __prefixCount(self, node: Node, prefix: str, length: int) -> int:
        for i in range(length):
            ch = prefix[i]
            ind = ord(ch) - ord(self.__preset)
            if node.next[ind] == None:
                return 0
            node = node.next[ind]
        return node.samePrefixCount

    def longestCommonPrefixLength(self) -> int:
        return self.__lcpLength
    
    def longestCommonPrefix(self) -> str:
        return ''.join(self.__lcp)


class SegmentTree:
    """
    Segment Tree with Get, pointUpdate, RangeUpdate and RangeQuery Operations
    """

    def __init__(self, a: list, key = lambda x, y: (x + y), default = 0) -> None:
        """
        Constructs Segment Tree. Parent Node = key(child1, child2). Extra nodes are set to default.
        """
        self.__array = [i for i in a]
        self.__default = default
        self.__key = key
        self.__tree = self.__build()
        self.__length = len(self.__tree) // 2
        self.__carry = [default for i in range(self.__length * 2)]
        del self.__array

    def __build(self) -> list:
        """
        Utility function to build Segment Tree
        """
        n = len(self.__array)
        while (n & (n - 1)) != 0:
            self.__array.append(self.__default)
            n += 1
        tree = [self.__default for i in range(2 * n)]
        for i in range(n):
            tree[n + i] = self.__array[i]
        for i in range(n - 1, 0, -1):
            tree[i] = self.__key(tree[2 * i], tree[2 * i + 1])
        return tree

    def __str__(self) -> str:
        return str(self.__tree)

    def get(self, index: int) -> int:
        """
        Returns the value at a[index]
        """
        return self.rangeQuery(index, index)

    def pointUpdate(self, index: int, value: int) -> None:
        """
        Modifies a Singly Node and its Ancestors, Sets a[index] to value
        """
        self.__update(1, 0, self.__length - 1, index, value)

    def __update(self, node: int, node_lb: int, node_ub: int, index: int, value: int) -> int:
        if (index < node_lb or node_ub < index):
            return self.__tree[node]
        elif (node_lb == node_ub and node_ub == index):
            self.__tree[node] = value
        else:
            leftReturned = self.__update(2 * node, node_lb, (node_lb + node_ub) // 2, index, value)
            rightReturned = self.__update(2 * node + 1, (node_lb + node_ub) // 2 + 1, node_ub, index, value)
            self.__tree[node] = self.__key(leftReturned, rightReturned)
        return self.__tree[node]

    def rangeUpdate(self, range_lb: int, range_ub: int, value: int) -> None:
        """
        Modifies several Nodes lying in the Range by Performing key operation
        """
        self.__rangeUpdate(1, 0, self.__length - 1, range_lb, range_ub, value)

    def __rangeUpdate(self, node: int, node_lb: int, node_ub: int, range_lb: int, range_ub: int, value: int) -> int:
        if range_lb <= node_lb and node_ub <= range_ub:
            self.__carry[node] = self.__key(self.__carry[node], value)
        elif node_ub < range_lb or range_ub < node_lb:
            return self.__carry[node]
        else:
            self.__rangeUpdate(2 * node, node_lb, (node_lb + node_ub) // 2, range_lb, range_ub, value)
            self.__rangeUpdate(2 * node + 1, (node_lb + node_ub) // 2 + 1, node_ub, range_lb, range_ub, value)
        return self.__carry[node]

    def rangeQuery(self, query_lb: int, qeury_ub: int) -> int:
        """
        Returns the Result of Key Function over the Range
        """
        return self.__query(1, 0, self.__length - 1, query_lb, qeury_ub)

    def __query(self, node: int, node_lb: int, node_ub: int, query_lb: int, query_ub: int) -> int:
        if query_lb <= node_lb and node_ub <= query_ub:
            return self.__key(self.__tree[node], self.__carry[node])
        elif query_ub < node_lb or node_ub < query_lb:
            return self.__default
        else:
            left_returned = self.__query(2 * node, node_lb, (node_lb + node_ub) // 2, query_lb, query_ub)
            right_returned = self.__query(2 * node + 1, (node_lb + node_ub) // 2 + 1, node_ub, query_lb, query_ub)
            return self.__key(self.__key(left_returned, right_returned), self.__carry[node])