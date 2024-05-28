#include <iostream>

using namespace std;

void Merge(int* a, int start, int mid, int end) {
    int* temp = new int[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            k += 1;
            i += 1;
        } else {
            temp[k] = a[j];
            k += 1;
            j += 1;
        }
    }

    while (i <= mid) {
        temp[k] = a[i];
        k += 1;
        i += 1;
    }

    while (j <= end) {
        temp[k] = a[j];
        k += 1;
        j += 1;
    }

    for (i = start; i <= end; i += 1) {
        a[i] = temp[i - start];
    }
}

void MergeSort(int* a, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(a, start, mid);
        MergeSort(a, mid + 1, end);
        Merge(a, start, mid, end);
    }
}

int main() {
    int n;
    cin >> n;

    int* a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    MergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    delete[] a;

    return 0;
}
