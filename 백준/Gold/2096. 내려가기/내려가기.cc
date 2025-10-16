#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int a,b,c;
    cin >> n;
    int dg[6];
    int dp[6];
    cin >> dg[0] >> dg[1] >> dg[2];
    dg[3] = dg[0];
    dg[4] = dg[1];
    dg[5] = dg[2];
    
    for(int i=1;i<n;i++){
        cin >> a >> b >> c;

        dp[0]=a + max(dg[0],dg[1]);
        dp[1]=b + max({dg[0],dg[1],dg[2]});
        dp[2]=c + max(dg[1],dg[2]);

        dp[3]=a + min(dg[3],dg[4]);
        dp[4]=b + min({dg[3],dg[4],dg[5]});
        dp[5]=c + min(dg[4],dg[5]);

        dg[0]=dp[0];
        dg[1]=dp[1];
        dg[2]=dp[2];
        dg[3]=dp[3];
        dg[4]=dp[4];
        dg[5]=dp[5];


    }

    cout << max({dg[0],dg[1],dg[2]}) << " ";

    cout << min({dg[3],dg[4],dg[5]});
}