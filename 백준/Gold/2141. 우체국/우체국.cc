#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> town;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long sump=0;
    int x,a;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> a;
        town.push_back({x,a});
        sump+= a;
    }
    long long midp = (sump+1)/2;
    long long curp=0;
    sort(town.begin(),town.end());
    for(auto now:town){
        curp+=now.second;
        if(curp>=midp){
            cout << now.first;
            break;
        }
    }
}