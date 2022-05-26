#include <iostream>
using namespace std;

void traceback(int t, int n, int x[]) {
    if (t > n) {
        for (int i = 0; i <= n; i++) {
            cout << x[i];
        }
        cout << endl;
    }
    else
        for (int i = t; i <= n; i++) {
            swap(x[t], x[i]);
            traceback(t + 1, n, x);
            swap(x[t], x[i]);
        }
}

int main()
{
    int n = 3;
    int x[] = {1, 2, 3, 4};
    traceback(0, n, x);

    return 0;
}