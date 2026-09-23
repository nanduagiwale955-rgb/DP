class Solution {
public:
int solve(vector<int>&dp,vector<int>&nums,int i,int n){
    if(i>n) return 0; //jb i out of index hoga toh zero return hoga 
    //equal= tb aata jb n array size rhta but yha pe it is valid index
    if(dp[i]!=-1) return dp[i];
    int steal=nums[i]+solve(dp,nums,i+2,n);
    int skip=solve(dp,nums,i+1,n);
    return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int take_0th_house=solve(dp1,nums,0,n-2);
        int take_1st_house=solve(dp2,nums,1,n-1);
        return max(take_0th_house,take_1st_house);
    }
};
