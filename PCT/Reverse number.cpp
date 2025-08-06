#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end) {
    if (start >= end)
        return;

    // Swap elements
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive call
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, 0, n - 1);

    // Output result
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

