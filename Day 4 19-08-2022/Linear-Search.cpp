#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int x){
    for(int i=0; i<5; i++){
        if(arr[i]==x)return i;
    }
    return -1;
}


int main(){
    int arr[] = {100, 5, 2, 89, 50};

    int a=search(arr, 100);
    int b=search(arr, 0);

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