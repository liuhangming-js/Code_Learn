#include <iostream>
using namespace std;

void quick_sort(int list[], int begin, int end) {
    if(begin > end) return;
    int tem = list[begin];
    int i = begin;
    int j = end;
    while(i != j) {
        while(list[j] >= tem && j > i) j--;
        while(list[i] <= tem && j > i) i++;
        if(j > i) swap(list[j], list[i]);
    }
    swap(list[begin], list[i]);
    quick_sort(list, begin, i - 1);
    quick_sort(list, i + 1, end);
}

int main() {
    int list[] = {5, 2, 3, 4, 6, 1};
    quick_sort(list, 0, 5);
    for(int i = 0; i < 6; i++) cout << list[i];

    return 0;
}
