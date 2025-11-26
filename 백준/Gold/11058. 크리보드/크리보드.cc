#include <iostream>
using namespace std;

long long dp[101];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<=n;i++){
        dp[i]=i;
    }
    for(int i=4;i<=n;i++){
        for(int j=2;j<i-1;j++){
            dp[i] = max(dp[i],dp[i-j-1]*j);
        }
    }
    cout << dp[n];
}
