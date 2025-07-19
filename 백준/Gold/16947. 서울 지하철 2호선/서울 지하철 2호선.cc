#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int,int>> trains;
vector<int> train[3001];
int visitid[3001];
int cycles[3001];

void cycle(int now,int first,int num){
    visitid[now] = 1;
    for(int k:train[now]){
        if(visitid[k]!=1){
            cycle(k,first,num+1);
        }
        else{
            if(num>=2 && k == first){
                cycles[first] = 1;
                visitid[now] = 0 ;
                return;
            }
        }
    }
    visitid[now] = 0;
}
int bfs(int first,int num){
    if(cycles[first]){
        return 0;
    }
    visitid[first] = 1;
    trains.push({first,0});
    while(!trains.empty()){
        int now = trains.front().first;
        int nown = trains.front().second;
        trains.pop();
        for(int k:train[now]){
            if(!visitid[k]){
                trains.push({k,nown+1});
                visitid[k] = 1;
            }
            if(cycles[k]){
                while(!trains.empty()){
                    trains.pop();
                }
                return nown+1;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    int a,b;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        train[a].push_back(b);
        train[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        cycle(i,i,0);
    }
    for(int i=1;i<=n;i++){
        fill(visitid,visitid+n+1,0);
        cout << bfs(i,0) << " ";
    }

}