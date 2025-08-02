#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> atm;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,tem;
    int sum = 0;
    int result = 0;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> tem;
        atm.push_back(tem);
    }
    sort(atm.begin(),atm.end());
    for(int i=0;i<n;i++){
        sum +=atm[i];
        result+=sum;
    }
    cout << result;
}