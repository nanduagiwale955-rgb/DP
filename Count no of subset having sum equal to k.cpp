class Solution {
  public:
    int t[1001][1001];
    int knapsack(vector<int>&arr,int n,int target){
        if(n==0) return target==0;
        
        if(t[n][target]!=-1) return t[n][target];
        if(arr[n-1]<=target){

            return t[n][target]=(knapsack(arr,n-1,target-arr[n-1])+knapsack(arr,n-1,target));
        }
        else{
            return t[n][target]=knapsack(arr,n-1,target);
        }
        
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        memset(t,-1,sizeof(t));
        return knapsack(arr,n,target);
    }
};
