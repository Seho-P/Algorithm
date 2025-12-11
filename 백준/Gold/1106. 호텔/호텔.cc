#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int city[20][2];
int dp[1111];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C,N;
    cin >> C >> N;
    int cost,customer;
    int result= 9999999;
    for(int i=0;i<N;i++){
        cin >> cost >> customer;
        city[i][0]=cost;
        city[i][1]=customer;
    }
    for(int i=0;i<=C+100;i++){
        dp[i] = 9999999;
    }
    dp[0]=0;
    for(int i=1;i<=C+100;i++){
        for(int j=0;j<N;j++){
            int nowco = city[j][0];
            int nowcu = city[j][1];
            if(nowcu<=i){
                dp[i] = min(dp[i],nowco+dp[i-nowcu]);
            }
        }
    }
    for(int i=C;i<=C+100;i++){
        result = min(result,dp[i]);
    }
    cout << result;
}
