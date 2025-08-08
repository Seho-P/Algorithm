#include <iostream>
#include <vector>
using namespace std;

vector<int> coin;

int main(){
    int n,k,tem;
    int cnt = 0;
    int sum = 0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> tem;
        coin.push_back(tem);
    }
    for(int i=n-1;i>=0;i--){
        if(sum==k){
            break;
        }
        if(coin[i]<=k){
            while(1){
                if(sum+coin[i]<=k){
                    sum+=coin[i];
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
    }
    cout << cnt;
}