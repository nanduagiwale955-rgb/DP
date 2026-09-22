class Solution {
public:
    int solve(vector<int>&dp,vector<int>&nums,int i,int n){
    if(i>=n) return 0; //jb i out of index hoga toh zero return hoga
    if(dp[i]!=-1) return dp[i];
    int steal=nums[i]+solve(dp,nums,i+2,n);
    int skip=solve(dp,nums,i+1,n);
    return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(dp,nums,0,n);

    }
};
