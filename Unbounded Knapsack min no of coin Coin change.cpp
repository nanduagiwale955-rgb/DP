class Solution {
public:
    int t[13][10001];
    int knapsack(vector<int>&coins,int sum, int n){
        if(n==0) return (sum==0)?0:1e9;
        if(t[n][sum]!=-1) return t[n][sum];
        if(coins[n-1]<=sum){
            return t[n][sum]=min(knapsack(coins,sum-coins[n-1],n)+1,knapsack(coins,sum,n-1));
        }
        else{
            return t[n][sum]=knapsack(coins,sum,n-1);
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
     int n=coins.size();
     memset(t,-1,sizeof(t));
     int ans=knapsack(coins,amount,n);
     return ans==1e9?-1:ans;
    }
};
