//Score After Flipping Matrix

// You are given an m x n binary matrix grid.

// A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

// Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

// Return the highest possible score after making any number of moves (including zero moves).

 

// Example 1:


// Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// Output: 39
// Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
// Example 2:
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int result=(n)*pow(2,m-1);
        for(int j=1;j<grid[0].size();j++){
            int ones=0;
            for(int i=0;i<grid.size();i++){
                if((grid[i][j]==0&&grid[i][0]==0)||(grid[i][j]==1&&grid[i][0]==1))
                ones++;
            }
            int zeros=n-ones;
            if(zeros>ones)
            result+=(pow(2,m-1-j)*zeros);
            else
            result+=(pow(2,m-1-j)*ones);
        }
        return result;
    }
};