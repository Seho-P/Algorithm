#include <iostream>
#include <climits>
using namespace std;

int maraton[501][2];
int dp[501][500];

int main(){
    int n,k;
    int mindis = 99999999;
    cin >> n >> k;
    dp[0][0] = 0;
    cin >> maraton[0][0] >> maraton[0][1];
    for(int i=1;i<n;i++){
        cin >> maraton[i][0] >> maraton[i][1];
        dp[i][0] = dp[i-1][0] + abs(maraton[i][0]-maraton[i-1][0]) + abs(maraton[i][1]-maraton[i-1][1]);
    }
    for(int i=0;i<n;i++){
        for(int p=1;p<=k;p++){
            dp[i][p] = 99999999;
        }
    }
    for(int i=0;i<n;i++){
        for(int p=0;p<=k;p++){
            for(int r=0;r<=k;r++){
                if(i-1-r<0)continue;
                if(p-r<0)continue;
                dp[i][p] = min(dp[i][p],dp[i-1-r][p-r]+abs(maraton[i-1-r][0]-maraton[i][0])+abs(maraton[i-1-r][1]-maraton[i][1]));
            }
        }
    }
    for(int i=0;i<=k;i++){
        if(mindis>dp[n-1][i]){
            mindis=dp[n-1][i];
        }
    }
    cout << mindis;
}