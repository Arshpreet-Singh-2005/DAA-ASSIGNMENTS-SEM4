#include<iostream>
using namespace std;
int binarysearch(int arr[], int l, int h, int k){
    if(l > h) return -1;
    int mid = h+((l - h) / 2);
    if(k < arr[mid]){
        return binarysearch(arr, l, mid - 1, k);
        }
    else if(k > arr[mid]){
        return binarysearch(arr, mid + 1, h, k);
    }
    else{
        return mid;
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    int result = binarysearch(arr, 0, n - 1, target);
    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}

 