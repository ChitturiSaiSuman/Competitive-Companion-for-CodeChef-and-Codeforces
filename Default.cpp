/*
Linkedin: https://www.linkedin.com/in/sai-suman-chitturi-9727a2196/
Hackerrank: https://www.hackerrank.com/skynetasspyder?hr_r=1
Codechef: https://www.codechef.com/users/suman_18733097
Codeforces: http://codeforces.com/profile/saisumanchitturi
Github: https://github.com/ChitturiSaiSuman
Hackerearth: https://www.hackerearth.com/@chitturi7
SPOJ: Sai Suman Chitturi @out_of_bound
*/

//	  _____   _    _   __    __     ____     __    _
//	 / ____| | |  | | |  \  /  |   /    \   |  \  | |
//	 | |___  | |  | | |   \/   |  /   _  \  | . \ | |
//	 \____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
//	 ____| | | \__/ | | |    | | |   __   | | | \ ` |
//	 |_____/ \______/ |_|    |_| |__|  |__| |_|  \__|
//

#include <bits/stdc++.h>
using namespace std;

#define newline 				    cout << "\n"
#define space					    cout << " "
#define endl					    cout << "\n"
#define iter(x, a, b) 			    for(int x = a; x <= b; x++)
#define range(start, stop, step)    for(int it = start; it < stop; it += step)
#define FOR(x, N) 				    for(int x = 0; x < N; x++)
#define For(x, N) 				    for(int x = 0; x < N; x++)
#define caseprint                   cout << "Case #" << d << ": "
#define inverse(a, p) 			    power(a, p-2, p)
#define scan(a) 				    cin >> a
#define print(a) 				    cout << a
#define println(a)                  cout << a << "\n";
#define getName(var)			    #var
#define debug(var)                  cerr << getName(var) << " = " << var << "\n"
#define abort					    assert(false)
#define read(arr, nax)              FOR(IT, nax) {cin >> arr[IT];}
#define write(arr, nax)             FOR(IT, nax) {cout << arr[IT] << " ";}
#define fill(arr,nax,value)		    FOR(IT,nax) {arr[IT] = value;}
#define sort123(arr,nax)		    qsort(arr,nax,sizeof(int),ascending)
#define sort321(arr,nax)		    qsort(arr,nax,sizeof(int),descending)
#define reverse(arr,nax)		    FOR(x,nax/2) {arr[x]=arr[nax-x-1];}
#define newInt(nax)				    (int*)malloc(sizeof(int)*nax)
#define newLong(nax)			    (ll *)malloc(sizeof(ll)*nax)
#define copy(from,to,nax)           FOR(IT,nax) {to[IT] = from[IT];}

typedef unsigned long long int ull;
typedef long long int ll;

const ll shit = ((ll)(998244353)); // 998,244,353
const ll mod = ((ll)(1e9+7)); // 10**9+7
const ll hell = ((ll)(1e9+9)); // 10**9+9
const ll inf = ((ll)(1e18)); // 10**18

const char yes[] = "yes";
const char Yes[] = "Yes";
const char YES[] = "YES";
const char no[] = "no";
const char No[] = "No";
const char NO[] = "NO";

static inline int setBitCount(ll n)				{int ans=0;for(;n>0;ans+=(n&1),n>>=1);return ans;}
static inline ll gcd(ll a, ll b) 				{for(ll rem;b>0;rem=a%b,a=b,b=rem);return a;}
static inline ll lcm(ll a, ll b) 				{return (a*b)/(gcd(a,b));}
static inline ll max(ll a, ll b) 				{return (a>b?a:b);}
static inline ll min(ll a, ll b) 				{return (a<b?a:b);}
static inline ll mul(ll a, ll b, ll p) 			{return ((a%p*b%p)%p);}
static inline ll add(ll a, ll b, ll p) 			{return ((a%p+b%p)%p);}
static inline ll sub(ll a, ll b, ll p) 			{return ((a%p-b%p)+p)%p;}
static inline int sumOfDigits(ll n) 			{return n>0?n%10+sumOfDigits(n/10):0;}
static inline int numberOfDigits(ll n)			{return n>0?1+numberOfDigits(n/10):0;}
static inline void LLFraction(ll *a, ll *b) 	{ll g = gcd(*a,*b); (*a)/=g; (*b)/=g;}
static inline void IntFraction(int *a, int *b)	{int g = gcd(*a,*b); (*a)/=g; (*b)/=g;}

ll power(ll x, ll y, ll p) {
	ll result=1;
	for(;y>0;y>>=1,x=mul(x,x,p)) {
		if(y&1)
			result = mul(result,x,p);
	}
	return result;
}

bool isPrime(ll n) {
	if(n==0 or n==1)
		return false;
	else if(n==2 or n==3)
		return true;
	else if(n%2==0 or n%3==0)
		return false;
	for(int i=5;i<=sqrt(n);i+=6)
		if(n%i==0 or n%(i+2)==0)
			return false;
	return true;
}

void preCompute() {

    return;
}

void solve() {

    return;
}

int main() {

    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 0;
	if(!t) scan(t);
	preCompute();
	For(test, t) {
		// caseprint;
		solve();
	}
	return 0;
}

vector<bool> sieve(int size) {
    vector<bool> prime(size, false);
    prime[2] = true;
    for(int i = 3; i < size; i++) {
        prime[i] = true;
    }

    for(int i = 3; i*i < size; i += 2) {
        if(prime[i]) {
            for(int j = i*i; j < size; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}