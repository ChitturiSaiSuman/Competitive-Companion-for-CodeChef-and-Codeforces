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
# BIT or Fenwick Tree
class BIT:
    def __init__(self,n,arr):
        self.arr = arr
        self.n = n
        self.bit = [0]*(self.n+1)
        for i in range(n):
            ind = i
            ind += 1
            while ind<=self.n:
                self.bit[ind] += self.arr[i]
                ind += ind&(-ind)
    def update(self,ind,val):
        initial = self.arr[ind]
        self.arr[ind] = val
        val -= initial
        ind += 1
        while ind <= self.n:
            self.bit[ind] += val
            ind += ind&(-ind)
    def find(self,ind):
        s = 0
        ind += 1
        while ind>0:
            s += self.bit[ind]
            ind -= ind&(-ind)
        return s
    def findRange(self,ind1,ind2):
        if ind1>ind2:
            ind1,ind2 = ind2,ind1
        return self.find(ind2)-self.find(ind1-1)
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