
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

void pre_compute() {
    return;
}

void solve(int test) {
    string s1, s2;
    cin >> s1 >> s2;

    DynamicHash h1(s1), h2(s2);

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