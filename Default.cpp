
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <boost/multiprecision/cpp_int.hpp>

using namespace std;
// using namespace __gnu_pbds;
// using namespace boost::multiprecision;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
	return os << '(' << p.first << ", " << p.second << ')'; 
}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) {
	os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}';
}
void debug() { cerr << '\n'; }
template<typename Head, typename... Tail> void debug(Head H, Tail... T) {
	cerr << ' ' << H; debug(T...);
}

#ifdef SUMAN
#define debug(...) cerr << #__VA_ARGS__ << ":", debug(__VA_ARGS__)
#else
#define debug(...)
#endif

#define FOR(x, N)			for(int x = 0; x < N; x++)
#define inverse(a, p)		power(a, p - 2, p)
#define endl				'\n'

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
static inline ll power(ll a, ll b, ll p) {
	ll result = 1;
	for(; b > 0; b >>= 1, (a = a * a % p)) {
		if(b & 1) {
			result = result * a % p;
		}
	}
	return result;
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
    int t = 1;
	cin >> t;
	pre_compute();
	FOR(test, t) {
		// cout << "Case #" << (test + 1) << ": ";
		solve();
	}
	return 0;
}