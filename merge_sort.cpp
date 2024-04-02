#include<iostream>
using namespace std;


void merge(int arr[], int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = l; 
    int temp[5];

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <=mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[] , int l , int r) {
    if(l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
 
int main()
{
    int arr[] = { 5,4,3,2,1 };
    mergeSort(arr, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
