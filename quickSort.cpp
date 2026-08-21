#include <iostream>
using namespace std;

int partition(int a[], int l, int h) {
    int p = a[h], i = l - 1;
    for (int j = l; j < h; j++) {
        if (a[j] < p)
            swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[h]);
    return i + 1;
}

void quickSort(int a[], int l, int h) {
    if (l < h) {
        int p = partition(a, l, h);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, h);
    }
}

int main() {
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}