class Solution {
  public:
    int t[1001][1001];
    int knapsack(vector<int>&price,vector<int>&wt,int W,int n){
        if(n==0 || W==0) return 0;
        if(t[n][W]!=-1) return t[n][W];
        if(wt[n-1]<=W){
            return t[n][W]=max(price[n-1]+knapsack(price,wt,W-wt[n-1],n),knapsack(price,wt,W,n-1));
            
        }
        else{
            return t[n][W]=knapsack(price,wt,W,n-1);
        }

    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<int>length(n);
        memset(t,-1,sizeof(t));
        for(int i=1;i<=n;i++){
            length[i-1]=i;
        }
        return knapsack(price,length,n,n);
        
    }
};
