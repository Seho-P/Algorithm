#include <iostream>
using namespace std;

long long dp[101];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        dp[i] = i;
        for(int k = 1; k <= i - 3; k++){
            dp[i] = max(dp[i], dp[k] * (i - k - 1));
        }
    }

    cout << dp[n];
}