#include <iostream>
using namespace std;
int main()
{
    int n1 = 0, n2 = 1, n, N;
    cout << "Give me the N:" << endl;
    cin >> N;
    if (N == 1)
        cout << n1;
    else if (N == 2)
        cout << n1 << " " << n2;
    else
    {
        cout << n1 << " " << n2 << " ";
        for (int i = 1; i <= N - 2; i++)
        {
            n = n1 + n2;
            n1 = n2;
            n2 = n;
            cout << n;
            if (i != N - 2)
                cout << " ";
        }
    }
    return 0;
}