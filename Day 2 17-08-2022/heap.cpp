#include <bits/stdc++.h>
using namespace std;

class MinHeap{
public:
    int *arr;
    int cap;
    int s;

    MinHeap(int x){
        cap = x;
        s = 0;
        arr = new int[cap];
    }

    int parent(int i){ return (i-1)/2; }

    int left(int i){return (2*i)+1;}

    int right(int i){return (2*i)+2;}

    int getMin(){return arr[0];}

    void insertKey(int k){
        if(s == cap){
            cout << "Overflow" << endl;
            return;
        }

        int i = s;
        s++;
        arr[i] = k;

        while(i != 0 && arr[parent(i)] > arr[i]){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int val){
        arr[i] = val;
        while(i != 0 && arr[parent(i)] > arr[i]){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    int extractMin(){
        if(s <= 0){
            return INT_MAX;
        }
        if(s==1){
            s--;
            return arr[0];
        }

        int m = arr[0];
        arr[0] = arr[s-1];
        s--;
        MinHeapify(0);

        return m;
    }

    void deleteKey(int i){
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void MinHeapify(int i){
        int l = left(i);
        int r = right(i);
        int sm = i;
        if(l < s && arr[l] < arr[i]){
            sm = l;
        }
        if(r < s && arr[r] < arr[sm]){
            sm = r;
        }

        if(sm != i){
            swap(arr[sm], arr[i]);
            MinHeapify(sm);
        }
    }
};

int main(){
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
