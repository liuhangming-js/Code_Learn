#include<iostream>
using namespace std;
int main() {
    int n, sum = 0;
    cin >> n;
    int array[n+1] = {0};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i / 2; j++) {
            array[i] += array[j];
        }
        array[i]++;
    }
    cout << array[n];

    return 0;
}