#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int num, cou = 0;
    char ch;
    vector<int> array;

    while(cin >> num) {
        cou++;
        ch = getchar();
        array.push_back(num);
        if(ch == '\n') break;
    }

    int down[cou], up[cou];

    for(int i = cou - 1; i >= 0; i--) {
        down[i] = 1;
        for(int j = cou - 1; j > i; j--) {
            if(array[j] <= array[i]) down[i] = max(down[i], down[j] + 1);
        }
    }
    cout << *max_element(down, down + cou) << endl;

    for(int i = 0; i < cou; i++) {
        up[i] = 1;
        for(int j = 0; j < i; j++) {
            if(array[j] < array[i]) up[i] = max(up[i], up[j] + 1);
        }
    }
    cout << *max_element(up, up + cou) << endl;

    return 0;
}