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
#include <stack>
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

#define nax 2000003 // 2e6 + 3

// Fraction template for CPP

class Fraction {
	public:
	ll num = 0, den = 1;
	ll gcd(ll a, ll b) {if(a < 0) a = -a; if(b < 0) b = -b; for(ll rem;b>0;rem=a%b,a=b,b=rem); return a;}
	ll lcm(ll a, ll b) {if(a < 0) a = -a; if(b < 0) b = -b; return (a * b) / gcd(a, b);}
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
    Fraction(Fraction &f) {
        num = f.num;
        den = f.den;
    }
    Fraction(string s) {
        int pos = s.find('/');
        if(pos != string::npos) {
            num = stoll(s.substr(0, pos));
            den = stoll(s.substr(pos + 1, s.size()));
            ll g = gcd(num, den);
            num /= g;
            den /= g;
        }
        else {
            num = stoll(s);
            den = 1;
        }
    };
    operator string() const {
		if(den == 1)
			return to_string(num);
		return to_string(num) + "/" + to_string(den);
	}
	Fraction operator + (const Fraction &frac) {
		ll l = lcm(den, frac.den);
		ll a = num * (l / den);
		ll b = frac.num * (l / frac.den);
		return Fraction(a+b, l);
	}
    void operator += (const Fraction &frac) {
        Fraction f = Fraction(num, den);
        f = (f + frac);
        num = f.num;
        den = f.den;
    }
	Fraction operator - (const Fraction &frac) {
		ll l = lcm(den, frac.den);
		ll a = num * (l / den);
		ll b = frac.num * (l / frac.den);
		return Fraction(a - b, l);
	}
    void operator -= (const Fraction &frac) {
        Fraction f = Fraction(num, den);
        f = (f - frac);
        num = f.num;
        den = f.den;
    }
	Fraction operator * (const Fraction &frac) {
		return Fraction(num * frac.num, den * frac.den);
	}
    void operator *= (const Fraction &frac) {
        Fraction f = Fraction(num, den);
        f = (f * frac);
        num = f.num;
        den = f.den;
    }
	Fraction operator / (const Fraction &frac) {
		return Fraction(num * frac.den, den * frac.num);
	}
    void operator /= (const Fraction &frac) {
        Fraction f = Fraction(num, den);
        f = (f / frac);
        num = f.num;
        den = f.den;
    }
    bool operator == (const Fraction &frac) {
        return (frac.num == num && frac.den == den);
    }
    bool operator != (const Fraction &frac) {
        return !(frac.num == num && frac.den == den);
    }
    bool operator < (const Fraction &frac) {
        ll base = lcm(den, frac.den);
        return (base/den * num) < (base/frac.den * frac.num);
    }
    bool operator <= (const Fraction &frac) {
        ll base = lcm(den, frac.den);
        return (base/den * num) <= (base/frac.den * frac.num);
    }
    bool operator > (const Fraction &frac) {
        ll base = lcm(den, frac.den);
        return (base/den * num) > (base/frac.den * frac.num);
    }
    bool operator >= (const Fraction &frac) {
        ll base = lcm(den, frac.den);
        return (base/den * num) >= (base/frac.den * frac.num);
    }
};

ostream& operator << (ostream& out, const Fraction &f) {
	if(f.den == 1)
		return out << to_string(f.num);
	return out << to_string(f.num) + "/" + to_string(f.den);
}

// End of Fraction template for CPP


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

// NextGreater, NextSmaller at Right, Left

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

// ******************************************

// Generic Segment Tree

class SegmentTree {

    /**
     * Segment Tree with Get, pointUpdate, RangeUpdate and RangeQuery Operations
     */ 

    private:
    vector<ll> tree;
    vector<ll> carry;
    ll default_value;
    int length;
    function<ll(ll, ll)> key;

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

    void pointUpdate(int index, ll value) {
        /**
         * Updates a single node and its Ancestors - Sets the node to this value
         */
        pointUpdate(1, 0, length - 1, index, value);
    }

    private:
    ll pointUpdate(int node, int node_lb, int node_ub, int index, ll value) {
        if(index < node_lb || node_ub < index) {
            return tree[node];
        }
        else if(node_lb == node_ub && node_ub == index) {
            tree[node] = value;
        }
        else {
            ll leftReturned = pointUpdate(2 * node, node_lb, (node_lb + node_ub) / 2, index, value);
            ll rightReturned = pointUpdate(2 * node + 1, (node_lb + node_ub) / 2 + 1, node_ub, index, value);
            tree[node] = key(leftReturned, rightReturned);
        }
        return tree[node];
    }

    public:
    void rangeUpdate(int range_lb, int range_ub, ll value) {
        /**
         * Updates Several Nodes using the results of Key Function over Children
         */
        rangeUpdate(1, 0, length - 1, range_lb, range_ub, value);
    }

    private:
    ll rangeUpdate(int node, int node_lb, int node_ub, int range_lb, int range_ub, ll value) {
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
    ll rangeQuery(int query_lb, int query_ub) {
        /**
         * Returns the result of Key Function over the range
         */
        return rangeQuery(1, 0, length - 1, query_lb, query_ub);
    }
    
    private:
    ll rangeQuery(int node, int node_lb, int node_ub, int query_lb, int query_ub) {
        if(query_lb <= node_lb && node_ub <= query_ub) {
            return key(tree[node], carry[node]);
        }
        else if(query_ub < node_lb || node_ub < query_lb) {
            return default_value;
        }
        else {
            ll leftReturned = rangeQuery(2 * node, node_lb, (node_lb + node_ub) / 2, query_lb, query_ub);
            ll rightReturned = rangeQuery(2 * node + 1, (node_lb + node_ub) / 2 + 1, node_ub, query_lb, query_ub);
            return key(carry[node], key(leftReturned, rightReturned));
        }
    }
};
// End of Segment Tree

// Trie for strings

class Trie {

    private:
    class Node {

        public:
        Node *next[26];
        bool isTerminalNode;
        int samePrefixCount;

        Node() {
            isTerminalNode = false;
            samePrefixCount = 0;
        }
    };

    Node *root;
    string lcp;
    int count;
    int lcpLength;
    char preset;

    public:
    Trie() {
        root = new Node();
        count = 0;
        lcpLength = 0;
        preset = 'a';
    }

    int size() {
        return count;
    }

    void setPreset(char ch) {
        preset = ch;
    }

    void insert(string str) {
        if(contains(str)) {
            return;
        }
        _insert(root, str, str.size());
        count++;
        if(count == 1) {
            lcp.append(str);
        }
        else {
            int i = 0;
            const int length = min(lcp.size(), str.size());
            for(; i < length && lcp[i] == str[i]; i++);
            lcp.resize(i);
            lcpLength = i;
        }
    }

    int longestCommonPrefixLength() {
        return lcpLength;
    }

    string longestCommonPrefix() {
        return lcp;
    }

    void remove(string str) {
        if(!contains(str)) {
            return;
        }
        _remove(root, str, str.size());
    }

    bool contains(string str) {
        return _find(root, str, str.size());
    }

    int prefixCount(string prefix) {
        return _prefixCount(root, prefix, prefix.size());
    }

    private:
    void _insert(Node *node, string str, const int length) {
        for(int i = 0; i < length; i++) {
            int ind = str[i] - preset;
            if(node->next[ind] == nullptr) {
                node->next[ind] = new Node();
            }
            (node->next[ind])->samePrefixCount++;
            node = node->next[ind];
        }
        node->isTerminalNode = true;
    }

    void _remove(Node *node, string str, const int length) {
        for(int i = 0; i < length; i++) {
            int ind = str[i] - preset;
            node = node->next[ind];
        }
        node->isTerminalNode = false;
        count--;
    }

    bool _find(Node *node, string str, const int length) {
        for(int i = 0; i < length; i++) {
            int ind = str[i] - preset;
            if(node->next[ind] == nullptr) {
                return false;
            }
            node = node->next[ind];
        }
        return node->isTerminalNode;
    }

    int _prefixCount(Node *node, string prefix, const int length) {
        for(int i = 0; i < length; i++) {
            int ind = prefix[i] - preset;
            if(node->next[ind] == nullptr) {
                return 0;
            }
            node = node->next[ind];
        }
        return node->samePrefixCount;
    }
};
// End of Trie


// Utilities for Permutations and Combinations

vector<ll> fact;
vector<ll> invFact;
vector<ll> inv;

void prepare(int N, ll p) {
    fact.resize(N);
    invFact.resize(N);
    inv.resize(N);
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i, p);
    }
    invFact[N - 1] = power(fact[N - 1], p - 2, p);
    for(int i = N - 2; i >= 0; i--) {
        invFact[i] = ((i + 1) * invFact[i + 1]) % p;
    }
    inv[0] = 0;
    for(int i = 1; i < N; i++) {
        inv[i] = (fact[i - 1] * invFact[i]) % p;
    }
}

ll nCr_mod_p(int n, int r, ll p) {
    return mul(fact[n], mul(invFact[r], invFact[n - r], p), p);
}

ll nthCatalan_mod_p(int n, ll p) {
    return mul(nCr_mod_p(2 * n, n, p), inv[n + 1], p);
}
// End of Template for P & C

// Bisect Functions

template <typename T>
int binarySearch(vector<T> &a, T key) {
    int lb = 0;
    int ub = a.size() - 1;
    while(lb <= ub) {
        int mid = (lb + ub) / 2;
        if(a[mid] == key) {
            return mid;
        }
        else if(a[mid] < key) {
            lb = mid + 1;
        }
        else {
            ub = mid - 1;
        }
    }
    return -1;
}

template <typename T>
int bisect_left(vector<T> &a, T key) {
    int ind = binarySearch(a, key);
    double k = key;
    if(ind != -1) {
        k = ((double)(key)) - 0.5;
    }
    int lb = 0, ub = a.size() - 1;
    while(lb <= ub) {
        int mid = (lb + ub) / 2;
        if(a[mid] < k) {
            lb = mid + 1;
        }
        else {
            ub = mid - 1;
        }
    }
    return lb;
}

template <typename T>
int bisect_right(vector<T> &a, T key) {
    int ind = binarySearch(a, key);
    double k = key;
    if(ind != -1) {
        k = ((double)(key)) + 0.5;
    }
    int lb = 0, ub = a.size() - 1;
    while(lb <= ub) {
        int mid = (lb + ub) / 2;
        if(a[mid] < k) {
            lb = mid + 1;
        }
        else {
            ub = mid - 1;
        }
    }
    return lb;
}
// End of Bisect Functions

// Utility functions


// Count Inversions using merge sort
ll merge(vector<int> &a, int lb, int ub) {
    vector<int> temp(ub + 1 - lb);
    ll ans = 0;
    int i = lb;
    int mid = (lb + ub) / 2;
    int j = mid + 1;
    int ind = 0;
    while(i <= mid && j <= ub) {
        if(a[i] <= a[j]) {
            temp[ind++] = a[i++];
        }
        else {
            ans = ans + mid + 1 - i;
            temp[ind++] = a[j++];
        }
    }
    while(i <= mid) {
        temp[ind++] = a[i++];
    }
    while(j <= ub) {
        temp[ind++] = a[j++];
    }
    for(i = lb, ind = 0; i <= ub; i++, ind++) {
        a[i] = temp[ind];
    }
    return ans;
}

ll mergeSort (vector<int> &a, int lb, int ub) {
    ll ans = 0;
    if(lb < ub) {
        int mid = (lb + ub) / 2;
        ans += mergeSort(a, lb, mid);
        ans += mergeSort(a, mid + 1, ub);
        ans += merge(a, lb, ub);
    }
    return ans;
}

ll countInversions(vector<int> a) {
    return mergeSort(a, 0, a.size() - 1);
}
// End of Count Inversions

// Longest common subsequence
int lcs(vector<int> &a, vector<int> &b) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp (m + 1, vector<int>(n + 1));
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int lcs(string &a, string &b) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp (m + 1, vector<int>(n + 1));
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
// End of longest common subsequence

// Matrix Multiplication
void matmul(vector<vector<ll>> &a, vector<vector<ll>> &b, vector<vector<ll>> &res, ll p) {
    int M = a.size();
    int N = a[0].size();
    int P = b[0].size();
    vector<vector<ll>> result(M, vector<ll>(P));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < P; j++) {
            result[i][j] = 0;
            for(int k = 0; k < N; k++) {
                result[i][j] = add(result[i][j], mul(a[i][k], b[k][j], p), p);
            }
        }
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < P; j++) {
            res[i][j] = result[i][j];
        }
    }
}

// Matrix Multiplication for Fraction

void matmul(vector<vector<Fraction>> &a, vector<vector<Fraction>> &b, vector<vector<Fraction>> &res) {
    int M = a.size();
    int N = a[0].size();
    int P = b[0].size();
    vector<vector<Fraction>> result(M, vector<Fraction>(P));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < P; j++) {
            result[i][j] = 0;
            for(int k = 0; k < N; k++) {
                result[i][j] = result[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < P; j++) {
            res[i][j] = result[i][j];
        }
    }
}

// Matrix Exponentiation
vector<vector<ll>> power(vector<vector<ll>> &a, ll y, ll p) {
    vector<vector<ll>> result(a.size(), vector<ll>(a.size(), 0));
    for(int i = 0; i < a.size(); i++) {
        result[i][i] = 1;
    }
    for(; y > 0; y >>= 1, matmul(a, a, a, p)) {
        if((y & 1) == 1) {
            matmul(a, result, result, p);
        }
    }
    return result;
}

// Fraction Matrix Exponentiation
vector<vector<Fraction>> power(vector<vector<Fraction>> &a, ll y) {
    vector<vector<Fraction>> result(a.size(), vector<Fraction>(a.size(), 0));
    for(int i = 0; i < a.size(); i++) {
        result[i][i] = 1;
    }
    for(; y > 0; y >>= 1, matmul(a, a, a)) {
        if((y & 1) == 1) {
            matmul(a, result, result);
        }
    }
    return result;
}

// Nth Fibonacci
ll nthFibonacci(ll n, ll p) {
    vector<vector<ll>> base(2, vector<ll>(2, 1));
    base[1][1] = 0;
    return power(base, n, p)[0][1];
}

// Prefix Sum
vector<ll> prefixSum(vector<int> &a) {
    int n = a.size();
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    return prefix;
}

vector<ll> prefixSum(vector<ll> &a) {
    int n = a.size();
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    return prefix;
}

// Suffix Sum
vector<ll> suffixSum(vector<int> &a) {
    int n = a.size();
    vector<ll> suffix(n);
    suffix[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + a[i];
    }
    return suffix;
}

vector<ll> suffixSum(vector<ll> &a) {
    int n = a.size();
    vector<ll> suffix(n);
    suffix[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + a[i];
    }
    return suffix;
}

// Set bit count
int popCount(ll n) {
    int c = 0;
    for(; n > 0; c += n % 2, n >>= 1);
    return c;
}

// Disjoint Set Union

class DSU {
    private:
    int size = 0;
    vector<int> parent;
    vector<int> weight;

    public:
    DSU(int N) {
        size = N + 1;
        parent.resize(size);
        weight.resize(size, 1);
        for(int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    
    int get(int a) {
        for(; parent[a] != a; parent[a] = parent[parent[a]], a = parent[a]);
        return a;
    }

    int getParent(int a) {
        return get(a);
    }

    void join(int a, int b) {
        set_union(a, b);
    }

    void set_union(int a, int b) {
        int parent_of_a = get(a);
        int parent_of_b = get(b);
        if(parent_of_a == parent_of_b) {
            return;
        }
        if(weight[parent_of_a] < weight[parent_of_b]) {
            parent[parent_of_a] = parent[parent_of_b];
            weight[parent_of_b] += weight[parent_of_a];
        }
        else {
            parent[parent_of_b] = parent[parent_of_a];
            weight[parent_of_a] += weight[parent_of_b];
        }
    }
};

// Primality Class - Trial Division and Miller Rabin Test

class Primality {
    public:
    bool check(ll n) {
        if(n == 0 || n == 1) {
            return false;
        }
        else if(n == 2 || n == 3) {
            return true;
        }
        else if(n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        const int root = ((int)(sqrt(n)));
        for(int i = 5; i <= root; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    ll powr(ll x, ll y, ll p) {
        ll result = 1;
        for(result = 1; y > 0; x = (x % p * x % p) % p, y >>= 1)
            if((y & 1) == 1)
                result = (result % p * x % p) % p;
        return result;
    }

    bool check_composite(ll n, ll a, ll d, ll s) {
        ll x = powr(a, d, n);
        if(x == 1 || x == n - 1)
            return false;
        for(int r = 1; r < s; r++) {
            x = (x % n * x % n) % n;
            if(x == n - 1)
                return false;
        }
        return true;
    }
    bool test(ll n) {
        if(n < 2)
            return false;
        int r = 0;
        ll d = n - 1;
        while((d&1) == 0) {
            d >>= 1;
            r ++;
        }
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for(int i = 0; i < primes.size(); i++) {
            int a = primes[i];
            if(n == a)
                return true;
            if(check_composite(n, a, d, r))
                return false;
        }
        return true;
    }
};


// Sieve for prime generation, Smallest Prime Factor, Euler Totient Function
class Sieve {
    public:
    vector<bool> prime;
    vector<int> primes;
    vector<int> phi;
    vector<int> spf;
    vector<bool> sieve(int size) {
        prime.resize(size, false);
        prime[2] = true;
        for(int i = 3; i < size; i += 2) {
            prime[i] = true;
        }
        for(int i = 3; i <= sqrt(size); i += 2) {
            if(prime[i]) {
                for(int j = i * i; j < size; j += i) {
                    prime[j] = false;
                }
            }
        }
		return prime;
    }
    vector<int> getPrimes(int size) {
        if(prime.size() == 0) {
            sieve(size);
        }
        if(primes.size() == 0) {
            primes.push_back(2);
            primes.push_back(3);
            for(int i = 5; i + 2 < size; i += 6) {
                if(prime[i]) {
                    primes.push_back(i);
                }
                if(prime[i + 2]) {
                    primes.push_back(i + 2);
                }
            }
        }
        return primes;
    }

    vector<int> getSPF(int size) {
        spf.resize(size);
        spf[0] = spf[1] = 1;
        for(int i = 2; i < size; i += 2) {
            spf[i] = 2;
        }
        for(int i = 3; i < size; i += 2) {
            spf[i] = i;
        }
        for(int i = 3; i < sqrt(size); i += 2) {
            if(spf[i] == i) {
                for(int j = i * i; j < size; j += i) {
                    if(spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
        return spf;
    }

    vector<int> getTotient(int size) {
        phi.resize(size);
        for(int i = 0; i < size; i ++) {
            phi[i] = i;
        }
        for(int i = 2; i < size; i++) {
            if(phi[i] == i) {
                for(int j = i; j < size; j += i) {
                    phi[j] -= phi[j] / i;
                }
            }
        }
        return phi;
    }

    int number_of_factors(int n) {
        int ans = 1;
        for(int c = 0; n > 1; c = 0) {
            for(int s = spf[n]; s == spf[n]; n /= s, c++);
            ans *= c + 1;
        }
        return ans;
    }

};