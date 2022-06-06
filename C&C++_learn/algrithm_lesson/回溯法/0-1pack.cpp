#include <bits/stdc++.h>

using namespace std;

class Object
{
public:
    int v;
    int w;
    int id;
};

int cp, cw, bestp, total_w, total_p;
int n = 5, c = 10;
int x[100], best_x[100];
Object O[100];
void Input()
{
    int w[n] = {2, 2, 6, 5, 4}, v[n] = {6, 3, 5, 4, 6};
    for(int i = 1; i <= n; ++i)
    {
        O[i].w = w[i];
        O[i].v = v[i];
        O[i].id = i;
    }
}
bool cmp(const Object &a, const Object &b)
{
    return a.v / a.w > b.v / b.w;
}
void Initilize()
{
    cp = cw = total_w = total_p = bestp = 0;
    for(int i = 1; i <= n; ++i)
    {
        total_p += O[i].v;
        total_w += O[i].w;
    }
    //依照单位重量排序
    sort(O + 1, O + n + 1, cmp);
}

//计算上界
int Bound(int i)
{
    int temp_cw = c - cw;
    int temp_cp = cp;
    while(i <= n && temp_cw >= O[i].w)
    {
        temp_cw -= O[i].w;
        temp_cp += O[i].v;
        ++i;
    }
    //装满背包
    if(i <= n)
        temp_cp += O[i].v / O[i].w * temp_cw;
    return temp_cp;


}

void Backtrack(int i)
{
    if(i > n)
    {
        bestp = cp;
        for(int i = 1; i <= n; ++i)
            best_x[i] = x[i];
        return;
    }
    if(cw + O[i].w <= c)
    {
        x[O[i].id] = 1;
        cw += O[i].w;
        cp += O[i].v;
        Backtrack(i + 1);
        cp -= O[i].v;
        cw -= O[i].w;
        x[O[i].id] = 0;
    }
    //向右求解的约束条件
    if(Bound(i + 1) > bestp)
    {
        x[O[i].id] = 0;
        Backtrack(i + 1);
    }
}



void OutPut()
{
    cout<<"max value is "<<bestp<<endl;;
    cout<<"selected id: ";
    for(int i = 1; i <= n; ++i)
    {
        if(best_x[i] == 1)
            cout << i+1 << " ";
    }
}
int main()
{
    Input();
    Initilize();
    Backtrack(1);
    OutPut();
}
