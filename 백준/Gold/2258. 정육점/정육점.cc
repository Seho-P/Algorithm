#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(pair<int,int> &a,pair<int,int> &b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}

int main(){
    int n,m;
    int cost,weight;
    int allweight = 0;
    cin >> n >> m;
    vector<pair<int,int>> meat;
    for(int i=0;i<n;i++){
        cin >> weight >> cost;
        meat.push_back({cost,weight});
    }
    meat.push_back({-1,0});
    sort(meat.begin(),meat.end(),Compare);
    int left=0;
    cost = meat[0].first;
    int result=-1;
    int temresult=0;
    // for(int i=0;i<=n;i++){
    //     cout << meat[i].first << " " << meat[i].second << endl;
    // }
    while(1){
        left++;
        if(left==n+1){
            break;
        }
        else if(allweight<m){
            if(cost!=meat[left].first){
                allweight+=meat[left].second;
                cost = meat[left].first;
                temresult=cost;
                if(allweight>=m){
                    result = temresult;
                }
            }
            else{
                allweight+=meat[left].second;
                cost = meat[left].first;
                temresult+=cost;
                if(allweight>=m){
                    result = temresult;
                }
            }
            
        }
        else if(allweight>=m){
            if(cost!=meat[left].first){
                result = min(result,meat[left].first);
                break;
            }
        }
    }
    cout << result;
}