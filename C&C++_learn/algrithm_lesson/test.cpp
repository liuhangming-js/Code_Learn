#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class demo {
    public:
        int a;
        int b;
};

bool com(demo x, demo y) {
    if(x.a == y.a)
        return x.b < y.b;
    return x.a < y.a;
}

int main() {
    vector<demo> arr = {{1, 2}, {5, 3}, {2, 4}, {3, 8}};
    sort(arr.begin(), arr.end(), com);
    for(int i = 0; i < arr.size(); i++) cout << arr[i].a << " " << arr[i].b << endl;
    return 0;
}