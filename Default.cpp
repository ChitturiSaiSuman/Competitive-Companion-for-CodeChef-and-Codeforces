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
#define getName(var)				#var
#define debug(var)					cerr << getName(var) << " = " << var << "\n"
#define abort						assert(false)
#define read(arr, nax)				FOR(IT, nax)	{cin >> arr[IT];}
#define write(arr, nax)				FOR(IT, nax)	{cout << arr[IT] << " ";}
#define fill(arr, nax, value)		FOR(IT, nax)	{arr[IT] = value;}
#define reverse(arr, nax)			FOR(x,nax/2) {arr[x] = (arr[nax-x-1] + arr[x]) - (arr[nax - x - 1] = arr[x]);}
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

#define nax 2000003 // 2e6 + 3
// Use Following lines to declare Global Variables
// 


void preCompute() {
	// Precompute stuff
	// 
}

void solve() {
	// Solve test cases here
	// 
}

int main() {

    ios_base::sync_with_stdio(false), cin.tie(NULL);
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