#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> elecline;
int dp[501];

int main(){
    int n;
    int a,b;
    int emax = -1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        elecline.push_back({a,b});
    }
    sort(elecline.begin(),elecline.end());
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(elecline[i].second>elecline[j].second){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        emax = max(emax,dp[i]);
    }
    cout << n - emax;
    
}