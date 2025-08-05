#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

vector<pair<int,int>> all;
priority_queue<int,vector<int>,greater<>> classroom;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,tem1,tem2;
    int sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tem1 >> tem2;
        all.push_back({tem1,tem2});
    }
    sort(all.begin(),all.end());
    classroom.push(all[0].second);
    sum++;
    for(int i=1;i<n;i++){
        while(classroom.top()<=all[i].first && !classroom.empty()){
            classroom.pop();
        }
        classroom.push(all[i].second);
        if(int(classroom.size())>sum){
            sum = classroom.size();
        }
    }
    cout << sum;    
}