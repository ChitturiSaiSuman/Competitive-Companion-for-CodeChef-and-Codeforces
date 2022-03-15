#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

template<typename T> ostream& operator<<(ostream& os, const vector<T> &v) {
	os << '[';
	for(auto it = v.begin(); it != v.end(); ++it) {
		if(it != v.begin()) os << ", ";
		os << *it;
	}
	return os << ']';
}

template<typename T1, typename T2> ostream& operator<<(ostream& os, const map<T1, T2> &m) {
	os << '{';
	for(auto it = m.begin(); it != m.end(); ++it) {
		if(it != m.begin()) os << ", ";
		os << it->first << ": " << it->second;
	}
	return os << '}';
}

template<typename T> ostream& operator<<(ostream& os, const set<T> my_set) {
	os << '{';
	for(auto it = my_set.begin(); it != my_set.end(); ++it) {
		if(it != my_set.begin()) os << ", ";
		os << *it;
	}
	return os << '}';
}

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) {
	os << '['; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << ']';
}

void debug() { cerr << '\n'; }

template<typename Head, typename... Tail> void debug(Head H, Tail... T) {
	cerr << ' ' << H; debug(T...);
}