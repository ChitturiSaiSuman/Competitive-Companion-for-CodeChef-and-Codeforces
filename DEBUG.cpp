#include "DEBUG.h"
#include <bits/stdc++.h>

using namespace std;

void debug(const long long N) {
    cerr << N << '\n';
}

void debug(const unsigned long long N) {
    cerr << N << '\n';
}

void debug(const float N) {
    cerr << N << '\n';
}

void debug(const long double N) {
    cerr << N << '\n';
}

void debug(const double N) {
    cerr << N << '\n';
}

void debug(const string& s) {
    cerr << s << '\n';
}

void debug(const pair<int, int>& x) {
    cerr << '(' << x.first << ", " << x.second << ')' << '\n';
}

void debug(const pair<char, int>& x) {
    cerr << '(' << x.first << ", " << x.second << ')' << '\n';
}

void debug(const vector<int>& arr) {
    const int N = arr.size();
    if(N == 0) {
        cerr << "[]\n";
    }
    else if(N == 1) {
        cerr << "[" << arr[0] << "]\n";
    }
    else {
        cerr << "[" << arr[0];
        for(int i = 1; i < N; i++) {
            cerr << ", " << arr[i];
        }
        cerr << "]\n";
    }
}

void debug(const vector<vector<int>>& arr) {
    const int N = arr.size();
    if(N == 0) {
        cerr << "[]\n";
    }
    else if(N == 1) {
        cerr << "[\n";
        debug(arr[0]);
        cerr << "]\n";
    }
    else {
        cerr << "[\n";
        for(int i = 0; i < N; i++) {
            debug(arr[i]);
        }
        cerr << "]\n";
    }
}

void debug(const vector<pair<int, int>>& arr) {
    const int N = arr.size();
    if(N == 0) {
        cerr << "[]\n";
    }
    else if(N == 1) {
        cerr << "[" << arr[0].first << ", " << arr[0].second << "]\n";
    }
    else {
        cerr << "[" << arr[0].first << ", " << arr[0].second;
        for(int i = 1; i < N; i++) {
            cerr << ", " << arr[i].first << ", " << arr[i].second;
        }
        cerr << "]\n";
    }
}