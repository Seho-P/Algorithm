#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

vector<pair<int,int>> graph[1000];

void spanb(int start,int end){
    int dist[1001];
    for(int i=1;i<=1000;i++){
        dist[i] = INT_MAX;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    dist[start] = 0;
    while(!pq.empty()){
        int nowloc = pq.top().second;
        int nowcost = pq.top().first;
        pq.pop();
        if(dist[nowloc]<nowcost){
            continue;
        }
        for(int i=0;i<int(graph[nowloc].size());i++){
            int nextloc = graph[nowloc][i].first;
            int nextcost = graph[nowloc][i].second;
            if(dist[nextloc] > nowcost+nextcost){
                dist[nextloc] = nowcost + nextcost;
                pq.push({dist[nextloc],nextloc});
            }
        }
    }
    cout << dist[end];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int a,b,c;
    int start,end;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    cin >> start >> end;
    spanb(start,end);
    
}