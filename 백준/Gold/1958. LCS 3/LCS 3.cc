#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][101][101];

void lcs(string s1,string s2,string s3){
    string result = "";
    int slen = s1.size();
    int s2len = s2.size();
    int s3len = s3.size();
    for(int i=1;i<=slen;i++){
        for(int j=1;j<=s2len;j++){
            for(int l=1;l<=s3len;l++){
                if(s1[i-1]==s2[j-1] && s1[i-1]==s3[l-1]){
                dp[i][j][l] = dp[i-1][j-1][l-1] + 1;
            }
            else{
                dp[i][j][l] = max({dp[i][j-1][l],dp[i-1][j][l],dp[i][j][l-1]});
            }
            }
            
        }
    }
    cout << dp[slen][s2len][s3len];
}

int main(){
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    lcs(s1,s2,s3);
}