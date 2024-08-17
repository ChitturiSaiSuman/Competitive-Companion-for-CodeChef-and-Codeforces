
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <boost/multiprecision/cpp_int.hpp>

using namespace std;
// using namespace __gnu_pbds;
// using namespace boost::multiprecision;

#ifdef SUMAN
#include "DEBUG.h"
#define LINE		cerr << "line " << __LINE__ << ": ";
#define debug(x)    LINE; cerr << "(" << #x << ")"; debug(x)
#else
#define debug(x)
#endif

#define FOR(x, N)	for(int x = 0; x < N; x++)
#define endl		'\n'

typedef unsigned long long int ull;
typedef long long int ll;

const short int dc[] = {1, 0, 0, -1, -1, -1, 1, 1};
const short int dr[] = {0, 1, -1, 0, -1, 1, -1, 1};

const ll shit	= ((ll)(998244353));
const ll mod	= ((ll)(1e9 + 7));
const ll hell	= ((ll)(1e9 + 9));
const ll inf	= ((ll)(1e18 + 3));

static inline ll gcd(ll a, ll b) {
	for(; b > 0; a %= b, swap(a, b));
	return a;
}
static inline ll lcm(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}
static inline ll power(ll a, ll b, ll p) {
	ll result = 1;
	for(; b > 0; b >>= 1, a = a * a % p) {
		if(b & 1) {
			result = result * a % p;
		}
	}
	return result;
}
static inline ll inverse(ll a, ll p) {
	return power(a, p - 2, p);
}

#define nax 2000003


void pre_compute() {
	return;
}

void solve() {
	
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
	cin >> t;
	pre_compute();
	FOR(test, t) {
		// cout << "Case #" << (test + 1) << ": ";
		solve();
		#ifdef SUMAN
		cerr << '\n';
		#endif
	}
	return 0;
}

// Fraction template for CPP

class Fraction {
    private:
    ll GCD(ll a, ll b) {
        for(ll rem; b > 0; rem = a % b, a = b, b = rem);
        return a;
    }
    ll LCM(ll a, ll b) {
        return (a * b) / GCD(a, b);
    }
    public:
    ll num = 0, den = 1;
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
            throw invalid_argument("Expected Non-Zero denominator");
        }
        num = n;
        den = d;
        ll g = GCD(num, den);
        num /= g;
        den /= g;
    };
    Fraction(Fraction& f) {
        num = f.num;
        den = f.den;
    };
    Fraction(string s) {
        int pos = s.find('/');
        if(pos != string::npos) {
            num = stoll(s.substr(0, pos));
            den = stoll(s.substr(pos + 1, s.size()));
            ll g = GCD(num, den);
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
    Fraction operator + (const Fraction& frac) {
        ll l = LCM(den, frac.den);
        ll a = num * (l / den);
        ll b = frac.num * (l / frac.den);
        return Fraction(a + b, l);
    }
    void operator += (const Fraction& frac) {
        Fraction f = Fraction(num, den);
        f = (f + frac);
        num = f.num;
        den = f.den;
    }
    Fraction operator - (const Fraction& frac) {
        ll l = LCM(den, frac.den);
        ll a = num * (l / den);
        ll b = frac.num * (l / frac.den);
        return Fraction(a - b, l);
    }
    void operator -= (const Fraction& frac) {
        Fraction f = Fraction(num, den);
        f = (f - frac);
        num = f.num;
        den = f.den;
    }
    Fraction operator * (const Fraction& frac) {
        return Fraction(num * frac.num, den * frac.den);
    }
    void operator *= (const Fraction& frac) {
        Fraction f = Fraction(num, den);
        f = (f * frac);
        num = f.num;
        den = f.den;
    }
    Fraction operator / (const Fraction& frac) {
        return Fraction(num * frac.den, den * frac.num);
    }
    void operator /= (const Fraction& frac) {
        Fraction f = Fraction(num, den);
        f = (f / frac);
        num = f.num;
        den = f.den;
    }
    bool operator == (const Fraction& frac) {
        return (frac.num == num && frac.den == den);
    }
    bool operator != (const Fraction& frac) {
        return !(frac.num == num && frac.den == den);
    }
    bool operator < (const Fraction& frac) {
        ll base = LCM(den, frac.den);
        return (num * base/den) < (frac.num * base/frac.den);
    }
    bool operator <= (const Fraction& frac) {
        ll base = LCM(den, frac.den);
        return (num * base/den) <= (frac.num * base/frac.den);
    }
    bool operator > (const Fraction& frac) {
        ll base = LCM(den, frac.den);
        return (num * base/den) > (frac.num * base/frac.den);
    }
    bool operator >= (const Fraction& frac) {
        ll base = LCM(den, frac.den);
        return (num * base/den) >= (frac.num * base/frac.den);
    }
};
ostream& operator << (ostream& out, const Fraction& f) {
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
        graph.resize(V, vector<int>());
    }

    void add_edge(int a, int b) {
        graph[a].push_back(b);
    }

    bool bfs(int start, int end) {
        vector<bool> visited(V, false);
        visited[start] = true;
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

    void recurse(int start, vector<bool>& visited, int end) {
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

vector<int> next_greater_in_right(vector<int> a, int n) {
    vector<int> right_index(n, n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[i] > a[st.top()]) {
            right_index[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return right_index;
}

vector<int> next_greater_in_left(vector<int>& a, int n) {
    vector<int> left_index(n, -1);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[i] > a[st.top()]) {
            left_index[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return left_index;
}

vector<int> next_smaller_in_right(vector<int>& a, int n) {
    vector<int> right_index(n, n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[i] < a[st.top()]) {
            right_index[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return right_index;
}

vector<int> next_smaller_in_left(vector<int>& a, int n) {
    vector<int> left_index(n, -1);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[i] < a[st.top()]) {
            left_index[st.top()] = i;
            st.pop();
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
    static inline ll fun(ll a, ll b) {
        return a + b;
    }

    public:
    SegmentTree(vector<int> arr, int def_value = 0) {
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
        }
        arr.resize(n, default_value);
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
        return range_query(index, index);
    }

    void point_update(int index, ll value) {
        /**
         * Updates a single node and its Ancestors - Sets the node to this value
         */
        point_update(1, 0, length - 1, index, value);
    }

    private:
    ll point_update(int node, int node_lb, int node_ub, int index, ll value) {
        if(index < node_lb || node_ub < index) {
            return tree[node];
        }
        else if(node_lb == node_ub && node_ub == index) {
            tree[node] = value;
        }
        else {
            ll left_returned = point_update(2 * node, node_lb, (node_lb + node_ub) / 2, index, value);
            ll right_returned = point_update(2 * node + 1, (node_lb + node_ub) / 2 + 1, node_ub, index, value);
            tree[node] = key(left_returned, right_returned);
        }
        return tree[node];
    }

    public:
    void range_update(int range_lb, int range_ub, ll value) {
        /**
         * Updates Several Nodes using the results of Key Function over Children
         */
        range_update(1, 0, length - 1, range_lb, range_ub, value);
    }

    private:
    ll range_update(int node, int node_lb, int node_ub, int range_lb, int range_ub, ll value) {
        if(range_lb <= node_lb && node_ub <= range_ub) {
            carry[node] = key(carry[node], value);
        }
        else if(node_ub < range_lb || range_ub < node_lb) {
            return carry[node];
        }
        else {
            range_update(2 * node, node_lb, (node_lb + node_ub) / 2, range_lb, range_ub, value);
            range_update(2 * node + 1, (node_lb + node_ub) / 2 + 1, node_ub, range_lb, range_ub, value);
        }
        return carry[node];
    }

    public:
    ll range_query(int query_lb, int query_ub) {
        /**
         * Returns the result of Key Function over the range
         */
        return range_query(1, 0, length - 1, query_lb, query_ub);
    }
    
    private:
    ll range_query(int node, int node_lb, int node_ub, int query_lb, int query_ub) {
        if(query_lb <= node_lb && node_ub <= query_ub) {
            return key(tree[node], carry[node]);
        }
        else if(query_ub < node_lb || node_ub < query_lb) {
            return default_value;
        }
        else {
            ll left_returned = range_query(2 * node, node_lb, (node_lb + node_ub) / 2, query_lb, query_ub);
            ll right_returned = range_query(2 * node + 1, (node_lb + node_ub) / 2 + 1, node_ub, query_lb, query_ub);
            return key(carry[node], key(left_returned, right_returned));
        }
    }
};
// End of Segment Tree

// Segment Tree from ChatGPT

class SegmentTree {
private:
	vector<ll> tree;
	vector<ll> lazy;
	int tree_size;
	
	void build(vector<ll>& nums, int node, int start, int end) {
		if (start == end) {
			tree[node] = nums[start];
		} else {
			int mid = (start + end) / 2;
			build(nums, 2 * node + 1, start, mid);
			build(nums, 2 * node + 2, mid + 1, end);
			tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
		}
	}

	void updateLazy(int node, int start, int end) {
		if (lazy[node] != 0) {
			tree[node] += (end - start + 1) * lazy[node];
			if (start != end) {
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

	void rangeUpdate(int l, int r, ll val, int node, int start, int end) {
		updateLazy(node, start, end);

		if (start > end || start > r || end < l) {
			return;
		}

		if (start >= l && end <= r) {
			tree[node] += (end - start + 1) * val;
			if (start != end) {
				lazy[2 * node + 1] += val;
				lazy[2 * node + 2] += val;
			}
			return;
		}

		int mid = (start + end) / 2;
		rangeUpdate(l, r, val, 2 * node + 1, start, mid);
		rangeUpdate(l, r, val, 2 * node + 2, mid + 1, end);
		tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
	}

	ll rangeQuery(int l, int r, int node, int start, int end) {
		updateLazy(node, start, end);

		if (start > end || start > r || end < l) {
			return 0;
		}

		if (start >= l && end <= r) {
			return tree[node];
		}

		int mid = (start + end) / 2;
		ll leftQuery = rangeQuery(l, r, 2 * node + 1, start, mid);
		ll rightQuery = rangeQuery(l, r, 2 * node + 2, mid + 1, end);
		return leftQuery + rightQuery;
	}

public:
	SegmentTree(int N) {
		tree_size = N;
		int k = __builtin_clz(tree_size);
		int size = 1 << ((1<<3) + 1 - k);
		tree.resize(size);
		lazy.resize(size, 0);
	}

	SegmentTree(vector<ll>& nums) {
		tree_size = nums.size();
		int k = __builtin_clzll(tree_size);
		int size = 1 << ((1<<3) + 1 - k);
		tree.resize(size);
		lazy.resize(size, 0);
		build(nums, 0, 0, tree_size - 1);
	}

	void rangeUpdate(int l, int r, ll val) {
		rangeUpdate(l, r, val, 0, 0, tree_size - 1);
	}

	ll rangeQuery(int l, int r) {
		return rangeQuery(l, r, 0, 0, tree_size - 1);
	}
};

// Trie for strings

class Trie {

    private:
    class Node {

        public:
        map<char, Node*> next;
        bool is_terminal_node;
        int same_prefix_count;

        Node() {
            is_terminal_node = false;
            same_prefix_count = 0;
        }
    };

    Node *root;
    string lcp;
    int count;
    int lcp_length;

    public:
    Trie() {
        root = new Node();
        count = 0;
        lcp_length = 0;
    }

    int size() {
        return count;
    }

    void insert(string& str) {
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
            lcp_length = i;
        }
    }

    int longest_common_prefix_length() {
        return lcp_length;
    }

    string longest_common_prefix() {
        return lcp;
    }

    void remove(string& str) {
        if(!contains(str)) {
            return;
        }
        _remove(root, str, str.size());
    }

    bool contains(string& str) {
        return _find(root, str, str.size());
    }

    int prefix_count(string& prefix) {
        return _prefix_count(root, prefix, prefix.size());
    }

    private:
    void _insert(Node* node, string& str, const int length) {
        for(int i = 0; i < length; i++) {
            char ind = str[i];
            if(node -> next[ind] == nullptr) {
                node -> next[ind] = new Node();
            }
            (node -> next[ind]) -> same_prefix_count++;
            node = node -> next[ind];
        }
        node -> is_terminal_node = true;
    }

    void _remove(Node* node, string& str, const int length) {
        for(int i = 0; i < length; i++) {
            char ind = str[i];
            node = node -> next[ind];
        }
        node -> is_terminal_node = false;
        count--;
    }

    bool _find(Node* node, string& str, const int length) {
        for(int i = 0; i < length; i++) {
            char ind = str[i];
            if(node -> next[ind] == nullptr) {
                return false;
            }
            node = node -> next[ind];
        }
        return node -> is_terminal_node;
    }

    int _prefix_count(Node* node, string& prefix, const int length) {
        for(int i = 0; i < length; i++) {
            char ind = prefix[i];
            if(node -> next[ind] == nullptr) {
                return 0;
            }
            node = node -> next[ind];
        }
        return node -> same_prefix_count;
    }
};
// End of Trie


// Utilities for Permutations and Combinations

vector<ll> fact;
vector<ll> inv_fact;
vector<ll> inv;

void prepare(int N, ll p) {

	// factorials
	fact.resize(N);
	fact[0] = 1;
	for(int i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * i % p;
	}

	// inv_factorials
	inv_fact.resize(N);
	inv_fact[N - 1] = power(fact[N - 1], p - 2, p);
	for(int i = N - 2; i >= 0; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % p;
	}

	// inverses
	inv.resize(N);
	inv[0] = 0;
	for(int i = 1; i < N; i++) {
		inv[i] = fact[i - 1] * inv_fact[i] % p;
	}
}

ll nCr_mod_p(int n, int r, ll p) {
	return fact[n] * (inv_fact[r] * inv_fact[n - r] % p) % p;
}

ll nth_catalan_mod_p(int n, ll p) {
	return nCr_mod_p(2 * n, n, p) * inv[n + 1] % p;
}
// End of Template for P & C

// Bisect Functions

template <typename T>
int binary_search(vector<T>& a, T key) {
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
int lower_bound(vector<T>& a, T key) {
    float k = key - 0.5;
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
int upper_bound(vector<T>& a, T key) {
    float k = key + 0.5;
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
ll merge(vector<int>& a, int lb, int ub) {
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

ll merge_sort(vector<int>& a, int lb, int ub) {
    ll ans = 0;
    if(lb < ub) {
        int mid = (lb + ub) / 2;
        ans += merge_sort(a, lb, mid);
        ans += merge_sort(a, mid + 1, ub);
        ans += merge(a, lb, ub);
    }
    return ans;
}

ll count_inversions(vector<int>& a) {
    return merge_sort(a, 0, a.size() - 1);
}
// End of Count Inversions

// Longest common subsequence
int lcs(vector<int>& a, vector<int>& b) {
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

int lcs(string& a, string& b) {
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
void matmul(vector<vector<ll>>& a, vector<vector<ll>>& b, vector<vector<ll>>& res, ll p) {
    int M = a.size();
    int N = a[0].size();
    int P = b[0].size();
    vector<vector<ll>> result(M, vector<ll>(P));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < P; j++) {
            result[i][j] = 0;
            for(int k = 0; k < N; k++) {
                result[i][j] = (result[i][j] % p + (a[i][k] % p * b[k][j] % p) % p) % p;
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

void matmul(vector<vector<Fraction>>& a, vector<vector<Fraction>>& b, vector<vector<Fraction>>& res) {
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
vector<vector<ll>> power(vector<vector<ll>>& a, ll y, ll p) {
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
vector<vector<Fraction>> power(vector<vector<Fraction>>& a, ll y) {
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
pair<ll, ll> fib (ll n, const ll p) {
    if (n == 0)
        return {0, 1};

    auto prev = fib(n >> 1, p);
    ll c = (prev.first * (((2 * prev.second) % p - prev.first) + p) % p) % p;
    ll d = (prev.first * prev.first) % p + (prev.second * prev.second) % p;
    if (n & 1)
        return {d % p, (c + d % p) % p};
    else
        return {c, d % p};
}

// Prefix Sum
vector<ll> prefix_sum(vector<int>& a) {
    int n = a.size();
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    return prefix;
}

vector<ll> prefix_sum(vector<ll>& a) {
    int n = a.size();
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    return prefix;
}

// Suffix Sum
vector<ll> suffix_sum(vector<int>& a) {
    int n = a.size();
    vector<ll> suffix(n);
    suffix[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + a[i];
    }
    return suffix;
}

vector<ll> suffix_sum(vector<ll>& a) {
    int n = a.size();
    vector<ll> suffix(n);
    suffix[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + a[i];
    }
    return suffix;
}

// Set bit count
int pop_count(ll n) {
    int c = 0;
    for(; n > 0; c += n % 2, n >>= 1);
    return c;
}

// Disjoint Set Union

class DSU {
    public:
    int size = 0;
    vector<int> parent;
    vector<int> weight;

    DSU(int N) {
        size = N;
        parent.resize(size);
        weight.resize(size, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int get(int a) {
        int p = parent[a];
        for(; parent[p] != p; p = parent[parent[p]]);
        for(int b = parent[a]; a != p; parent[a] = p, a = b, b = parent[a]);
        return p;
    }

    void join(int a, int b) {
        a = get(a);
        b = get(b);
        if(a == b) {
            return;
        }
        if(weight[a] < weight[b]) {
            parent[a] = parent[b];
            weight[b] += weight[a];
        }
        else {
            parent[b] = parent[a];
            weight[a] += weight[b];
        }
    }

    vector<vector<int>> get_components() {
        vector<vector<int>> components;
        map<int, vector<int>> component_map;
        for(int i = 0; i < size; i++) {
            int p = get(i);
            component_map[p].push_back(i);
        }
        for(auto component : component_map) {
            components.push_back(component.second);
        }
        return components;
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


// Yarin Sieve
// This is the famous "Yarin Sieve", for use when memory is tight

#define MAXSIEVE 100000001
#define MAXSIEVEHALF (MAXSIEVE >> 1)
#define MAXSQRT 5000
#define isprime(n) ((is_prime[n >> 4] & (1 << ((n >> 1) & 7))) && ((n & 1) || (n == 2)))

char is_prime[MAXSIEVE / (1 << 4) + 2];

int Yarin() {
    memset(is_prime, (1 << (1 << 3)) - 1, sizeof(is_prime));
    is_prime[0] = 0xFE;
    for(int i = 1; i < MAXSQRT; i++) {
        if(is_prime[i >> 3] & (1 << (i & 7))) {
            for(int j = 2 * i * (i + 1); j < MAXSIEVEHALF; j += (i << 1) + 1) {
                is_prime[j >> 3] &= ~(1 << (j & 7));
            }
        }
    }
    return 0;
}

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
    vector<int> get_primes(int size) {
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

    vector<int> get_spf(int size) {
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

    vector<int> get_totient(int size) {
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

class LCA {
    /**
     * @brief Lowest Common Ancestor for Multiple Queries
     * Uses Binary Lifting to pre-compute in O(N log N) time
     * And answer queries in Log N time
     * @tparam vector<vector<int>>& adj: Adjacency list of the tree
     */
 
public:
 
    int N = 0, LOG = 0;
    vector<vector<int>> ancestor;
    vector<int> depth;
 
    LCA(vector<vector<int>>& adj) {
        N = adj.size();
        LOG = ceil(log2(N)) + 2;
        ancestor.resize(N, vector<int>(LOG));
        depth.resize(N, 0);
        vector<bool> visited(N);
        dfs(adj, 0, visited);
    }
 
    int get_lca(int a, int b) {
        if(depth[a] < depth[b]) {
            swap(a, b);
        }
 
        int k = depth[a] - depth[b];
        for(int j = LOG - 1; j >= 0; j--) {
            if(k & (1 << j)) {
                a = ancestor[a][j];
            }
        }
 
        if(a == b) {
            return a;
        }
 
        for(int j = LOG - 1; j >= 0; j--) {
            if(ancestor[a][j] != ancestor[b][j]) {
                a = ancestor[a][j];
                b = ancestor[b][j];
            }
        }
 
        return ancestor[a][0];
    }
 
private:
 
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {
        visited[node] = true;
        for(int child : adj[node]) {
            if(visited[child]) {
                continue;
            }
            depth[child] = depth[node] + 1;
            ancestor[child][0] = node;
            for(int level = 1; level < LOG; level++) {
                ancestor[child][level] = ancestor[ancestor[child][level-1]][level-1];
            }
            dfs(adj, child, visited);
        }
    }
};

vector<int> dijkstra(vector<vector<int>>& adj, int V, map<pair<int, int>, int>& cost, int start) {
    /**
     * Returns the distances
     * from the vertex 'start' to other vertices
    */

    // Visited array to keep track of visited vertices
    vector<bool> visited(V, false);
    // Distance array to keep track of distances to vertices
    vector<int> dist(V, INT_MAX);

    dist[start] = 0;

    // Priority queue for min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    for(; !pq.empty(); pq.pop()) {
        // Pick the next promising pair that will guarantee
        // Shortest path
        pair<int, int> promising_pair = pq.top();
        int value = promising_pair.first;
        int vertex = promising_pair.second;

        // Mark this index as visited
        visited[vertex] = true;

        // If the distance to this vertex is already less
        // We will not apply relaxation to this vertex
        if(dist[vertex] < value) continue;

        for(int child: adj[vertex]) {
            if(visited[child]) {
                continue;
            }
            int new_distance = dist[vertex] + cost[make_pair(vertex, child)];

            // If new distance is less than previous distance
            // Relaxation is done on the cost to reach this vertex
            if(new_distance < dist[child]) {
                dist[child] = new_distance;
                pq.push(make_pair(new_distance, child));
            }
        }
    }
    // dist[i] = INT_MAX if unreachable
    return dist;
}

// Hash tables using Policy based Data Structures

#include <bits/stdc++.h>
using namespace std;

// ***************************************************************************************
// Usage:

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

gp_hash_table<int, int> table;

// ***************************************************************************************
// Defeat anti-hash test

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, int, chash> table;

// ***************************************************************************************
// For Pairs

struct chash {
    int operator()(pair<int, int> x) const { return x.first * 31 + x.second; }
};
gp_hash_table<pair<int, int>, int, chash> table;

// ***************************************************************************************
// High-quality and fast custom-hash

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<long long, int, custom_hash> safe_map;
gp_hash_table<long long, int, custom_hash> safe_hash_table;

// ***************************************************************************************
// Polynomial Hash Functions

class Hash {
private:
    int length;
    const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    const int p1 = 31, p2 = 37;
    vector<int> hash1, hash2;
    pair<int, int> hash_pair;
    const char seed = 'a';

public:
    inline static vector<int> inv_pow1, inv_pow2;
    inline static int inv_size = 1;

    Hash(const string& s) {
        length = s.size();
        hash1.resize(length);
        hash2.resize(length);

        int h1 = 0, h2 = 0;
        long long p_pow1 = 1, p_pow2 = 1;
        for(int i = 0; i < length; i++) {
            h1 = (h1 + (s[i] - seed + 1) * p_pow1) % mod1;
            h2 = (h2 + (s[i] - seed + 1) * p_pow2) % mod2;
            p_pow1 = (p_pow1 * p1) % mod1;
            p_pow2 = (p_pow2 * p2) % mod2;
            hash1[i] = h1;
            hash2[i] = h2;
        }
        hash_pair = make_pair(h1, h2);

        if(inv_size < length) {
            for(; inv_size < length; inv_size <<= 1);
            
            inv_pow1.resize(inv_size, -1);
            inv_pow2.resize(inv_size, -1);

            inv_pow1[inv_size - 1] = inverse(power(p1, inv_size - 1, mod1), mod1);
            inv_pow2[inv_size - 1] = inverse(power(p2, inv_size - 1, mod2), mod2);
            
            for(int i = inv_size - 2; i >= 0 && inv_pow1[i] == -1; i--) {
                inv_pow1[i] = (1LL * inv_pow1[i + 1] * p1) % mod1;
                inv_pow2[i] = (1LL * inv_pow2[i + 1] * p2) % mod2;
            }
        }
    }

    int size() {
        return length;
    }

    pair<int, int> prefix(const int index) {
        return {hash1[index], hash2[index]};
    }

    pair<int, int> substr(const int l, const int r) {
        if(l == 0) {
            return {hash1[r], hash2[r]};
        }
        int temp1 = hash1[r] - hash1[l - 1];
        int temp2 = hash2[r] - hash2[l - 1];
        temp1 += (temp1 < 0 ? mod1 : 0);
        temp2 += (temp2 < 0 ? mod2 : 0);
        temp1 = (temp1 * 1LL * inv_pow1[l]) % mod1;
        temp2 = (temp2 * 1LL * inv_pow2[l]) % mod2;
        return {temp1, temp2};
    }

    bool operator==(const Hash& other) {
        return (hash_pair == other.hash_pair);
    }
};

int longest_common_substring(const string& s1, const string& s2) {
    Hash h1(s1), h2(s2);
    const int m = s1.length(), n = s2.length();

    auto find = [&](int k) {
        set<pair<int, int>> substring_hashes;
        for(int begin = 0, end = begin + k - 1; end < n; begin++, end++) {
            substring_hashes.insert(h2.substr(begin, end));
        }
        for(int begin = 0, end = begin + k - 1; end < m; begin++, end++) {
            if(substring_hashes.count(h1.substr(begin, end))) {
                return true;
            }
        }
        return false;
    };

    int lcs_length = 0;
    int lb = 1, ub = min(m, n);
    while(lb <= ub) {
        int mid = (lb + ub) / 2;
        if(find(mid)) {
            lcs_length = mid;
            lb = mid + 1;
        } else {
            ub = mid - 1;
        }
    }

    return lcs_length;
}

// Big Integer for arbitrary 
// length integers

class big_integer {
public:
    short sign = 1;
    int length;
    string num;

    big_integer() {
        sign = 1;
        length = 0;
    }

    big_integer(const string& s) {
        length = s.length();
        assert(length > 0);
        if(s[0] == '-') {
            sign = -1;
            num = s.substr(1);
            length--;
        } else {
            sign = 1;
            num = s;
        }
        for(int i = 0; i < length; i++) {
            assert('0' <= num[i] && num[i] <= '9');
        }
        reverse(num.begin(), num.end());
        trim();
    }

    string to_string() {
        string res;
        if(sign == -1) {
            res.push_back('-');
        }
        for(int i = length - 1; i >= 0; i--) {
            res.push_back(num[i]);
        }
        return res;
    }

private:
    void trim() {
        while(length > 0 && num[length - 1] == '0') {
            length--;
            num.pop_back();
        }
        if(length == 0) {
            length++;
            num.push_back('0');
            sign = 1;
        }
    }

    bool lesser(const big_integer& a, const big_integer& b, const bool ignore_sign = false) const {
        if(a.length != b.length) {
            if(ignore_sign) {
                return a.length < b.length;
            }
            else {
                if(a.sign == 1 && b.sign == 1) {
                    return a.length < b.length;
                }
                else if(a.sign == -1 && b.sign == -1) {
                    return b.length < a.length;
                }
                else {
                    return a.sign == -1;
                }
            }
        }
        else {
            for(int i = a.length - 1; i >= 0; i--) {
                if(a.num[i] != b.num[i]) {
                    if(ignore_sign) {
                        return a.num[i] < b.num[i];
                    }
                    else {
                        if(a.sign == 1 && b.sign == 1) {
                            return a.num[i] < b.num[i];
                        }
                        else if(a.sign == -1 && b.sign == -1) {
                            return b.num[i] < a.num[i];
                        }
                        else {
                            return a.sign == -1;
                        }
                    }
                }
            }
            return false;
        }
    }

    bool greater(const big_integer& a, const big_integer& b, const bool ignore_sign = false) const {
        if(a.length != b.length) {
            if(ignore_sign) {
                return a.length > b.length;
            }
            else {
                if(a.sign == 1 && b.sign == 1) {
                    return a.length > b.length;
                }
                else if(a.sign == -1 && b.sign == -1) {
                    return b.length > a.length;
                }
                else {
                    return a.sign == 1;
                }
            }
        }
        else {
            for(int i = a.length - 1; i >= 0; i--) {
                if(a.num[i] != b.num[i]) {
                    if(ignore_sign) {
                        return a.num[i] > b.num[i];
                    }
                    else {
                        if(a.sign == 1 && b.sign == 1) {
                            return a.num[i] > b.num[i];
                        }
                        else if(a.sign == -1 && b.sign == -1) {
                            return b.num[i] > a.num[i];
                        }
                        else {
                            return a.sign == 1;
                        }
                    }
                }
            }
            return false;
        }
    }

    bool equals(const big_integer& a, const big_integer& b, const bool ignore_sign = false) const {
        return a.num == b.num && (ignore_sign ? true : a.sign == b.sign);
    }

public:
    bool operator ==(const big_integer& other) const {
        return equals(*this, other);
    }

    bool operator <(const big_integer& other) const {
        return lesser(*this, other);
    }

    bool operator >(const big_integer& other) const {
        return other < *this;
    }

    bool operator >=(const big_integer& other) const {
        return (*this > other || *this == other);
    }

    bool operator <=(const big_integer& other) const {
        return (*this < other || *this == other);
    }

    bool operator !=(const big_integer& other) const {
        return !(*this == other);
    }

private:
    big_integer add(const big_integer& a, const big_integer& b, short result_sign) const {
        big_integer res;
        int carry = 0;
        int i = 0;
        const int len1 = a.length, len2 = b.length;
        while(i < len1 || i < len2 || carry) {
            int sum = carry;
            if(i < len1) sum += a.num[i] - '0';
            if(i < len2) sum += b.num[i] - '0';
            res.num += (sum % 10) + '0';
            carry = sum / 10;
            i++;
        }
        res.sign = result_sign;
        res.length = res.num.size();
        res.trim();
        return res;
    }

    big_integer sub(const big_integer& a, const big_integer& b, short result_sign) const {
        big_integer res;
        int borrow = 0;
        int i = 0;
        const int len1 = a.length, len2 = b.length;
        while(i < len1 || i < len2 || borrow) {
            int diff = -borrow;
            if(i < len1) diff += a.num[i] - '0';
            if(i < len2) diff -= b.num[i] - '0';
            if(diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
            res.num += (diff % 10) + '0';
            i++;
        }
        res.sign = result_sign;
        res.length = res.num.size();
        res.trim();
        return res;
    }

    big_integer mul(const int x) const {
        assert(0 <= x && x <= 9);
        big_integer res;
        int carry = 0;
        for(int i = 0; i < length; i++) {
            int cur = (num[i] - '0') * x + carry;
            res.num += (cur % 10) + '0';
            carry = cur / 10;
        }
        if(carry) res.num += carry + '0';
        res.sign = 1;
        res.length = res.num.size();
        res.trim();
        return res;
    }

    big_integer div(const big_integer& other) const {
        assert(other != big_integer("0"));
        auto half = [&](big_integer& a) {
            a.num[0] -= (a.num[0] - '0') & 1;
            int dividend = 0;
            string result;
            for(int i = a.length - 1; i >= 0; i--) {
                dividend = (dividend * 10) + (a.num[i] - '0');
                if(dividend == 1) {
                    if(i != a.length - 1) {
                        result.push_back('0');
                    }
                    continue;
                }
                result.push_back(dividend / 2 + '0');
                dividend %= 2;
            }
            reverse(result.begin(), result.end());
            if(result == "") {
                a.num = "0";
            }
            else {
                a.num = result;
            }
            a.length = a.num.size();
            a.trim();
        };
        big_integer lb("0"), ub(*this);
        lb.sign = 1, ub.sign = 1;
        big_integer result;
        while(lb <= ub) {
            big_integer mid = (lb + ub);
            half(mid);
            big_integer product = other * mid;
            if(lesser(product, *this, true) || equals(product, *this, true)) {
                result = mid;
                lb = mid + big_integer("1");
            }
            else {
                ub = mid - big_integer("1");
            }
        }
        result.length = result.num.size();
        result.trim();
        result.sign = (result == big_integer("0") ? 1 : this->sign * other.sign);
        return result;
    }

public:
    big_integer operator+(const big_integer& other) const {
        if(sign * other.sign == 1) {
            return add(*this, other, this -> sign);
        }
        else {
            if(this -> sign == -1) {
                if(lesser(*this, other, true)) {
                    return sub(other, *this, 1);
                }
                else if(greater(*this, other, true)) {
                    return sub(*this, other, -1);
                }
                else {
                    return big_integer("0");
                }
            }
            else {
                if(lesser(*this, other, true)) {
                    return sub(other, *this, -1);
                }
                else if(greater(*this, other, true)) {
                    return sub(*this, other, 1);
                }
                else {
                    return big_integer("0");
                }
            }
        }
    }

    big_integer operator-(const big_integer& other) const {
        if(sign * other.sign == -1) {
            return add(*this, other, this -> sign);
        }
        else {
            if(this -> sign == -1) {
                if(lesser(*this, other, true)) {
                    return sub(other, *this, 1);
                }
                else if(greater(*this, other, true)) {
                    return sub(*this, other, -1);
                }
                else {
                    return big_integer("0");
                }
            }
            else {
                if(lesser(*this, other, true)) {
                    return sub(other, *this, -1);
                }
                else if(greater(*this, other, true)) {
                    return sub(*this, other, 1);
                }
                else {
                    return big_integer("0");
                }
            }
        }
    }

    big_integer operator*(const big_integer& other) const {
        string prods[10];
        for(int i = 0; i < 10; i++) {
            prods[i] = mul(i).num;
            reverse(prods[i].begin(), prods[i].end());
        }

        const int len2 = other.length;

        string zeroes;
        big_integer res;

        for(int i = 0; i < len2; i++) {
            string curr_prod = prods[other.num[i] - '0'];
            curr_prod += zeroes;
            res = add(res, curr_prod, 1);
            zeroes += '0';
        }

        res.sign = sign * other.sign;
        res.length = res.num.size();
        res.trim();
        return res;
    }

    big_integer operator/(const big_integer& other) {
        return div(other);
    }

    big_integer operator%(const big_integer& other) {
        big_integer quotient = *(this) / other;
        big_integer product = quotient * other;
        big_integer remainder = *this - product;
        return remainder;
    }

    void operator+=(const big_integer& other) {
        *this = *this + other;
    }

    void operator-=(const big_integer& other) {
        *this = *this - other;
    }

    void operator*=(const big_integer& other) {
        *this = *this * other;
    }

    void operator/=(const big_integer& other) {
        *this = *this / other;
    }

    void operator%=(const big_integer& other) {
        *this = *this % other;
    }

    ~big_integer() {
        this -> num.clear();
        this -> sign = 1;
        this -> length = 0;
    }
};

ostream& operator<<(ostream& out, const big_integer& a) {
    if(a.sign == -1) {
        out << "-";
    }
    for(int i = a.length - 1; i >= 0; i--) {
        out << a.num[i];
    }
    return out;
}

// Ordered Multiset (allows Duplicates)
// Code written by ChatGPT
// Supports O(log N) insertion, removal and access
// Keeps the elements ordered
template <typename T>
class ordered_multiset {
private:
    enum Color { RED, BLACK };

    struct Node {
        T key;
        Node* parent;
        Node* left;
        Node* right;
        Color color;
        int size;
    };

    Node* root;

    Node* createNode(const T& key) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->parent = nullptr;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->color = RED;
        newNode->size = 1;
        return newNode;
    }

    void updateSize(Node* node) {
        if (node != nullptr) {
            int leftSize = (node->left != nullptr) ? node->left->size : 0;
            int rightSize = (node->right != nullptr) ? node->right->size : 0;
            node->size = leftSize + rightSize + 1;
        }
    }

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;

        updateSize(x);
        updateSize(y);
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;

        updateSize(x);
        updateSize(y);
    }

    void fixInsertion(Node* z) {
        while (z->parent != nullptr && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rotateRight(z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rotateLeft(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v != nullptr)
            v->parent = u->parent;
    }

    Node* treeMinimum(Node* x) {
        while (x->left != nullptr)
            x = x->left;
        return x;
    }

    void fixDeletion(Node* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rotateRight(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            } else {
                Node* w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        rotateLeft(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    Node* findNode(const T& key) const {
        Node* current = root;
        while (current != nullptr) {
            if (key == current->key)
                return current;
            else if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }

    Node* getNodeAtIndex(Node* x, int index) {
        if (x == nullptr)
            return nullptr;

        int leftSize = (x->left != nullptr) ? x->left->size : 0;

        if (index < leftSize)
            return getNodeAtIndex(x->left, index);
        else if (index == leftSize)
            return x;
        else
            return getNodeAtIndex(x->right, index - leftSize - 1);
    }

public:
    RedBlackTree() : root(nullptr) {}

    int insert(const T& key) {
        Node* z = createNode(key);
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr) {
            y = x;
            x->size++;
            if (z->key < x->key)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
        fixInsertion(z);
        return 0;
    }

    void erase(const T& key) {
        Node* z = findNode(key);
        if (z == nullptr)
            return;
        Node* y = z;
        Node* x = nullptr;
        Color yOriginalColor = y->color;
        if (z->left == nullptr) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = treeMinimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z)
                x->parent = y;
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;

        Node* current = x;
        while (current != nullptr) {
            updateSize(current);
            current = current->parent;
        }

        if (yOriginalColor == BLACK)
            fixDeletion(x);
    }

    const T& getElementAt(int index) {
        Node* nodeAtIndex = getNodeAtIndex(root, index);
        if (nodeAtIndex == nullptr) {
            throw std::out_of_range("Index out of range");
        }
        return nodeAtIndex->key;
    }

    int getIndex(const T& key) const {
        int index = 0;
        Node* current = root;
        while (current != nullptr) {
            if (key == current->key)
                return index + (current->left != nullptr ? current->left->size : 0);
            else if (key < current->key)
                current = current->left;
            else {
                index += (current->left != nullptr ? current->left->size : 0) + 1;
                current = current->right;
            }
        }
        throw std::out_of_range("Element not found");
    }
};

// Ordered multi_set using GNU PBDS
// Allows duplicates
// Include these headers
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
template<typename T>
class Ordered_Multiset_PBDS {
private:
    int unique_id = 0;
    tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update> my_tree;
public:
    void insert(T item) {
        my_tree.insert({item, unique_id++});
    }

    void erase(T item) {
        my_tree.erase({item, 0});
    }

    T get_element_at(int index) {
        return (*my_tree.find_by_order(index)).first;
    }

    int count_less_than(T item) {
        return int(my_tree.order_of_key({item, 0}));
    }

    int size() {
        return my_tree.size();
    }
};

// Ordered set (does not allow duplicates)
// Code written by ChatGPT
// Supports O(log N) insertion, removal and access
// Keeps the elements ordered
template <typename T>
class ordered_set {
private:
    set<T> tracker;
    enum Color { RED, BLACK };

    struct Node {
        T key;
        Node* parent;
        Node* left;
        Node* right;
        Color color;
        int size;
    };

    Node* root;

    Node* createNode(const T& key) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->parent = nullptr;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->color = RED;
        newNode->size = 1;
        return newNode;
    }

    void updateSize(Node* node) {
        if (node != nullptr) {
            int leftSize = (node->left != nullptr) ? node->left->size : 0;
            int rightSize = (node->right != nullptr) ? node->right->size : 0;
            node->size = leftSize + rightSize + 1;
        }
    }

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;

        updateSize(x);
        updateSize(y);
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;

        updateSize(x);
        updateSize(y);
    }

    void fixInsertion(Node* z) {
        while (z->parent != nullptr && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rotateRight(z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rotateLeft(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v != nullptr)
            v->parent = u->parent;
    }

    Node* treeMinimum(Node* x) {
        while (x->left != nullptr)
            x = x->left;
        return x;
    }

    void fixDeletion(Node* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rotateRight(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            } else {
                Node* w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        rotateLeft(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    Node* findNode(const T& key) const {
        Node* current = root;
        while (current != nullptr) {
            if (key == current->key)
                return current;
            else if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }

    Node* getNodeAtIndex(Node* x, int index) {
        if (x == nullptr)
            return nullptr;

        int leftSize = (x->left != nullptr) ? x->left->size : 0;

        if (index < leftSize)
            return getNodeAtIndex(x->left, index);
        else if (index == leftSize)
            return x;
        else
            return getNodeAtIndex(x->right, index - leftSize - 1);
    }

public:
    RedBlackTree() : root(nullptr) {}

    int insert(const T& key) {
        if (!(tracker.find(key) == tracker.end())) {
            return;
        }
        tracker.insert(key);
        Node* z = createNode(key);
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr) {
            y = x;
            x->size++;
            if (z->key < x->key)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
        fixInsertion(z);
        return 0;
    }

    void erase(const T& key) {
        tracker.erase(key);
        Node* z = findNode(key);
        if (z == nullptr)
            return;
        Node* y = z;
        Node* x = nullptr;
        Color yOriginalColor = y->color;
        if (z->left == nullptr) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = treeMinimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z)
                x->parent = y;
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;

        Node* current = x;
        while (current != nullptr) {
            updateSize(current);
            current = current->parent;
        }

        if (yOriginalColor == BLACK)
            fixDeletion(x);
    }

    const T& getElementAt(int index) {
        Node* nodeAtIndex = getNodeAtIndex(root, index);
        if (nodeAtIndex == nullptr) {
            throw std::out_of_range("Index out of range");
        }
        return nodeAtIndex->key;
    }

    int getIndex(const T& key) const {
        int index = 0;
        Node* current = root;
        while (current != nullptr) {
            if (key == current->key)
                return index + (current->left != nullptr ? current->left->size : 0);
            else if (key < current->key)
                current = current->left;
            else {
                index += (current->left != nullptr ? current->left->size : 0) + 1;
                current = current->right;
            }
        }
        throw std::out_of_range("Element not found");
    }
};

// Ordered Set using GNU PBDS
// Functions as a set (doesn't allow duplicates)
// Include these headers
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
template<typename T>
class Ordered_Set_PBDS {
private:
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> my_tree;
public:
    void insert(T item) {
        my_tree.insert(item);
    }

    void erase(T item) {
        my_tree.erase(item);
    }

    T get_element_at(int index) {
        return *my_tree.find_by_order(index);
    }

    int count_less_than(T item) {
        return int(my_tree.order_of_key(item));
    }

    int size() {
        return my_tree.size();
    }
};

/**
 * Dynamic Hash:
 *      A Polynomial Rolling Hash and Fenwick Tree
 *      based String Hashing Data Structure.
 * Operations Supported:
 *      int size() {
 *          returns the size of the hash (length of string)
 *      }
 *      pair<int, int> prefix(int index) {
 *          returns the hash of the prefix S[0, index]
 *      }
 *      pair<int, int> substr(int l, int r) {
 *          returns the hash of the substring S[l, r]
 *      }
 *      void update(int index, char source, char target) {
 *          Updates the hash value when S[index]
 *          is replaced from source to target
 *      }
 *      bool operator==(DynamicHash& other) {
 *          returns true if this == other
 *      }
 */
class DynamicHash {
private:
    // Constants
    const char OFFSET = 'a';    // Set this to 'A' if Upper-case
    const int P1 = 31, P2 = 37; // Other options: (1571, 1597), (107897, 126271)
    const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
    const int INV_P1 = inverse(P1, MOD1), INV_P2 = inverse(P2, MOD2);

    // Hash size
    int length = 0;

    // Fenwick Tree members
    int bit_size;
    vector<int> bit1, bit2;

    // Fenwick Tree methods

    /**
     * Builds BIT for the Hash Vectors
     * Call this only when hash1 and hash2 are populated
     */
    void bit_build() {
        bit_size = length + 2;
        bit1.assign(bit_size, 0);
        bit2.assign(bit_size, 0);
        for (int i = 0; i < length; i++) {
            bit_add(bit1, i, hash1[i], MOD1);
            bit_add(bit2, i, hash2[i], MOD2);
        }
    }

    /**
     * Point Addition: Adds Val to the element at index Position
     */
    void bit_add(vector<int>& bit, int index, int val, int modulo) {
        for (++index; index < bit_size; index += index & -index) {
            // if val < 0: adding 2LL * modulo will make it positive
            bit[index] = (bit[index] + (2LL * modulo) + val) % modulo;
        }
    }

    /**
     * Range Query: Returns the Sum of the Prefix ending at index
     */
    pair<int, int> bit_get(int index) const {
        ll h1 = 0, h2 = 0;
        for (++index; index > 0; index -= index & -index) {
            h1 += bit1[index];
            h1 %= MOD1;
            h2 += bit2[index];
            h2 %= MOD2;
        }
        return {(int)h1, (int)h2};
    }
    // End of Fenwick Tree Methods

public:
    // Shared (Static) Members
    // Note: hash1 and hash2 are presumed to be shared but they aren't.
    // They are needed for building Fenwick Trees bit1 and bit2
    inline static vector<int> hash1;
    inline static vector<int> p_pow1 = vector<int>(1, 1);
    inline static vector<int> inv_pow1 = vector<int>(1, 1);

    inline static vector<int> hash2;
    inline static vector<int> p_pow2 = vector<int>(1, 1);
    inline static vector<int> inv_pow2 = vector<int>(1, 1);

    inline static int cache_size = 1; // cache_size always grows

    // Constructor
    DynamicHash(const string& s) {
        length = s.size();

        for (; cache_size < length; cache_size++) {
            p_pow1.push_back((p_pow1.back() * 1LL * P1) % MOD1);
            inv_pow1.push_back((inv_pow1.back() * 1LL * INV_P1) % MOD1);

            p_pow2.push_back((p_pow2.back() * 1LL * P2) % MOD2);
            inv_pow2.push_back((inv_pow2.back() * 1LL * INV_P2) % MOD2);
        }

        hash1.resize(cache_size);
        hash2.resize(cache_size);

        for (int i = 0; i < length; i++) {
            ll h1 = ((s[i] - OFFSET + 1) * 1LL * p_pow1[i]) % MOD1;
            ll h2 = ((s[i] - OFFSET + 1) * 1LL * p_pow2[i]) % MOD2;
            hash1[i] = h1;
            hash2[i] = h2;
        }

        // Do not call this before computing hash1 and hash2
        bit_build();
    }

    /**
     * Returns the size of the string or hash
     */
    int size() const {
        return length;
    }

    /**
     * Returns the Hash of the prefix s[0, index]
     */
    pair<int, int> prefix(const int index) const {
        // Can be a Private Method
        return bit_get(index);
    }

    /**
     * Returns the hash value of the substring s[l, r]
     */
    pair<int, int> substr(const int l, const int r) const {
        if(l == 0) {
            return prefix(r);
        }

        auto p_r = prefix(r);
        auto p_l = prefix(l - 1);

        int temp1 = p_r.first - p_l.first;
        int temp2 = p_r.second - p_l.second;

        temp1 += (temp1 < 0 ? MOD1 : 0); temp1 = (temp1 * 1LL * inv_pow1[l]) % MOD1;
        temp2 += (temp2 < 0 ? MOD2 : 0); temp2 = (temp2 * 1LL * inv_pow2[l]) % MOD2;

        return {temp1, temp2};
    }

    /**
     * Updates the hash value when s[index]
     * is replaced from source to target.
     * Remember to update your original string.
     */
    void update(const int index, const char source, const char target) {
        if (source == target) {
            return;
        }

        // Compute the difference for MOD1 (consider target vs source)
        int d1 = (target - source + MOD1) % MOD1;
        d1 = (d1 * 1LL * p_pow1[index]) % MOD1;

        // Compute the difference for MOD2 (consider target vs source)
        int d2 = (target - source + MOD2) % MOD2;
        d2 = (d2 * 1LL * p_pow2[index]) % MOD2;

        bit_add(bit1, index, d1, MOD1);
        bit_add(bit2, index, d2, MOD2);
    }

    bool operator==(const DynamicHash& other) {
        return prefix(size() - 1) == other.prefix(other.size() - 1);
    }
};