#include <iostream>
using namespace std;

void perm(int list[], int k, int m) {
    if(k == m) {
        for(int i = 0; i <= m; i++) cout << list[i];
        cout << endl;
    }
    else {
        for(int i = k; i <= m; i++) {
            swap(list[k], list[i]);
            perm(list, k + 1, m);
            swap(list[k], list[i]);
        }
    }
}

int main() {
    int list[] = {4,3,2,1};
    perm(list, 0, 3);

    return 0;
}
