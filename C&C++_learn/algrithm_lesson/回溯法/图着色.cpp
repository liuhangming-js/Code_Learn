#include<iostream>
using namespace std;

const int MAXN = 10000;

int n = 5, m;
bool a[6][6] = 
    {{0, 0, 0, 0, 0, 0},
     {0, 0, 1, 0, 1, 1},
     {0, 1, 0, 1, 0, 0},
     {0, 0, 1, 0, 1, 1},
     {0, 1, 0, 1, 0, 1},
     {0, 1, 0, 1, 1, 0}};
int x[MAXN];
long sum;

bool ok(int k) {
    for(int j = 1; j <= n; j++) 
        if (a[k][j] && (x[j] == x[k])) return false;
    return true;
}

void backrack(int t) {
    if(t > n) {
        sum++;
        for (int i = 1; i <= n; i++) cout << x[i] << " ";
        cout << endl;
    }
    else {
        for (int i = 1; i <= m; i++) {
            x[t] = i;
            if (ok(t)) backrack(t + 1);
            x[t] = 0;
        }
    }
}

long mColoring(int mm) {
    m = mm;
    sum = 0;
    backrack(1);
    return sum;
}

int main() {
    mColoring(3);

    return 0;
}
