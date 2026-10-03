class Solution {
public:
    int t[301][5001];
    int knapsack(vector<int>&coins,int sum, int n){
        if(n==0) return sum==0;
        if(t[n][sum]!=-1) return t[n][sum];
        if(coins[n-1]<=sum){
            return t[n][sum]=knapsack(coins,sum-coins[n-1],n)+knapsack(coins,sum,n-1);
        }
        else{
            return t[n][sum]=knapsack(coins,sum,n-1);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        memset(t,-1,sizeof(t));
        return knapsack(coins,amount,n);
    }
};
