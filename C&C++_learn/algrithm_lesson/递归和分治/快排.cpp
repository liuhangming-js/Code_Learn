#include <iostream>
using namespace std;

void quick_sort(int list[], int begin, int end) {
    if(begin > end) return; //出界终止
    int tem = list[begin]; //先取第一个数为基数
    int i = begin;
    int j = end;
    while(i != j) {
        while(list[j] >= tem && j > i) j--;
        while(list[i] <= tem && j > i) i++;
        if(j > i) swap(list[j], list[i]);
    }
    swap(list[begin], list[i]);
    quick_sort(list, begin, i - 1); //左边递归
    quick_sort(list, i + 1, end); //右边递归
}

int main() {
    int list[] = {5, 2, 3, 4, 6, 1};
    quick_sort(list, 0, 5);
    for(int i = 0; i < 6; i++) cout << list[i];

    return 0;
}
