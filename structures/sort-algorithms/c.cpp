#include <iostream>

using namespace std;

void Merge(int* a, int start, int mid, int end, bool increasing) {
    int* temp = new int[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (increasing) {
            if (a[i] <= a[j]) {
                temp[k] = a[i];
                k += 1;
                i += 1;
            } else {
                temp[k] = a[j];
                k += 1;
                j += 1;
            }
        } else {
            if (a[i] >= a[j]) {
                temp[k] = a[i];
                k += 1;
                i += 1;
            } else {
                temp[k] = a[j];
                k += 1;
                j += 1;
            }
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

    delete[] temp;
}

void MergeSort(int* a, int start, int end, bool increasing) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(a, start, mid, increasing);
        MergeSort(a, mid + 1, end, increasing);
        Merge(a, start, mid, end, increasing);
    }
}

int main() {
    int n;
    cin >> n;

    int* odd = new int[n];
    int* even = new int[n];

    int odd_size = 0, even_size = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2 != 0) {
            odd[odd_size] = a;
            odd_size++;
        } else {
            even[even_size] = a;
            even_size++;
        }
    }

    MergeSort(odd, 0, odd_size - 1, true);
    MergeSort(even, 0, even_size - 1, false);

    for (int i = 0; i < odd_size; i++) {
        cout << odd[i] << ' ';
    }

    for (int i = 0; i < even_size; i++) {
        cout << even[i] << ' ';
    }

    delete[] odd;
    delete[] even;

    return 0;
}
