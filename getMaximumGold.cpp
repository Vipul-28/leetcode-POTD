//Path with Maximum Gold
// In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

// Return the maximum amount of gold you can collect under the conditions:

// Every time you are located in a cell you will collect all the gold in that cell.
// From your position, you can walk one step to the left, right, up, or down.
// You can't visit the same cell more than once.
// Never visit a cell with 0 gold.
// You can start and stop collecting gold from any position in the grid that has some gold.
 

// Example 1:

// Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
// Output: 24
// Explanation:
// [[0,6,0],
//  [5,8,7],
//  [0,9,0]]
// Path to get the maximum gold, 9 -> 8 -> 7.
// Example 2:

// Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
// Output: 28
// Explanation:
// [[1,0,7],
//  [2,0,6],
//  [3,4,5],
//  [0,3,0],
//  [9,0,20]]
// Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        if(i<=0||i>=n||j<=0||j>=m||vis[i][j]==1||grid[i][j]==0)
        return INT_MIN;
        vis[i][j]=1;
        int a=dfs(grid,i-1,j,vis);
        if(a<0)a=0;
        int b=dfs(grid,i+1,j,vis);
        if(b<0)b=0;
        int c=dfs(grid,i,j-1,vis);
        if(c<0)c=0;
        int d=dfs(grid,i,j+1,vis);
        if(d<0)d=0;
        vis[i][j]=0;
       int sum=grid[i][j]+max(max(a,b),max(c,d));
       return sum;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sum1=0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)
                {
                int sum=dfs(grid,i,j,vis);;
                sum1=max(sum,sum1);
                }
            }
        }
           return sum1;
    }
};