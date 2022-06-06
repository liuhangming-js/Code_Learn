#include <iostream>
using namespace std;

int x[9] = {0};
int sum = 0;

bool judge(int q) {
    for (int i = 1; i < q; i++) {
        if (x[i] == x[q] || abs(i - q) == abs(x[i] - x[q])) return false;
    }
    return true;
}

void queen() {
    int n = 8;
    int i, k = 1; //k是行号
    x[1] = 0;
    while (k > 0) {
        x[k]++;
        while (x[k] <= n && !judge(k)) x[k]++;
        if (x[k] <= n) {
            if(k == n) {
                for(i = 1; i <= n; i++) cout << "queen " << i << "in " << "line " << i << "col " << x[i] << endl;
                sum++;
            }
            else {
                k++;
                x[k] = 0;
            }
        }
        else k--;
    }
    
}

int main() {
    queen();
    cout << "sum: " << sum;
    return 0;
}