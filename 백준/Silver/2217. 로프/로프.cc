#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> all;

bool compare(int a,int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,tem,result=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tem;
        all.push_back(tem);
    }
    sort(all.begin(),all.end(),compare);
    for(int i=0;i<n;i++){
        if(all[i]*(i+1)>result){
            result = all[i]*(i+1);
        }
    }
    cout << result << "\n";
}