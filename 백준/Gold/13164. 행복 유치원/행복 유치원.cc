#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dif;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    int bf,af;
    int result = 0;
    cin >> n >> k;
    cin >> bf;
    for(int i=0;i<n-1;i++){
        cin >> af;
        dif.push_back(af-bf);
        bf  = af;
    }
    sort(dif.begin(),dif.end());
    for(int i=0;i<n-k;i++){
        result+= dif[i];
    }
    cout << result;
}