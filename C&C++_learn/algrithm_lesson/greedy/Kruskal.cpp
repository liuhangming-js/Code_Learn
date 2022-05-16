#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class FastUnionFind {
    public:
        int a[11];
        FastUnionFind(int n) {
            for(int i = 0; i <= n; i++) a[i] = i;
        }
        int Find(int x) {
            if(a[x] == x) return x;
            else return Find(a[x]);
        }
        void Union(int x, int y) {
            a[Find(y)] = a[Find(x)];
        }
};

class bian {
    public:
        int node1;
        int node2;
        float weight;
};

bool com(bian a, bian b) {
    return a.weight < b.weight;
}

int main() {
    int biannum = 10;
    bian bianlist[10] = {
        {1, 2, 6},
        {1, 3, 1},
        {1, 4, 5},
        {2, 3, 5},
        {2, 5, 3},
        {3, 4, 5},
        {3, 5, 6},
        {3, 6, 4},
        {4, 6, 2},
        {5, 6, 6}
    };
    vector<bian> selected;
    FastUnionFind UnionList(biannum);
    sort(bianlist, bianlist+10, com);
    for(int i = 0; i < 10; i++) {
        bian demobian = bianlist[i];
        int a = demobian.node1;
        int b = demobian.node2;
        float value = demobian.weight;
        if(UnionList.Find(a) != UnionList.Find(b)) {
            UnionList.Union(a, b);
            selected.push_back(demobian);
        }
    }
    for(int i = 0; i < selected.size(); i++) {
        cout << "NodeA: " << selected[i].node1 << " " << "NodeB: " << selected[i].node2 << " " << "Value: " << selected[i].weight << endl;
    }
    
    return 0;
}