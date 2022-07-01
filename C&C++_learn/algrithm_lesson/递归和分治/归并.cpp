#include <iostream>
#include <algorithm>
using namespace std;

void merge(int a[], int l, int r, int mid){
    int aux[r - l + 1], i, j, k;
    for (k = l; k <= r; k++) aux[k - l] = a[k];
    i = l;
    j = mid + 1;
    for (k = l; k <= r; k++) {
        if (i > mid) {
            a[k] = aux[j - l];
            j++;
        }
        else if (j > r) {
            a[k] = aux[i - l];
            i++;
        }
        else if (aux[i - l] > aux[j - l]) {
            a[k] = aux[j - l];
            j++;
        }
        else {
            a[k] = aux[i - l];
            i++;
        }
    }
}

void merge_sort(int a[], int l, int r) { //a数组从l到r下标排序 {
    if (l >= r) return; //越界终止

    int mid = (l + r) / 2;

    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a, l, r, mid);
}

void mergesort(int a[], int l, int r) {
    merge_sort(a, l, r - 1);
}

int main() {
    int n, i;
    n = 5;

    int a[] = {1, 2, 8, 6, 4};

    mergesort(a, 0, n);

    for (i = 0; i < n; i++) cout << a[i];

    return 0;
}
