#include <iostream>
#include <climits>
using namespace std;
int maxSum(int arr[], int l, int m, int r) {
    int sum = 0, left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }
    return left_sum + right_sum;
}
int maxSubArraySum(int arr[], int l, int r) {
    if (l == r)
        return arr[l];

    int m = (l + r) / 2;
    return max(max(maxSubArraySum(arr, l, m),maxSubArraySum(arr, m + 1, r)),maxSum(arr, l, m, r));
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSubArraySum(arr, 0, n - 1);
    return 0;
}
