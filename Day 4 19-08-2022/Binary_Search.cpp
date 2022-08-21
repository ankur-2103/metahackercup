#include <bits/stdc++.h>
using namespace std;

int binary_search(int l, int r, int x, int arr[]){
    if(r >= l){
        int mid = l+(r-l)/2;
        if(arr[mid]==x)return mid;
        if(arr[mid]>x)return binary_search(l, mid-1, x, arr);
        return binary_search(mid+1, r, x, arr);
    }
    return -1;
}

int main(){
    int arr[] = {2, 3, 10, 15, 50};

    int a=binary_search(0, 4, 50, arr);
    int b=binary_search(0, 4, 0, arr);

    if(a==-1){
        cout << "Not Found\n";
    }else{
        cout << "Found at index " << a << "\n";
    }

    if(b==-1){
        cout << "Not Found\n";
    }else{
        cout << "Found at index " << b << "\n";
    }    
    return 0;
}