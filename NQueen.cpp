#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<char>>&chessboard,int row,int col){
    int n=chessboard.size();
    //check row-> East and west
    for(int j=0;j<n;j++){
        if(chessboard[row][j]=='Q') return false;
    }
    //check column->north and south
    for(int i=0;i<n;i++){
        if(chessboard[i][col]=='Q') return false;
    }
    //check northEast
    int i=row;
    int j=col;
    while(i>=0 && j<n){
        if(chessboard[i][j]=='Q') return false;
        i--;
        j++;
    }
    //chesk south east
      i=row;
     j=col;
    while(i<n && j<n){
        if(chessboard[i][j]=='Q') return false;
        i++;
        j++;
    }
    //check south west
     i=row;
     j=col;
    while(i<n && j>=0){
        if(chessboard[i][j]=='Q') return false;
        i++;
        j--;
    }
    //check north west
    i=row;
    j=col;
    while(i>=0 && j>=0){
        if(chessboard[i][j]=='Q') return false;
        i--;
        j--;
    }
    return true;

}
void nqueen(vector<vector<char>>&chessboard,int row){
    int n=chessboard.size();
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<chessboard[i][j]<<" ";
               
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    for(int j=0;j<n;j++){
        if(isSafe(chessboard,row,j)){
            chessboard[row][j]='Q';
            nqueen(chessboard,row+1);
            chessboard[row][j]='X';//backtracking
        }
    }
}
int main(){
    int n=4;
    vector<vector<char>>chessboard(n,vector<char>(n,'X'));
    nqueen(chessboard,0);
}