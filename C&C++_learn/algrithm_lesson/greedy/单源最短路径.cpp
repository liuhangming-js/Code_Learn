#include<stdio.h>
#include<iostream>
#include<stack>

const double MAXNUM = 100000;
#define n 5

void dijkstra(int v, double a[][n+1], double dist[], int prev[]);

void find (int v, int i, int prev[]);

int main() {
    printf("Min Route of 1 start:\n");
    
    int v = 1;

    double a[n + 1][n + 1] = 
    {{0,      0,      0,      0,      0,      0},
     {0, MAXNUM,     10, MAXNUM,     30,    100},
     {0, MAXNUM, MAXNUM,     50, MAXNUM, MAXNUM},
     {0, MAXNUM, MAXNUM, MAXNUM, MAXNUM,     10},
     {0, MAXNUM, MAXNUM,     20, MAXNUM,     60},
     {0, MAXNUM, MAXNUM, MAXNUM, MAXNUM, MAXNUM}};
    
    double dist[6];
    int prev[6];

    dijkstra(v, a, dist, prev);
    for(int i = 1; i <= n; i++) {
        printf("From node %d to %d is %lf\n ", v, i, dist[i]);
        find(v, i, prev);
    }

    return 0;
}

void dijkstra(int v, double a[][n+1], double dist[], int prev[]) {
    if(v < 1 || v > n) return; //v是起始节点
    bool s[n + 1];

    //初始化
    for (int i = 1; i <= n; i++) {
        dist[i] = a[v][i];
        s[i] = false;
        if (dist[i] == MAXNUM) prev[i] = 0;
        else prev[i] = v;
    }

    dist[v] = 0;
    s[v] = true;

    for (int i = 1; i < n; i++) {
        double temp = MAXNUM;
        int u = v;
        for (int j = 1; j <= n; j++)
            if ((! s[j]) && (dist[j] < temp)) {
                u = j;
                temp = dist[j];
            }
        s[u] = true;
        for (int j = 1; j <= n; j++)
            if ((! s[j]) && (a[u][j] < MAXNUM)) {
                double newdist = dist[u] + a[u][j];
                if (newdist < dist[j]) {
                    //dist[j] 减少
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}

// void find(int v, int i, int prev[]) {
//     stack<int> n;
//     int u = i;
//     while (prev[u] != v) {
//         n.push(prev[u]);
//         u = prev[u];
//     }
//     printf("%d", v);
//     while (! n.empty()) {
//         printf("->%d", n.top());
//         n.pop();
//     }
// }