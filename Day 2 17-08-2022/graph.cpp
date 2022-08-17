#include <bits/stdc++.h>
using namespace std;

class Graph{
    int n;
    list<int>*node;
    vector<bool>visited;

public:

    Graph(int n){
        this->n = n;
        node = new list<int>[n];
        visited.resize(n,false);
    }

    void addEdge(int v, int w){
        node[v].push_back(w);
    }

    void bfs(int s){
        visited.resize(n, false);
        list<int>li;

        visited[s]=true;
        li.push_back(s);

        while(!li.empty()){
            s = li.front();
            cout << s << " ";
            li.pop_front();

            for(auto i : node[s]){
                if(!visited[i]){
                    visited[i]=true;
                    li.push_back(i);
                }
            }
        }

        visited.resize(n,false);
    }

    void dfs(int v){
        visited[v]=true;
        cout << v << " ";

        for(auto i : node[v]){
            if(!visited[i]){
                dfs(i);
            }
        }
    }

};

int main(){
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.bfs(1);
    g.dfs(0);


    return 0;
}