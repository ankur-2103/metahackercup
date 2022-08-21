#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int n, vector<vector<bool>>&board){
    for(int i=0; i<col; i++){
        if(board[row][i])return false;
    }

    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j])return false;
    }

    for(int i=row, j=col; i<n && j>=0; i++, j--){
        if(board[i][j])return false;
    }

    return true;
}

void printSoln(int n, vector<vector<bool>>&board){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << " " << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool solveNQ(int col, int n, vector<vector<bool>>&board){
    if(col >= n)return true;

    for(int i=0; i<n; i++){
        if(isSafe(i, col, n, board)){
            board[i][col]=true;
            if(solveNQ(col+1, n, board))return true;
            board[i][col]=false;
        }
    }

    return false;
}

int main(){
    int n;
    cin >> n;
    vector<vector<bool>>board(n, vector<bool>(n, false));

    if(solveNQ(0, n, board)){
        printSoln(n, board);
    }else{
        cout << "SOLUTION DOSE NOT EXIST\n";
    }
    return 0;
}