// Find the Safest Path in a Grid
// You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

// A cell containing a thief if grid[r][c] = 1
// An empty cell if grid[r][c] = 0
// You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
// The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
// Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
// An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
// The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

// Example 1:
// Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
// Output: 0
// Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
// Example 2:


// Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
// Output: 2
// Explanation: The path depicted in the picture above has a safeness factor of 2 since:
// - The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
// It can be shown that there are no other paths with a higher safeness factor.
// Example 3:


// Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
// Output: 2
// Explanation: The path depicted in the picture above has a safeness factor of 2 since:
// - The closest cell of the path to the thief at c
class Solution {
public:
    const int dir[4]={-1,0,1,0};
    const int dic[4]={0,1,0,-1};
    int isValid(vector<vector<int>>&dis,int val){
        int n=dis.size();
        int m=dis[0].size();
        if(val>dis[0][0]||val>dis[n-1][m-1])return false;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>pq;
        pq.push({0,0});
        vis[0][0]=1;
        while(!pq.empty()){
            int row=pq.front().first;
            int col=pq.front().second;
            pq.pop();   
            if(row==n-1&&col==n-1)return true;
            if(dis[row][col]<val)return false;
             for(int i=0;i<4;i++){
                int new_row=dir[i]+row;
                int new_col=dic[i]+col;
                if(new_row>=0&&new_row<n&&new_col>=0&&new_col<m&&!vis[new_row][new_col])
                {
                    if(dis[new_row][new_col]>=val){
                    pq.push({new_row,new_col});
                    vis[new_row][new_col]=1;
                    }
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                pq.push({{i,j},0});
                }
            }
        }
        while(!pq.empty()){
            auto val=pq.front();
            pq.pop();
            int row=val.first.first;
            int col=val.first.second;
            int dist=val.second;
            dis[row][col]=dist;
            for(int i=0;i<4;i++){
                int new_row=dir[i]+row;
                int new_col=dic[i]+col;
                if(new_row>=0&&new_row<n&&new_col>=0&&new_col<m&&!vis[new_row][new_col])
                {
                    pq.push({{new_row,new_col},dist+1});
                    vis[new_row][new_col]=1;
                }
            }
        }
        int low=0,high=400;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(isValid(dis,mid)){
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};