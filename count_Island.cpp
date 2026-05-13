#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>>&grid,int r,int c,vector<vector<bool>>&visited){
    int n=grid.size();
    int m=grid[0].size();

    return (r>=0 && r<n && c>=0 && c<m && grid[r][c]=='L' && !visited[r][c]);
}


void dfs(vector<vector<char>>&grid,int r,int c,vector<vector<bool>>&visited){
    visited[r][c]=true;

    vector<int>dr={-1,-1,-1,0,0,1,1,1};
    vector<int>dc={-1,0,1,-1,1,-1,0,1};

    for(int k=0;k<8;k++){
        int nr=r+dr[k];
        int nc=c+dc[k];
    
    if(isSafe(grid,nr,nc,visited))
      dfs(grid,nr,nc,visited);
    }
    
}


int countLand(vector<vector<char>>&grid){
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<bool>>visited(n,vector<bool>(m,false));
    int islands=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='L'&&!visited[i][j]){
                dfs(grid,i,j,visited);
                islands++;
            }
        }

    }
    return islands;
}
  
int main () {

    vector<vector<char>>grid={
        {'L','W','W','W','W'},
        {'W','L','W','W','L'},
        {'L','W','W','L','L'},
        {'W','W','W','W','W'},
        {'L','W','L','L','W'}
    };
    cout<<countLand(grid)<<endl;
  
  
return 0;
}