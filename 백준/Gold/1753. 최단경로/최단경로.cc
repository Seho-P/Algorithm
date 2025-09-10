#include <iostream>
#include <algorithm>
#include <climits>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int,int>> graph[20001];

void gogo(int k,int V){
    int ww[V+1];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=1;i<=V;i++){
        ww[i] = INT_MAX;
    }
    ww[k] = 0;
    pq.push({0,k});
    while(!pq.empty()){
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        for(int i=0;i<int(graph[v].size());i++){
            int nextv = graph[v][i].first;
            int nextw = graph[v][i].second;
            if(ww[nextv]>w+nextw){
                ww[nextv] = w + nextw;
                pq.push({ww[nextv],nextv});
            }
        }
    }
    
    for(int i=1;i<=V;i++){
        if(ww[i]==INT_MAX){
            cout << "INF" << "\n";
        }
        else{
            cout << ww[i] << "\n";
        }
    }
}



int main(){
    int u,v,w;
    int V,e;
    int k;
    cin >> V >> e;
    cin >> k;
    
    for(int i=0;i<e;i++){
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    gogo(k,V);
}