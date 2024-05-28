#include <iostream>

using namespace std;

struct Pair {
    int first, second;
};

void Merge(Pair* a, int start, int mid, int end) {
    Pair* temp = new Pair[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (a[i].first < a[j].first || (a[i].first == a[j].first && a[i].second < a[j].second)) {
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

void MergeSort(Pair* a, int start, int end) {
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

    Pair* a = new Pair[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    MergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i].first << ' ' << a[i].second << endl;
    }

    delete[] a;

    return 0;
}
