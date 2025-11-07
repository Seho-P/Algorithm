#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A, B, C;
    string X, Y;
    cin >> A >> B >> C;
    cin >> X >> Y;

    int n = X.size();
    int m = Y.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    
    for (int i = 1; i <= n; i++) dp[i][0] = i * B;
    for (int j = 1; j <= m; j++) dp[0][j] = j * B;

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int same_or_diff = dp[i-1][j-1] + (X[i-1] == Y[j-1] ? A : C);
            int gap_x = dp[i-1][j] + B;
            int gap_y = dp[i][j-1] + B;
            dp[i][j] = max({same_or_diff, gap_x, gap_y});
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}