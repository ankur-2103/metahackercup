#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &grid){
    return (x>=0 && x<8 && y>=0 && y<8 && grid[x][y]==-1);
}

void printSoln(vector<vector<int>> &grid){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout << " " << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int solveKT(int x, int y, int move, vector<vector<int>> &grid, int movex[8], int movey[8]){
    if(move >= 8*8)return 1;

    int nextx, nexty;
    for(int i=0; i<8; i++){
        nextx = x + movex[i];
        nexty = y + movey[i];

        if(isSafe(nextx, nexty, grid)){
            grid[nextx][nexty] = move;
            if(solveKT(nextx, nexty, move+1, grid, movex, movey) == 1){
                return 1;
            }else{
                grid[nextx][nexty] = -1;
            }
        }
    }

    return 0;
}

void solve(){
    vector<vector<int>> grid(8, vector<int>(8, -1));

    int movex[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int movey[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    grid[0][0] = 0;

    if(solveKT(0, 0, 1, grid, movex, movey) == 1){
        printSoln(grid);
    }else{
        cout << "SOLUTION DOES NOT EXIST\n";
    }
}

int main(){
    solve();
    return 0;
}