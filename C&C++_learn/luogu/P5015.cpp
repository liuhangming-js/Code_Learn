#include<iostream>
#include<string>
using namespace std;
int main() {
    string s;
    int cou = 0;
    while(cin >> s) {
        cou += s.length();
    }

    cout << cou;

    return 0;
}