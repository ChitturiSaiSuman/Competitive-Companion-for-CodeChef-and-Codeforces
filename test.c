
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned long long int ull;
typedef long long int ll;

const int dc[] = {1, 0, 0, -1, -1, -1, 1, 1};
const int dr[] = {0, 1, -1, 0, -1, 1, -1, 1};

const ll shit	= ((ll)(998244353));
const ll mod	= ((ll)(1e9 + 7));
const ll hell	= ((ll)(1e9 + 9));
const ll inf	= ((ll)(1e18 + 3));

static inline ll	gcd(ll a, ll b)					{for(ll rem;b>0;rem=a%b,a=b,b=rem);return a;}
static inline ll	lcm(ll a, ll b)					{return (a*b)/(gcd(a,b));}
static inline ll	max(ll a, ll b)					{return (a>b?a:b);}
static inline ll	min(ll a, ll b)					{return (a<b?a:b);}
static inline ll	mul(ll a, ll b, ll p)			{return ((a%p*b%p)%p);}
static inline ll	add(ll a, ll b, ll p)			{return ((a%p+b%p)%p+p)%p;}
static inline ll	sub(ll a, ll b, ll p)			{return ((a%p-b%p)+p)%p;}

ll power(ll x, ll y, ll p) {
	ll result = 1;
	for(; y > 0; y >>= 1, x = mul(x, x, p)) {
		if(y & 1)
			result = mul(result, x, p);
	}
	return result;
}

#define size 2000003


void preCompute() {
	return;
}

void solve() {
	return;
}

int main() {
	int t = 0;
	// t++;
	if(!t) scanf("%d", &t);
	preCompute();
	for(int test = 0; test < t; test++) {
		// printf("Case #%d: ", test + 1);		
		solve();
	}
	return 0;
}