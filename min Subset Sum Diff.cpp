class Solution {
public:
    int t[1001][1001];

    bool knapsack(vector<int>& arr, int range, int n) {
        if (range == 0)
            return true;

        if (n == 0)
            return false;

        if (t[n][range] != -1)
            return t[n][range];

        if (arr[n - 1] <= range) {
            return t[n][range] =
                knapsack(arr, range - arr[n - 1], n - 1) ||
                knapsack(arr, range, n - 1);
        }
        else {
            return t[n][range] =
                knapsack(arr, range, n - 1);
        }
    }

    int minDifference(vector<int>& arr) {
        int n = arr.size();

        int range = accumulate(arr.begin(), arr.end(), 0);

        memset(t, -1, sizeof(t));

        int ans = INT_MAX;

        for (int i = 0; i <= range / 2; i++) {
            if (knapsack(arr, i, n)) {
                ans = min(ans, range - 2 * i);
            }
        }

        return ans;
    }
};
