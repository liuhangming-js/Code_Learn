#include<iostream>
#include<vector>
using namespace std;

void dijkstra(int v, vector<vector<float>> a, vector<float> dist, vector<int> prev);

int main() {
    cout << "单源最短路径" << endl;

    int v = 1;

    vector<vector<float>> a;
    a.push_back({0, 0, 0, 0, 0, 0});
    a.push_back({0, 0, 10, __FLT_MAX__, __FLT_MAX__, 100});
    a.push_back({0, __FLT_MAX__, 0, 50, __FLT_MAX__, __FLT_MAX__});
    a.push_back({0, __FLT_MAX__, __FLT_MAX__, 20, 0, 60});
    a.push_back({0, __FLT_MAX__, __FLT_MAX__, __FLT_MAX__, __FLT_MAX__, 0});
    
    vector<float> dist;
    vector<int> prev;

    dijkstra(v, a, dist, prev);
    for(int i = 1; i <= dist.size() - 1; i++) cout << dist[i] << " ";

    return 0;
}

void dijkstra(int v, vector<vector<float>> a, vector<float> dist, vector<int> prev) {
    int n = dist.size() - 1;
    if(v < 1 || v > n) return; //v是起始节点
    bool s[n + 1];

    //初始化
    for (int i = 1; i <= n; i++) {
        dist[i] = a[v][i];
        s[i] = false;
        if (dist[i] == __FLT_MAX__) prev[i] = 0;
        else prev[i] = v;
    }

    dist[v] = 0;
    s[v] = true;

    for (int i = 1; i < n; i++) {
        float temp = __FLT_MAX__;
        int u = v;
        for (int j = 1; j <= n; j++)
            if ((! s[j]) && (dist[j] < temp)) {
                u = j;
                temp = dist[j];
            }
        s[u] = true;
        for (int j = 1; j <= n; j++)
            if ((! s[j]) && (a[u][j] < __FLT_MAX__)) {
                float newdist = dist[u] + a[u][j];
                if (newdist < dist[j]) {
                    //dist[j] 减少
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}