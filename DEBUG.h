#include <bits/stdc++.h>
using namespace std;

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