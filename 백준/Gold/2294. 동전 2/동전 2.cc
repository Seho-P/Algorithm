#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int acost[10001];

int main(){
    int n,k,tem;
    cin >> n >> k;
    vector<int> coin;
    for(int i=0;i<n;i++){
        cin >> tem;
        coin.push_back(tem);
    }
    sort(coin.begin(),coin.end());
    for(int i=1;i<=k;i++){
        acost[i] = 999999;
    }
    for(int i=0;i<n;i++){
        for(int j=coin[i];j<=k;j++){
            acost[j] = min(acost[j],acost[j-coin[i]]+1);
        }
        
    }
    if(acost[k]!=999999){
        cout << acost[k];
    }
    else{
        cout << -1;
    }
    
    
}
