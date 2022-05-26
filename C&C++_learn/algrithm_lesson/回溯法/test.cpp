#include<iostream>
using namespace std;

void backtrack(int t, int n, int x[3]) {
	if (t > n) {
		for (int i = 0; i <= n; i++) {
            cout << x[i];
		}
        cout << endl;
	}
    else{
        for (int i = 1; i >= 0; i--) {
			x[t] = i;
			backtrack(t + 1, n, x);
		}
    }	
}

int main() {
    int n = 2;
    int x[3];
	backtrack(0, n, x);
    return 0;
}