#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int>s;

    for(int i=1; i<=5; i++){
        s.push(i);       
    }

    cout << "Before pop : " << s.top() << "\n";
    s.pop();
    cout << "After pop : " << s.top() << "\n";

    cout << "Removing all elements : \n";
    for(int i=0; i<4; i++){
        cout << s.top() << "\n";
        s.pop();
    }
    return 0;
}