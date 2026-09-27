class Solution {
public:
    int t[201][10001];
    bool knapsack(vector<int>&nums,int k,int n ){
        if(k==0) return true;
        if(n==0) return false;
        if(t[n][k]!=-1) return t[n][k];
        if(nums[n-1]<=k){
            return t[n][k]=knapsack(nums,k-nums[n-1],n-1) || knapsack(nums,k,n-1);
        }
        else { return knapsack(nums,k,n-1);
        }
    
    }
    bool subset(vector<int>&nums,int k){
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return knapsack(nums,k,n);
    }
     bool canPartition(vector<int>& nums) {
       int n=nums.size();
       int sum=accumulate(nums.begin(),nums.end(),0);
       if(sum%2!=0) return false;
            
            return subset(nums,sum/2);


    

    
    }
};
