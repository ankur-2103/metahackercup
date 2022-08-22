#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i=0; i<n; i++){
        int x = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[x]){
                x = j;
            }
        }
        if(i!=x){
            swap(arr[i], arr[x]);
        }
    }
}

void printSoln(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {68, 20, 90, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, n);
    printSoln(arr, n);
   
    return 0;
}