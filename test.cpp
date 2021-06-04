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
#include <algorithm>
using namespace std;

#define FOR(x, N)					for(int x = 0; x < N; x++)
#define inverse(a, p)				power(a, p - 2, p)
#define SORT123(v)					sort(v.begin(), v.end())
#define SORT321(v)					sort(v.begin(), v.end(), greater<int>())

typedef unsigned long long int ull;
typedef long long int ll;

const int dc[] = {1, 0, 0, -1, -1, -1, 1, 1};
const int dr[] = {0, 1, -1, 0, -1, 1, -1, 1};

const ll shit	= ((ll)(998244353));	// 998,244,353
const ll mod	= ((ll)(1e9 + 7));		// 10**9 + 7
const ll hell	= ((ll)(1e9 + 9));		// 10**9 + 9
const ll inf	= ((ll)(1e18 + 3));		// 10 ** 18 + 3

static inline ll gcd(ll a, ll b) {
	for(ll rem; b > 0; rem = a % b, a = b, b = rem);
	return a;
}
static inline ll lcm(ll a, ll b) {
	return (a * b) / gcd(a, b);
}
static inline ll mul(ll a, ll b, ll p) {
	return ((a % p * b % p) % p + p) % p;
}
static inline ll add(ll a, ll b, ll p) {
	return ((a % p + b % p) % p + p) % p;
}
static inline ll sub(ll a, ll b, ll p) {
	return ((a % p - b % p) + p) % p;
}
static inline ll SUM(ll a, ll b) {
	return a + b;
}
static inline ll AND(ll a, ll b) {
	return a & b;
}
static inline ll XOR(ll a, ll b) {
	return a ^ b;
}
static inline ll OR(ll a, ll b) {
	return a | b;
}

#define nax 2000003


void preCompute() {
	// 
}

void solve() {
	// 
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 0;
	// t++;
	if(!t) cin >> t;
	preCompute();
	FOR(test, t) {
		// cout << "Case #" << (test + 1) << ": ";
		solve();
	}
	return 0;
}