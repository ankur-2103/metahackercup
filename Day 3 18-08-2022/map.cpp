#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int,int>mp;
    mp[0]=10;
    mp[100]++;
    mp[1]=1000;
    mp[0]++;
    mp[1]++;

    for (auto a : mp){
        cout << a.first << " " << a.second << "\n";
    }
    return 0;
}