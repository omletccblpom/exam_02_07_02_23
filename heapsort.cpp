#include <algorithm>

static void sift(int *A, int i, int m)
{
    int j = i, k = i*2+1;

    while (k <= m) {
        if (k<m && A[k]<A[k+1]) {
            k++;
        }

        if (A[j] < A[k]) {
            std::swap(A[j], A[k]);
            j = k;
            k = k*2+1;
        }
        else {
          break;
        }
    }
}

void heapSort(int *arr, int size, int step) {
    int i, m, s;

    for (i = size/2; i >= 0; i--)
        sift(arr, i, size-1);

    for (m = size-1; m >= 1 || s < step; m--, s++) {
        std::swap(arr[0], arr[m]);
        sift(arr, 0, m-1);
    }
}
