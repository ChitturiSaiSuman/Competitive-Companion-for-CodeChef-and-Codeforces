// 57:69:74:68:20:4C:4F:56:45
//	  _____   _    _   __    __     ____     __    _
//	 / ____| | |  | | |  \  /  |   /    \   |  \  | |
//	 | |___  | |  | | |   \/   |  /   _  \  | . \ | |
//	 \____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
//	 ____| | | \__/ | | |    | | |   __   | | | \ ` |
//	 |_____/ \______/ |_|    |_| |__|  |__| |_|  \__|
//
						
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

#define and							&&
#define or							||
#define not							!
#define is							==
#define abort						assert(false)
#define newInt(nax)					(int *)	malloc(sizeof(int)	* nax)
#define newLong(nax)				(ll *)	malloc(sizeof(ll)	* nax)
#define newString(nax)				(char *)malloc(sizeof(char)	* nax)
#define newline						printf("\n")
#define space						printf(" ")
#define print(a)					printf("%lld", ((ll)a))
#define println(a)					printf("%lld\n", ((ll)a))
#define prints(s)					printf("%s", s)
#define printsln(s)					printf("%s\n", s)
#define scan(a)						scanf("%d", &a)
#define scanll(a)					scanf("%lld", &a)
#define scans(s)					scanf("%s", s)
#define scanLine(s)					scanf("%[^\n]%*c", s);
#define FOR(x,N)					for(int x = 0; x < N; x++)
#define readInt(arr, nax)			FOR(IT, nax) {scan(arr[IT]);}
#define readLL(arr, nax)			FOR(IT, nax) {scanll(arr[IT]);}
#define write(arr, nax)				FOR(IT, nax) {print(arr[IT]);space;}
#define fill(arr, nax, value)		FOR(IT, nax) {arr[IT] = value;}
#define reverse(arr, nax)			FOR(x,nax/2) {arr[x] = arr[nax-x-1];}
#define copy(from, to, nax)			FOR(IT,nax) {to[IT] = from[IT];}
#define getName(var)				#var
#define debug(var)					fprintf(stderr, "%s = %lld\n", getName(var), ((ll)var))
#define inverse(a, p)				power(a, p - 2, p)
#define sort123(arr, nax)			qsort(arr, nax, sizeof(int), ascending)
#define sort321(arr, nax)			qsort(arr, nax, sizeof(int), descending)


typedef unsigned long long int ull;
typedef long long int ll;

const int dc[] = {1, 0, 0, -1, -1, -1, 1, 1};
const int dr[] = {0, 1, -1, 0, -1, 1, -1, 1};

const ll shit	= ((ll)(998244353));	// 998,244,353
const ll mod	= ((ll)(1e9+7));		// 10**9 + 7
const ll hell	= ((ll)(1e9+9));		// 10**9 + 9
const ll inf	= ((ll)(1e18));			// 10 ** 18

const char yes[] = "yes";
const char Yes[] = "Yes";
const char YES[] = "YES";
const char no[] = "no";
const char No[] = "No";
const char NO[] = "NO";

static inline void	swapInt(int *a, int *b)			{int temp=*a;*a=*b;*b=temp;}
static inline void	swapChar(char *a, char *b)		{char c=*a;*a=*b;*b=c;}
static inline void	swapLong(ll *a, ll *b)			{ll temp=*a;*a=*b;*b=temp;}
static inline ll	gcd(ll a, ll b)					{for(ll rem;b>0;rem=a%b,a=b,b=rem);return a;}
static inline ll	lcm(ll a, ll b)					{return (a*b)/(gcd(a,b));}
static inline ll	max(ll a, ll b)					{return (a>b?a:b);}
static inline ll	min(ll a, ll b)					{return (a<b?a:b);}
static inline ll	mul(ll a, ll b, ll p)			{return ((a%p*b%p)%p);}
static inline ll	add(ll a, ll b, ll p)			{return ((a%p+b%p)%p);}
static inline ll	sub(ll a, ll b, ll p)			{return ((a%p-b%p)+p)%p;}

int ascending (const void *a, const void *b)		{return *(int*)a>=*(int*)b?1:-1;}
int descending(const void *a, const void *b)		{return *(int*)b>=*(int*)a?1:-1;}

ll power(ll x, ll y, ll p) {
	ll result = 1;
	for(; y > 0; y >>= 1, x = mul(x, x, p)) {
		if(y & 1)
			result = mul(result, x, p);
	}
	return result;
}

bool isPrime(ll n) {
	if(n == 0 or n == 1)
		return false;
	else if(n == 2 or n == 3)
		return true;
	else if(n % 2 == 0 or n % 3 == 0)
		return false;
	const int root = sqrt(n);
	for(int i = 5; i <= root; i += 6)
		if(n % i == 0 or n % (i + 2) == 0)
			return false;
	return true;
}

typedef struct tuple {
	int val1, val2;
} tuple;

int compare(const void *a, const void *b) {
	tuple *t1 = (tuple *)a;
	tuple *t2 = (tuple *)b;
	int v1 = t1 -> val1;
	int v2 = t2 -> val1;
	return v1 > v2 ? 1 : -1;
}

#define size 2000003 // 2 * 10 ** 6+3
// Use Following lines to declare Global Variables
// 
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
	
	int t = 0;

	// t++;

	if(!t) scan(t);

	preCompute();

	FOR(test, t) {
		// printf("Case #%d: ", test + 1);
		
		solve();
	}
	return 0;
}