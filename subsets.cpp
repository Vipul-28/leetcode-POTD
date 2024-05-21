//Subsets
//Given an integer array nums of unique elements, return all possible 
//subsets
 //(the power set).

//The solution set must not contain duplicate subsets. Return the solution in any order.

 

//Example 1:

//Input: nums = [1,2,3]
//Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//Example 2:

//Input: nums = [0]
//Output: [[],[0]]


class Solution {
public:
    void Solve(int i,int j,vector<vector<int>>&v,vector<int>&ans,vector<int>& nums){
        if(i==(nums.size()))
        {
        v.push_back(ans);
        return ;
        }
        ans.push_back(nums[i]);
        Solve(i+1,j,v,ans,nums);
        ans.pop_back();
        Solve(i+1,j,v,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>v;
            vector<int>ans;
            Solve(0,0,v,ans,nums);
         return v;
    }
};




class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>v;
         for(int i=0;i<(1<<nums.size());i++){
            vector<int>ans;
            for(int j=0;j<nums.size();j++){
                if(i&1<<j)
                ans.push_back(nums[j]);
            }
             v.push_back(ans);
         }
         return v;
    }
};