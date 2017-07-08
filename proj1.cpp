#include <iostream>

using namespace std;
int n, k;
int main(int argc, char* argv[]) {
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string res = "";
    for (int j = 0; j < k; ++j) {
        int buff;
        cin >> buff;
        cout << BinarySearch(0, n - 1, buff, a) << "\n";
    }
    cout << res;
}