
#include <bits/stdc++.h>
using namespace std;

#define FOR(x, N)					for(int x = 0; x < N; x++)
#define inverse(a, p)				power(a, p - 2, p)

typedef unsigned long long int ull;
typedef long long int ll;

const int dc[] = {1, 0, 0, -1, -1, -1, 1, 1};
const int dr[] = {0, 1, -1, 0, -1, 1, -1, 1};

const ll shit	= ((ll)(998244353));
const ll mod	= ((ll)(1e9 + 7));
const ll hell	= ((ll)(1e9 + 9));
const ll inf	= ((ll)(1e18 + 3));

static inline ll gcd(ll a, ll b) {
	for(ll rem; b > 0; rem = a % b, a = b, b = rem);
	return a;
}
static inline ll lcm(ll a, ll b) {
	return (a * b) / gcd(a, b);
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