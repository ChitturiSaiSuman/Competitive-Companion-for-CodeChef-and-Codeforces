#include <iostream>

using namespace std;

int main() {
    int arr[100000] = {0};
    for (int i = 0; i < 1e5; i++) {
        arr[i] = i;
    }
    int N = 1e4;
    cout << arr[N] << '\n';
    return 0;
}