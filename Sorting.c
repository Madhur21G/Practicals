#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void printarr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int arr[], int l, int r, int m){
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int a[n1];
    int b[n2];
    for(int i = 0;i < n1; i++){
        a[i] = arr[l + i];
    }
    for(int j = 0; j < n2; j++){
        b[j] = arr[j + m + 1];
    }
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            arr[k] = a[i++];
        }
        else{
            arr[k] = b[j++];
        }
        k++;
    }
    while(i < n1){
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = b[j];
        j++;
        k++;
    }
}

int partition(int arr[], int l, int r){
    int pivot = arr[l];
    int i = l;
    int j = r;
    while(i < j){
        while(arr[i] < pivot && i <= l - 1) i++;
        while(arr[j] > pivot && j >= l + 1) j--;
        if(i < j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[l], &arr[r]);
    return j;
}

void bubble_sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
        }
    }
}

void selection_sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int min_idx = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge_sort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, r, m);
    }
}

void quick_sort(int arr[], int l, int r){
    if(l < r){
        int p_idx = partition(arr, l, r);
        quick_sort(arr, l, p_idx - 1);
        quick_sort(arr,p_idx + 1, r);
    }
}

int main(){


}
