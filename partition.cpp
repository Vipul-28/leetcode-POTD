//Palindrome Partitioning
// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
class Solution {
    public:
    bool isPalindrome(string str)
{
    int left=0,right=str.size()-1;
    while(left<right)
    {
        if(str[left]==str[right])
        {
            left++,right--;
        }
        else
        return false;
    }
    return true;
}
public:
void partitioning(string str,vector<vector<string>>&a,vector<string>ans,int index)
{
    if(index==str.size())
    {
        // if(find(a.begin(),a.end(),ans)==a.end())
        a.push_back(ans);
        return ;
    }
    for(int i=index;i<str.size();i++)
    {
       string str1=str.substr(index,i-index+1);
       if(isPalindrome(str1))
       {
          ans.push_back(str1);
          partitioning(str,a,ans,i+1);
          ans.pop_back();
       }
    }
    return ;
}
public:
    vector<vector<string>> partition(string str) {
        vector<vector<string>>a;
    vector<string>ans;
    partitioning(str,a,ans,0);
    return a;
    }
};