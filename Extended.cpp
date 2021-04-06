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
using namespace std;

#define nl							"\n"
#define sp							" "
#define iter(x, a, b) 			    for(int x = a; x <= b; x++)
#define range(start, stop, step)    for(int it = start; it < stop; it += step)
#define FOR(x, N) 				    for(int x = 0; x < N; x++)
#define For(x, N) 				    for(int x = 0; x < N; x++)
#define caseprint                   cout << "Case #" << (test + 1) << ": "
#define inverse(a, p) 			    power(a, p - 2, p)
#define getName(var)			    #var
#define debug(var)                  cerr << getName(var) << " = " << var << "\n"
#define abort					    assert(false)
#define read(arr, nax)              FOR(IT, nax) {cin >> arr[IT];}
#define write(arr, nax)             FOR(IT, nax) {cout << arr[IT] << " ";}
#define fill(arr,nax,value)		    FOR(IT,nax) {arr[IT] = value;}
#define reverse(arr,nax)		    FOR(x,nax/2) {arr[x]=arr[nax-x-1];}
#define SORT123(v)					sort(v.begin(), v.end())
#define SORT321(v)					sort(v.begin(), v.end(), greater<int>())

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

ll power(ll x, ll y, ll p) {
	ll result = 1;
	for(; y > 0; y >>= 1, x = mul(x, x, p)) {
		if(y&1)
			result = mul(result, x, p);
	}
	return result;
}

bool isPrime(ll n) {
	if(n == 0 || n == 1)
		return false;
	else if(n == 2 || n == 3)
		return true;
	else if(n % 2 == 0 || n % 3 == 0)
		return false;
	for(int i = 5; i <= sqrt(n); i += 6)
		if(n % i == 0 || n % (i + 2)== 0)
			return false;
	return true;
}

// Fraction template for CPP

class Fraction {
	public:
	ll num = 0, den = 1;
	ll gcd(ll a, ll b) {for(ll rem;b>0;rem=a%b,a=b,b=rem); return a;}
	ll lcm(ll a, ll b) {return (a * b) / gcd(a, b);}
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
			throw invalid_argument("Non-Zero denominator is expected");
		}
		num = n;
		den = d;
		ll g = gcd(num, den);
		num /= g;
		den /= g;
	};
	Fraction operator + (Fraction const &frac) {
		ll l = lcm(den, frac.den);
		ll a = num * (l / den);
		ll b = frac.num * (l / frac.den);
		return Fraction(a+b, l);
	}
	Fraction operator - (Fraction const &frac) {
		ll l = lcm(den, frac.den);
		ll a = num * (l / den);
		ll b = frac.num * (l / frac.den);
		return Fraction(a - b, l);
	}
	Fraction operator * (Fraction const &frac) {
		return Fraction(num * frac.num, den * frac.den);
	}
	Fraction operator / (Fraction const &frac) {
		return Fraction(num * frac.den, den * frac.num);
	}
	operator string() const {
		if(den == 1)
			return to_string(num);
		return to_string(num) + "/" + to_string(den);
	}
};

ostream& operator << (ostream& out, const Fraction &f) {
	if(f.den == 1)
		return out << to_string(f.num);
	return out << to_string(f.num) + "/" + to_string(f.den);
}

// End of Fraction template for CPP

// Sieve for Prime Generation

vector<bool> sieve(int nax) {
    vector<bool> prime(nax, false);
    prime[2] = true;
    for(int i = 3; i < nax; i += 2) {
        prime[i] = true;
    }

    for(int i = 3; i * i < nax; i += 2) {
        if(prime[i]) {
            for(int j = i * i; j < nax; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

// End of Sieve for Prime Generation


class Graph {
    public:
    int V = 0;
    int E = 0;
    vector<vector<int>> graph;
    Graph(int v, int e) {
        V = v + 1;
        E = e;
        FOR(i, V) {
            graph.push_back(vector<int>());
        }
    }

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        // graph[b].push_back(a);
    }

    bool bfs(int start, int end) {
        vector<bool> visited(V, false);
        visited[true] = true;
        queue<int> q;
        q.push(start);
        while (!q.empty() && !visited[end]) {
            start = q.front();
            q.pop();
            for(int i: graph[start]) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.push(i);
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
        for(int i: graph[start]) {
            if(!visited[i]) {
                recurse(i, visited, end);
            }
        }
    }

    bool dfs(int start, int end) {
        vector<bool> visited(V, false);
        recurse(start, visited, end);
        return visited[end];
    }
};


vector<int> nextGreaterInRight(vector<int> a, int n) {
	vector<int> right_index(n, n);
	stack<int> st;
	for(int i = 0; i < n; i++) {
		while(!st.empty() && a[i] > a[st.top()]) {
			int r = st.top();
			st.pop();
			right_index[r] = i;
		}
		st.push(i);
	}
	return right_index;
}

vector<int> nextGreaterInLeft(vector<int> a, int n) {
	vector<int> left_index(n, -1);
	stack<int> st;
	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && a[i] > a[st.top()]) {
			int r = st.top();
			st.pop();
			left_index[r] = i;
		}
		st.push(i);
	}
	return left_index;
}

vector<int> nextSmallerInRight(vector<int> a, int n) {
	vector<int> right_index(n, n);
	stack<int> st;
	for(int i = 0; i < n; i++) {
		while(!st.empty() && a[i] < a[st.top()]) {
			int r = st.top();
			st.pop();
			right_index[r] = i;
		}
		st.push(i);
	}
	return right_index;
}

vector<int> nextSmallerInLeft(vector<int> a, int n) {
	vector<int> left_index(n, -1);
	stack<int> st;
	for(int i = n - 1; i >= 0; i--) {
		while (!st.empty() && a[i] < a[st.top()]) {
			int r = st.top();
			st.pop();
			left_index[r] = i;
		}
		st.push(i);
	}
	return left_index;
}