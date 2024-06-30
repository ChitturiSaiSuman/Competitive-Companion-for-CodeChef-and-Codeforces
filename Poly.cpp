
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <boost/multiprecision/cpp_int.hpp>

using namespace std;
// using namespace __gnu_pbds;
// using namespace boost::multiprecision;

#ifdef SUMAN
#include "DEBUG.h"
#define LINE        cerr << "line " << __LINE__ << ": ";
#define debug(x)    LINE; cerr << "(" << #x << ")"; debug(x)
#else
#define debug(x)
#endif

#define FOR(x, N)    for(int x = 0; x < N; x++)
#define endl         '\n'

typedef unsigned long long int ull;
typedef long long int ll;

const short int dc[] = {1, 0, 0, -1, -1, -1, 1, 1};
const short int dr[] = {0, 1, -1, 0, -1, 1, -1, 1};

const ll shit    = ((ll)(998244353));
const ll mod     = ((ll)(1e9 + 7));
const ll hell    = ((ll)(1e9 + 9));
const ll inf     = ((ll)(1e18 + 3));

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

class FenwickTree {
public:
    vector<ll> bit;
    int tree_size, modulo;

    FenwickTree() {}

    FenwickTree(int n, int m) {
        tree_size = n + 5;
        bit.assign(tree_size, 0);
        modulo = m;
    }

    FenwickTree(vector<int> const &a, int m): FenwickTree(a.size(), m) {
        for (int i = 0; i < (int)a.size(); i++) {
            add(i, a[i]);
        }
    }

    void add(int idx, int val) {
        for (++idx; idx <= tree_size; idx += idx & -idx) {
            bit[idx] += val;
            bit[idx] %= modulo;
        }
    }

    void range_update(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    ll get(int index) const {
        if (index == 0) {
            return bit[index];
        }
        ll ret = 0;
        for (++index; index > 0; index -= index & -index) {
            ret += bit[index];
            ret %= modulo;
        }
        return ret;
    }

    ll point_query(int idx) const {
        if (idx == 0) {
            return get(idx);
        }
        ll ret = get(idx) - get(idx -  1);
        ret += modulo;
        ret %= modulo;
        return ret;
    }
};

class SegmentTree {
public:
    vector<ll> tree;
    int tree_size;
    ll modulo;

    SegmentTree() {}

    SegmentTree(vector<int>& a, ll p) {
        modulo = p;
        int N = a.size();
        int M = N;
        if ((N & (N - 1)) != 0) {
            N = 1 << (32 - __builtin_clz(N));
        }
        tree_size = N;
        tree.resize(2 * tree_size);
        for (int i = 0; i < M; i++) {
            tree[i + N] = a[i];
        }
        debug(tree);
    }

    void update(int node, int node_lb, int node_ub, int lb, int ub, ll value) {
        if (node_ub < lb || ub < node_lb) {
            return;
        } else if (lb <= node_lb && node_ub <= ub) {
            tree[node] = (tree[node] + value) % modulo;
        } else {
            int mid = (node_lb + node_ub) / 2;
            update(2 * node, node_lb, mid, lb, ub, value);
            update(2 * node + 1, mid + 1, node_ub, lb, ub, value);
        }
    }

    void update(int l, int r, ll value) {
        update(1, tree_size, 2 * tree_size - 1, l + tree_size, r + tree_size, value);
        debug(tree);
    }

    ll query(int index) const {
        ll ans = 0;
        index += tree_size;
        while (index > 0) {
            ans = (ans + tree[index]) % modulo;
            index >>= 1;
        }
        return ans;
    }
};

class Hash {
private:
    int length;
    const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    const int p1 = 31, p2 = 37;
    const int inv_p1 = inverse(p1, mod1), inv_p2 = inverse(p2, mod2);
    vector<int> hash1, hash2;
    pair<int, int> hash_pair;
    FenwickTree tree1, tree2;

public:

    inline static vector<ll> p_pow1 = vector<ll>(1, 1);
    inline static vector<ll> p_pow2 = vector<ll>(1, 1);

    inline static vector<int> inv_pow1 = vector<int>(1, 1);
    inline static vector<int> inv_pow2 = vector<int>(1, 1);
    inline static int inv_size = 1;

    Hash(const string& s) {
        length = s.size();
        hash1.resize(length);
        hash2.resize(length);

        for (; inv_size < length; inv_size++) {
            p_pow1.push_back((p_pow1.back() * 1LL * p1) % mod1);
            p_pow2.push_back((p_pow2.back() * 1LL * p2) % mod2);
            inv_pow1.push_back((inv_pow1.back() * 1LL * inv_p1) % mod1);
            inv_pow2.push_back((inv_pow2.back() * 1LL * inv_p2) % mod2);
        }

        int h1 = 0, h2 = 0;

        for (int i = 0; i < length; i++) {
            h1 = (h1 + (s[i] - 'a' + 1) * p_pow1[i]) % mod1;
            h2 = (h2 + (s[i] - 'a' + 1) * p_pow2[i]) % mod2;
            hash1[i] = h1;
            hash2[i] = h2;
        }
        hash_pair = make_pair(h1, h2);

        tree1 = FenwickTree(hash1, mod1);
        tree2 = FenwickTree(hash2, mod2);
    }

    int size() {
        return length;
    }

    pair<ll, ll> prefix(const int index) const {
        return {tree1.point_query(index), tree2.point_query(index)};
    }

    pair<int, int> substr(const int l, const int r) {
        if(l == 0) {
            return prefix(r);
        }
        auto p_r = prefix(r), p_l = prefix(l - 1);
        ll temp1 = p_r.first - p_l.first;
        ll temp2 = p_r.second - p_l.second;

        temp1 += (temp1 < 0 ? mod1 : 0);
        temp2 += (temp2 < 0 ? mod2 : 0);

        temp1 = (temp1 * 1LL * inv_pow1[l]) % mod1;
        temp2 = (temp2 * 1LL * inv_pow2[l]) % mod2;
        return {temp1, temp2};
    }

    void update(const int index, const char source, const char target) {
        if (source == target) {
            return;
        }

        ll d1 = (target - source + mod1) % mod1;
        d1 = (d1 * 1LL * p_pow1[index]) % mod1;

        ll d2 = (target - source + mod2) % mod2;
        d2 = (d2 * 1LL * p_pow2[index]) % mod2;

        tree1.range_update(index, length - 1, d1);
        tree2.range_update(index, length - 1, d2);

        // tree1.update(index, length - 1, d1);
        // tree2.update(index, length - 1, d2);
    }

    bool operator==(const Hash& other) {
        return prefix(length - 1) == other.prefix(other.length - 1);
    }
};

void pre_compute() {
    return;
}

void solve(int test) {
    string s1, s2;
    cin >> s1 >> s2;

    Hash h1(s1), h2(s2);

    debug(h1.prefix(s1.length() - 1)); debug(h2.prefix(s2.length()));

    int ops = 0;
    cin >> ops;

    for (int op = 0; op < ops; op++) {
        int index; char ch; string s;
        cin >> index >> ch >> s;

        string prev1 = s1, prev2 = s2;

        h1.update(index, s1[index], ch);
        s1[index] = ch;

        if (s1 != s) {
            cout << "Something is fishy. Failed Test: " << (op + 1) << '\n';
        }

        if ((s1 == s2) != (h1 == h2)) {
            cout << "Test: " << (test + 1) << '\n';
            cout << "Failed Test: " << (op + 1) << '\n';
            cout << "Previous: " << prev1 << ", " << prev2 << '\n';
            cout << "Index and Value: " << index << ", " << ch << '\n';
            auto p1 = h1.prefix(s1.length() - 1), p2 = h2.prefix(s2.length() - 1);
            cout << "Hashes: " << "(" << p1.first << ", " << p1.second << "), (" << p2.first << ", " << p2.second << ")" << '\n';
            break;
        } else {
            Hash temp(s1);
            if (!(temp == h1)) {
                cout << "Test: " << (test + 1) << '\n';
                cout << "Failed Test: " << (op + 1) << '\n';
                cout << "Previous: " << prev1 << ", " << prev2 << '\n';
                cout << "Index and Value: " << index << ", " << ch << '\n';
                auto p1 = h1.prefix(s1.length() - 1), p2 = temp.prefix(s1.length() - 1);
                cout << "Hashes: " << "(" << p1.first << ", " << p1.second << "), (" << p2.first << ", " << p2.second << ")" << '\n';
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    pre_compute();
    FOR(test, t) {
        // cout << "Case #" << (test + 1) << ": ";
        solve(test);
        #ifdef SUMAN
        cerr << '\n';
        #endif
    }
    return 0;
}