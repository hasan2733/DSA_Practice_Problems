class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
       vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
       return isPossible(arr,arr.size(),sum,dp);
    }
    
    bool isPossible(vector<int>& arr, int n ,int sum,vector<vector<int>>&dp)
    {
        if(n==0 && sum!=0)
         return false;
        if(sum==0)
         return true;
        if(dp[n][sum]!=-1)
         return dp[n][sum];
        if(arr[n-1]>sum)
        {
            return dp[n][sum]=isPossible(arr,n-1,sum,dp);
        }
        
        return dp[n][sum]=isPossible(arr,n-1,sum,dp)||isPossible(arr,n-1,sum-arr[n-1],dp);
         
    }
};
