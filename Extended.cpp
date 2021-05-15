// 57:69:74:68:20:4C:4F:56:45
//	  _____   _    _   __    __     ____     __    _
//	 / ____| | |  | | |  \  /  |   /    \   |  \  | |
//	 | |___  | |  | | |   \/   |  /   _  \  | . \ | |
//	 \____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
//	 ____| | | \__/ | | |    | | |   __   | | | \ ` |
//	 |_____/ \______/ |_|    |_| |__|  |__| |_|  \__|
//

#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

#define FOR(x, N)					for(int x = 0; x < N; x++)
#define inverse(a, p)				power(a, p - 2, p)
#define getName(var)				#var
#define debug(var)					cerr << getName(var) << " = " << var << "\n"
#define abort						assert(false)
#define read(arr, nax)				FOR(IT, nax)	{cin >> arr[IT];}
#define write(arr, nax)				FOR(IT, nax)	{cout << arr[IT] << " ";}
#define fill(arr, nax, value)		FOR(IT, nax)	{arr[IT] = value;}
#define reverse(arr, nax)			FOR(x, nax/2)	{arr[x] = arr[nax - x - 1];}
#define SORT123(v)					sort(v.begin(), v.end())
#define SORT321(v)					sort(v.begin(), v.end(), greater<int>())

typedef unsigned long long int ull;
typedef long long int ll;

const int dc[] = {1, 0, 0, -1, -1, -1, 1, 1};
const int dr[] = {0, 1, -1, 0, -1, 1, -1, 1};

const ll shit	= ((ll)(998244353));	// 998,244,353
const ll mod	= ((ll)(1e9+7));		// 10**9 + 7
const ll hell	= ((ll)(1e9+9));		// 10**9 + 9
const ll inf	= ((ll)(1e18 + 3));		// 10 ** 18 + 3

const char yes[]	= "yes";
const char Yes[]	= "Yes";
const char YES[]	= "YES";
const char no[]		= "no";
const char No[]		= "No";
const char NO[]		= "NO";

static inline ll	gcd(ll a, ll b)					{for(ll rem;b>0;rem=a%b,a=b,b=rem);return a;}
static inline ll	lcm(ll a, ll b)					{return (a*b)/(gcd(a,b));}
static inline ll	max(ll a, ll b)					{return (a>b?a:b);}
static inline ll	min(ll a, ll b)					{return (a<b?a:b);}
static inline ll	mul(ll a, ll b, ll p)			{return ((a%p*b%p)%p+p)%p;}
static inline ll	add(ll a, ll b, ll p)			{return ((a%p+b%p)%p+p)%p;}
static inline ll	sub(ll a, ll b, ll p)			{return ((a%p-b%p)+p)%p;}
static inline ll	sum(ll a, ll b)					{return a + b;}
static inline ll	AND(ll a, ll b)					{return a & b;}
static inline ll	XOR(ll a, ll b)					{return a ^ b;}
static inline ll	OR(ll a, ll b)					{return a | b;}

ll power(ll x, ll y, ll p) {
	ll result = 1;
	for(; y > 0; y >>= 1, x = mul(x, x, p)) {
		if(y & 1)
			result = mul(result, x, p);
	}
	return result;
}

bool isPrime(ll n) {
	if(n == 0 or n == 1)
		return false;
	else if(n == 2 or n == 3)
		return true;
	else if(n % 2 == 0 or n % 3 == 0)
		return false;
	const int root = sqrt(n);
	for(int i = 5; i <= root; i += 6)
		if(n % i == 0 or n % (i + 2) == 0)
			return false;
	return true;
}

// Fraction template for CPP

class Fraction {
	public:
	ll num = 0, den = 1;
	ll gcd(ll a, ll b) {for(ll rem;b>0;rem=a%b,a=b,b=rem); return a;}
	ll lcm(ll a, ll b) {return (a * b) / gcd(a, b);}
	Fraction() {
		num = 0;
		den = 1;
	};
	Fraction(ll n) {
		num = n;
		den = 1;
	};
	Fraction(ll n, ll d) {
		if(d == 0) {
			throw invalid_argument("Non-Zero denominator is expected");
		}
		num = n;
		den = d;
		ll g = gcd(num, den);
		num /= g;
		den /= g;
	};
	Fraction operator + (Fraction const &frac) {
		ll l = lcm(den, frac.den);
		ll a = num * (l / den);
		ll b = frac.num * (l / frac.den);
		return Fraction(a+b, l);
	}
	Fraction operator - (Fraction const &frac) {
		ll l = lcm(den, frac.den);
		ll a = num * (l / den);
		ll b = frac.num * (l / frac.den);
		return Fraction(a - b, l);
	}
	Fraction operator * (Fraction const &frac) {
		return Fraction(num * frac.num, den * frac.den);
	}
	Fraction operator / (Fraction const &frac) {
		return Fraction(num * frac.den, den * frac.num);
	}
	operator string() const {
		if(den == 1)
			return to_string(num);
		return to_string(num) + "/" + to_string(den);
	}
};

ostream& operator << (ostream& out, const Fraction &f) {
	if(f.den == 1)
		return out << to_string(f.num);
	return out << to_string(f.num) + "/" + to_string(f.den);
}

// End of Fraction template for CPP

// Sieve for Prime Generation

vector<bool> sieve(int nax) {
    vector<bool> prime(nax, false);
    prime[2] = true;
    for(int i = 3; i < nax; i += 2) {
        prime[i] = true;
    }

    for(int i = 3; i * i < nax; i += 2) {
        if(prime[i]) {
            for(int j = i * i; j < nax; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

// End of Sieve for Prime Generation


class Graph {
    public:
    int V = 0;
    int E = 0;
    vector<vector<int>> graph;
    Graph(int v, int e) {
        V = v + 1;
        E = e;
        FOR(i, V) {
            graph.push_back(vector<int>());
        }
    }

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        // graph[b].push_back(a);
    }

    bool bfs(int start, int end) {
        vector<bool> visited(V, false);
        visited[true] = true;
        queue<int> q;
        q.push(start);
        while (!q.empty() && !visited[end]) {
            start = q.front();
            q.pop();
            for(int i: graph[start]) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return visited[end];
    }

    void recurse(int start, vector<bool> & visited, int end) {
        if(start == end) {
            visited[start] = true;
            return;
        }
        visited[start] = true;
        for(int i: graph[start]) {
            if(!visited[i]) {
                recurse(i, visited, end);
            }
        }
    }

    bool dfs(int start, int end) {
        vector<bool> visited(V, false);
        recurse(start, visited, end);
        return visited[end];
    }
};


vector<int> nextGreaterInRight(vector<int> a, int n) {
	vector<int> right_index(n, n);
	stack<int> st;
	for(int i = 0; i < n; i++) {
		while(!st.empty() && a[i] > a[st.top()]) {
			int r = st.top();
			st.pop();
			right_index[r] = i;
		}
		st.push(i);
	}
	return right_index;
}

vector<int> nextGreaterInLeft(vector<int> a, int n) {
	vector<int> left_index(n, -1);
	stack<int> st;
	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && a[i] > a[st.top()]) {
			int r = st.top();
			st.pop();
			left_index[r] = i;
		}
		st.push(i);
	}
	return left_index;
}

vector<int> nextSmallerInRight(vector<int> a, int n) {
	vector<int> right_index(n, n);
	stack<int> st;
	for(int i = 0; i < n; i++) {
		while(!st.empty() && a[i] < a[st.top()]) {
			int r = st.top();
			st.pop();
			right_index[r] = i;
		}
		st.push(i);
	}
	return right_index;
}

vector<int> nextSmallerInLeft(vector<int> a, int n) {
	vector<int> left_index(n, -1);
	stack<int> st;
	for(int i = n - 1; i >= 0; i--) {
		while (!st.empty() && a[i] < a[st.top()]) {
			int r = st.top();
			st.pop();
			left_index[r] = i;
		}
		st.push(i);
	}
	return left_index;
}

class SegmentTree {

    /**
     * Segment Tree with Get, pointUpdate, RangeUpdate and RangeQuery Operations
     */ 

    private:
    vector<ll> tree;
    vector<ll> carry;
    ll default_value;
    int length;
    function<long(long, long)> key;

    public:
    SegmentTree(vector<int> arr, int def_value = 0, ll fun(ll, ll) = sum) {
        /**
         * Constructor with optional Arguments: def_value, fun
         * Extra nodes are filled with def_value
         * fun builds up relation between in parent and children
         */  
        default_value = def_value;
        key = fun;
        int n = arr.size();
        while ((n & (n - 1)) != 0) {
            n++;
            arr.push_back(default_value);
        }
        tree.resize(2 * n, default_value);
        for(int i = 0; i < n; i++) {
            tree[n + i] = arr[i];
        }
        for(int i = n - 1; i > 0; i--) {
            tree[i] = key(tree[2 * i], tree[2 * i + 1]);
        }
        length = ((int)(tree.size())) / 2;
        carry.resize(2 * n, default_value);
    }

    int size() {
        /**
         * Returns length of Segment Tree
         */ 
        return length * 2;
    }

    ll get(int index) {
        /**
         * Returns the value at a[index]
         */ 
        return rangeQuery(index, index);
    }

    void pointUpdate(int index, long value) {
        /**
         * Updates a single node and its Ancestors - Sets the node to this value
         */
        pointUpdate(1, 0, length - 1, index, value);
    }

    private:
    long pointUpdate(int node, int node_lb, int node_ub, int index, long value) {
        if(index < node_lb || node_ub < index) {
            return tree[node];
        }
        else if(node_lb == node_ub && node_ub == index) {
            tree[node] = value;
        }
        else {
            long leftReturned = pointUpdate(2 * node, node_lb, (node_lb + node_ub) / 2, index, value);
            long rightReturned = pointUpdate(2 * node + 1, (node_lb + node_ub) / 2 + 1, node_ub, index, value);
            tree[node] = key(leftReturned, rightReturned);
        }
        return tree[node];
    }

    public:
    void rangeUpdate(int range_lb, int range_ub, long value) {
        /**
         * Updates Several Nodes using the results of Key Function over Children
         */
        rangeUpdate(1, 0, length - 1, range_lb, range_ub, value);
    }

    private:
    long rangeUpdate(int node, int node_lb, int node_ub, int range_lb, int range_ub, long value) {
        if(range_lb <= node_lb && node_ub <= range_ub) {
            carry[node] = key(carry[node], value);
        }
        else if(node_ub < range_lb || range_ub < node_lb) {
            return carry[node];
        }
        else {
            rangeUpdate(2 * node, node_lb, (node_lb + node_ub) / 2, range_lb, range_ub, value);
            rangeUpdate(2 * node + 1, (node_lb + node_ub) / 2 + 1, node_ub, range_lb, range_ub, value);
        }
        return carry[node];
    }

    public:
    long rangeQuery(int query_lb, int query_ub) {
        /**
         * Returns the result of Key Function over the range
         */
        return rangeQuery(1, 0, length - 1, query_lb, query_ub);
    }
    
    private:
    long rangeQuery(int node, int node_lb, int node_ub, int query_lb, int query_ub) {
        if(query_lb <= node_lb && node_ub <= query_ub) {
            return key(tree[node], carry[node]);
        }
        else if(query_ub < node_lb || node_ub < query_lb) {
            return default_value;
        }
        else {
            long leftReturned = rangeQuery(2 * node, node_lb, (node_lb + node_ub) / 2, query_lb, query_ub);
            long rightReturned = rangeQuery(2 * node + 1, (node_lb + node_ub) / 2 + 1, node_ub, query_lb, query_ub);
            return key(carry[node], key(leftReturned, rightReturned));
        }
    }
};