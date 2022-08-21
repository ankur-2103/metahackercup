#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &maze){
    return (x>=0 && x<4 && y>=0 && y<4 && maze[x][y] == 1);
}

void printSoln(vector<vector<int>> &soln){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << " " << soln[i][j] << " ";
        }
        cout << "\n";
    }
}

bool solveRM(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &soln){
    if(x == 3 && y == 3 && maze[x][y]){
        soln[x][y] = 1;
        return true;
    }

    if(isSafe(x, y, maze)){
        if(soln[x][y]==1)return false;

        soln[x][y] = 1;

        if(solveRM(x+1, y, maze, soln) || solveRM(x, y+1, maze, soln))return true;

        soln[x][y] = 0;
    }

    return false;
}

void solve(vector<vector<int>>&maze){
    vector<vector<int>>soln(4, vector<int>(4,0));

    if(solveRM(0, 0, maze, soln)){
        printSoln(soln);
    }else{
        cout << "SOLUTION DOSE NOT EXIST\n";
    }
}

int main(){

    vector<vector<int>> maze = { { 1, 0, 0, 0 },{ 1, 1, 0, 1 },{ 0, 1, 0, 0 },{ 1, 1, 1, 1 } };

    solve(maze);   
    return 0;
}