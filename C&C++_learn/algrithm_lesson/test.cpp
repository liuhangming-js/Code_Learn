#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class box {
    public:
        double length;
        double height;
        double width;

        double get() {
            return length * width * height;
        };
        void set(double len, double wid, double hei) {
            length = len;
            width = wid;
            height = hei;
        }
};

int main() {
    box b1, b2, b3;
    b1.set(30, 20, 10);
    b2.set(20, 30, 40);
    b3.set(10, 40, 50);

    vector<box> br;
    sort(br.begin(), br.end());

    for(int i = 0; i < br.size(); i++) {
        cout << br[i].length << br[i].width << br[i].height << endl;
    }

    return 0;
}