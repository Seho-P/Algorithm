#include <iostream>
#include <algorithm>
using namespace std;

int podo[10001];
int result[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> podo[i];
    }
    result[1]= podo[1];
    result[2]= podo[1] + podo[2];
    for(int i=3;i<=n;i++){
        result[i] = max({result[i-1],result[i-2]+podo[i],result[i-3]+podo[i-1]+podo[i]});
    }
    cout << result[n] << "\n";
}