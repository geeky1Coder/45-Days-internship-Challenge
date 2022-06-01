class Solution {
public:
    int md=1e9+7;
    int knightDialer(int n) {
        vector<vector<int>> ms = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
        for (int j = 0; j < 10; ++j) {
            dp[1][j] = 1;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (auto el : ms[j]) {
                    dp[i][j] = (dp[i][j]%md+dp[i - 1][el]%md)%md;
                }
            }
        }

        long long ans = 0;
        for (int j = 0; j < 10; ++j) {
            ans = (ans%md+dp[n][j]%md)%md;
        }

        return (ans%md);
    }
};