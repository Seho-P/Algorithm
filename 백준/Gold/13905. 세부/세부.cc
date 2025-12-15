#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<pair<int,int>> graph[100001];
int best[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, e;
    cin >> n >> m >> s >> e;

    for(int i = 0; i < m; i++){
        int a, b, k;
        cin >> a >> b >> k;
        graph[a].push_back({k, b});
        graph[b].push_back({k, a});
    }

    priority_queue<pair<int,int>> pq;
    best[s] = INT_MAX;
    pq.push({best[s], s});

    while(!pq.empty()){
        auto [curW, cur] = pq.top();
        pq.pop();

        if(cur == e) {
            cout << curW;
            return 0;
        }

        if(curW < best[cur]) continue;

        for(auto &nx : graph[cur]){
            int w = nx.first;
            int next = nx.second;
            int nextW = min(curW, w);

            if(nextW > best[next]){
                best[next] = nextW;
                pq.push({nextW, next});
            }
        }
    }

    cout << 0;
}
