//K-th Smallest Prime Fraction
// You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

// For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

// Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

 

// Example 1:

// Input: arr = [1,2,3,5], k = 3
// Output: [2,5]
// Explanation: The fractions to be considered in sorted order are:
// 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
// The third fraction is 2/5.
// Example 2:

// Input: arr = [1,7], k = 1
// Output: [1,7]
 
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,vector<int>>>pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                double x=arr[i]/(arr[j]*1.0);
            if(pq.size()==k){
                if(x<pq.top().first){
                 pq.pop();
                 pq.push({x,{arr[i],arr[j]}});
                }
            }
            else
                 pq.push({x,{arr[i],arr[j]}});

            }
        }
        return pq.top().second;
    }
};