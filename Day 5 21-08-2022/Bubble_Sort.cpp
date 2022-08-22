#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
    for(int i=0; i<n; i++){
        bool x = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                x = true; 
            }
        }
        if(!x)break;
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
    bubble_sort(arr, n);
    printSoln(arr, n);
   
    return 0;
}