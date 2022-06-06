#include <iostream>
using namespace std;
int a[5][5] =
    {{0, 1, 0, 1, 1},
     {1, 0, 1, 0, 0},
     {0, 1, 0, 1, 1},
     {1, 0, 1, 0, 1},
     {1, 0, 1, 1, 0}};
// int a[5][5] =
//     {{0, 0, 0, 0, 1},
//      {0, 0, 0, 0, 0},
//      {0, 0, 0, 0, 0},
//      {0, 0, 0, 0, 1},
//      {1, 0, 0, 0, 0}};
int n, m, g, i;
void next(int k, int *x);
void backtrack(int k, int *x);
void backtrack(int *x);
bool flag = false;

void next(int k, int *x) {
    int j;
    do {
        x[k] = (x[k] + 1) % n;
        if (!x[k]) return;
        if (a[x[k - 1]][x[k]]) {
            for (j = 0; j < k; j++)
                if (x[j] == x[k]) break;
            if (j == k)
                if ((k < n - 1) || (k == n - 1) && a[x[n - 1]][x[0]]) return;
        }
    } while (1);
}
void backtrack(int k, int *x) {
    do {
        next(k, x);
        if (!x[k]) return;
        if (k == n - 1) {
            flag = true;
            for (int i = 0; i < n; i++) cout << x[i] + 1 << ' ';
            cout << 1 << endl; //1开始1结束
        }
        else
            backtrack(k + 1, x);
    } while (1);
}
void backtrack(int *x) {
    backtrack(1, x);
}

int main() {
    n = 5;

    int *x = new int[10000];
    int u, v;
    for (i = 0; i < n; i++) x[i] = 0;
    backtrack(x);
    if(!flag) cout << "There is no answer" << endl;

    return 0;
}
