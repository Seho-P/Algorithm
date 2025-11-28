#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare1(pair<int,int> &a, pair<int,int> &b){
    return a.second>b.second;
}

int main(){
    vector<pair<int,int>> worktime;
    int n,t,s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>> t >> s;
        worktime.push_back({t,s});
    }
    sort(worktime.begin(),worktime.end(),compare1);
    int work = worktime[0].second;
    for(auto l:worktime){
        if(work>l.second){
            work= l.second;
        }
        work-=l.first;
    }
    if(work<0){
        cout << -1;
    }
    else{
        cout << work;
    }
}