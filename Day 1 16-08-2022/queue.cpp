#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int>q;

    for(int i=1; i<=5; i++){
        q.push(i*10);
    }

    cout << "q.size() : " << q.size();
    cout << "\ngquiz.front() : " << q.front();
    cout << "\ngquiz.back() : " << q.back();
  
    q.pop();
    cout << "\nAfter pop";
    cout << "\ngquiz.front() : " << q.front();
    cout << "\ngquiz.back() : " << q.back();

    return 0;
}