class Solution {
public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        int n = arr.size();

        bool t[n+1][k+1];

        // Base case
        for(int i = 0; i < n+1; i++) {
            for(int j = 0; j < k+1; j++) {

                if(i == 0) {
                    t[i][j] = false;
                }

                if(j == 0) {
                    t[i][j] = true;
                }
            }
        }

        // DP
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < k+1; j++) {

                if(arr[i-1] <= j) {
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][k];
    }
};
