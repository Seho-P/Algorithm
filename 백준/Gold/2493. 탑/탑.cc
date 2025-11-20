#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> htop(n);
    vector<int> ltop(n);
    for(int i=0;i<n;i++){
        cin >> htop[i];
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> toplist;
    toplist.push({htop[n-1],n-1});
    for(int i=n-2;i>=0;i--){
        while(!toplist.empty()){
            if(htop[i]>toplist.top().first){
                ltop[toplist.top().second] = i+1;
                toplist.pop();
            }
            else{
                break;
            }
        }
        toplist.push({htop[i],i});
    }
    while(!toplist.empty()){
        ltop[toplist.top().second]=0;
        toplist.pop();
    }
    for(int i=0;i<n;i++){
        cout << ltop[i] << " ";
    }
}
