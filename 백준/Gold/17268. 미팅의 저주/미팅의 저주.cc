#include <iostream>
#include <math.h>
using namespace std;

long long dp[10001];

int main(){
    long long  N;
    cin >> N;
    N/=2;
    dp[0]=1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++){
            dp[i]+=(dp[j]*dp[i-1-j])%987654321;
            dp[i]%=987654321;
        }
    }
    cout << dp[N];
    
}
