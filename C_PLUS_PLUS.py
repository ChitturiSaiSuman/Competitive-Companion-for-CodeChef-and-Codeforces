c_plus_plus_functions = {
    "Default Template":
"""

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FOR(x, N)					for(int x = 0; x < N; x++)
#define inverse(a, p)				power(a, p - 2, p)

typedef unsigned long long int ull;
typedef long long int ll;

const short int dc[] = {1, 0, 0, -1, -1, -1, 1, 1};
const short int dr[] = {0, 1, -1, 0, -1, 1, -1, 1};

const ll shit	= ((ll)(998244353));
const ll mod	= ((ll)(1e9 + 7));
const ll hell	= ((ll)(1e9 + 9));
const ll inf	= ((ll)(1e18 + 3));

static inline ll gcd(ll a, ll b) {
	for(ll rem = 0; b > 0; rem = a % b, a = b, b = rem);
	return a;
}
static inline ll lcm(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}

#define nax 2000003


void pre_compute() {
	return;
}

void solve() {
	return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 0;
	// t++;
	if(!t) cin >> t;
	pre_compute();
	FOR(test, t) {
		// cout << "Case #" << (test + 1) << ": ";
		solve();
	}
	return 0;
}
""",
    "Tree Generator":
"""
// Simple Tree Genertor
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = rand(2, 20);
    printf("%d\n", n);
    for(int i = 2; i <= n; ++i) {
        printf("%d %d\n", rand(1, i - 1), i);
    }
}

// Strong Tree Generator

#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = rand(2, 20);
    printf("%d\n", n);
    vector<pair<int,int>> edges;
    for(int i = 2; i <= n; ++i) {
        edges.emplace_back(rand(1, i - 1), i);
    }
    
    vector<int> perm(n + 1); // re-naming vertices
    for(int i = 1; i <= n; ++i) {
        perm[i] = i;
    }
    random_shuffle(perm.begin() + 1, perm.end());
    
    random_shuffle(edges.begin(), edges.end()); // random order of edges
    
    for(pair<int, int> edge : edges) {
        int a = edge.first, b = edge.second;
        if(rand() % 2) {
            swap(a, b); // random order of two vertices
        }
        printf("%d %d\n", perm[a], perm[b]);
    }
}
""",
    "Binary Search":
"""
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
""",
    "Lower Bound":
"""
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
""",
    "Upper Bound":
"""
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
""",
    "Fast Exponentiation":
"""
ll power(ll x, ll y, ll p) {
	ll result = 1;
	for(; y > 0; y >>= 1, x = (x % p * x % p) % p) {
		if(y & 1)
			result = (result % p * x % p) % p;
	}
	return result;
}
""",
    "Fraction":
"""
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
""",
    "Graph":
"""
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
            for(int child: graph[start]) {
                if(!visited[child]) {
                    visited[child] = true;
                    q.push(child);
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
        for(int child: graph[start]) {
            if(!visited[child]) {
                recurse(child, visited, end);
            }
        }
    }

    bool dfs(int start, int end) {
        vector<bool> visited(V, false);
        recurse(start, visited, end);
        return visited[end];
    }
};
""",
    "Next Greater in Right":
"""
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
""",
    "Next Greater in Left":
"""
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
""",
    "Next Smaller in Right":
"""
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
""",
    "Next Smaller in Left":
"""
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
""",
    "Segment Tree":
"""
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
""",
    "Trie":
"""
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
""",
    "Permutations and Combinations, factorials, inverses":
"""
vector<ll> fact;
vector<ll> inv_fact;
vector<ll> inv;

void prepare(int N, ll p) {
    fact.resize(N);
    inv_fact.resize(N);
    inv.resize(N);
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
    inv_fact[N - 1] = power(fact[N - 1], p - 2, p);
    for(int i = N - 2; i >= 0; i--) {
        inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % p;
    }
    inv[0] = 0;
    for(int i = 1; i < N; i++) {
        inv[i] = (fact[i - 1] * inv_fact[i]) % p;
    }
}

ll nCr_mod_p(int n, int r, ll p) {
    return (fact[n] * (inv_fact[r] * inv_fact[n - r]) % p) % p;
}

ll nth_catalan_mod_p(int n, ll p) {
    return (nCr_mod_p(2 * n, n, p) * inv[n + 1]) % p;
}
""",
    "Count Inversions":
"""
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
""",
    "Longest Common Subsequence of Pair of Integer Sequences":
"""
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
""",
    "Longest Common Subsequence of Pair of Strings":
"""
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
""",
    "Matrix Multiplication":
"""
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
""",
    "Fraction Matrix Multiplication":
"""
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
""",
    "Matrix Exponentiation":
"""
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
""",
    "Fraction Matrix Exponentiation":
"""
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
""",
    "Fibonacci":
"""
ll nth_fibonacci(ll n, ll p) {
    auto mul_mat = [](vector<vector<ll>>& a, vector<vector<ll>>& b, vector<vector<ll>>& result, ll p){
        ll res[2][2];
        res[0][0] = ((a[0][0] * b[0][0]) % p + (a[0][1] * b[1][0]) % p) % p;
        res[0][1] = ((a[0][0] * b[0][1]) % p + (a[0][1] * b[1][1]) % p) % p;
        res[1][0] = ((a[1][0] * b[0][0]) % p + (a[1][1] * b[1][0]) % p) % p;
        res[1][1] = ((a[1][0] * b[0][1]) % p + (a[1][1] * b[1][1]) % p) % p;
        result[0][0] = res[0][0];
        result[0][1] = res[0][1];
        result[1][0] = res[1][0];
        result[1][1] = res[1][1];
    };
    vector<vector<ll>> base(2, vector<ll>(2, 1));
    base[1][1] = 0;
    vector<vector<ll>> result(2, vector<ll>(2));
    result[0][0] = result[1][1] = 1;
    for(; n > 0; n >>= 1, mul_mat(base, base, base, p)) {
        if((n&1)) {
            mul_mat(base, result, result, p);
        }
    }
    return result[0][1];
}
""",
    "Prefix Sum":
"""
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
""",
    "Suffix Sum":
"""
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
""",
    "Set Bit Count":
"""
int pop_count(ll n) {
    int c = 0;
    for(; n > 0; c += n % 2, n >>= 1);
    return c;
}
""",
    "Disjoint Set Union":
"""
class DSU {
    public:
    int size = 0;
    vector<int> parent;
    vector<int> weight;

    DSU(int N) {
        size = N + 1;
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
""",
    "Primality Testing":
"""
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
""",
    "Sieve":
"""
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
""",
    "Yarin Sieve":
"""
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
""",
    "Lowest Common Ancestor for multiple queries (LCA)":
"""
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
""",
    "Dijkstra's Single Source shortest path algorithm":
"""
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
""",
    "gp hashing using policy based ds":
"""
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
"""
}