#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
    vector<int> arr = {0, 4, 2, 6, 7};
    int brr[] = {2, 4, 5, 1, 2};
    cout << "MAX Value:" << *max_element(arr.begin(), arr.end()) << endl;
    cout << "MAX Value:" << *max_element(brr, brr + (sizeof(brr) / sizeof(int))) << endl;
}