#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    double n;
    cin >> n;
    int array[3];
    for(int i = 0; i < 3; i++) {
        double x;
        int y;
        cin >> x >> y;
        if(x >= n) array[i] = y;
        else array[i] = (int)(ceil(n/x)) * y;
    }
    sort(array, array + 3);
    cout << array[0] << endl;

    return 0;
}