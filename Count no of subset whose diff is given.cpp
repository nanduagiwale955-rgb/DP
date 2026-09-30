class Solution {
  public:
    int t[1001][1001];
    int knapsack(vector<int>&arr,int i ,int n){
        if(n==0) return i==0;
        if(t[n][i]!=-1) return t[n][i];
        if(arr[n-1]<=i){
            return t[n][i]=knapsack(arr,i-arr[n-1],n-1) + knapsack(arr,i,n-1);
        }
        else{
            return t[n][i]=knapsack(arr,i,n-1);
        }
        
        
    }
    int countPartitions(vector<int>& arr, int diff) {
        int s=accumulate(arr.begin(),arr.end(),0);
        memset(t,-1,sizeof(t));
        int n=arr.size();
        if((s+diff)%2!=0) return 0;
        int s1=(s+diff)/2;
        return knapsack(arr,s1,n);
        
    
        
        
        
        
        
    }
};
