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
    for(int i=0;i<=k;i++){
        acost[i] = 999999;
    }
    for(int i=0;i<n;i++){
        if(coin[i]<=10000){
            acost[coin[i]]=1;
        }
        
    }
    for(int i=1;i<=k;i++){
        tem = 999999;
        for(int j=0;j<n;j++){
            if(i>coin[j] && acost[i-coin[j]]!=0){
                tem = min(tem,acost[i-coin[j]]+1);
            }
        }
        if(tem!=999999){
            acost[i]=min(acost[i],tem);
        }
        
    }
    if(acost[k]!=999999){
        cout << acost[k];
    }
    else{
        cout << -1;
    }
    
    
}
