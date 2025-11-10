#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int stone[1001][1001];
// int visited[1001][1001];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
    vector<vector<int>> visited(n+1,vector<int>(m+1,0));
    vector<int> a;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> stone[i][j];
        }
    }
    for(int i=0;i<m;i++){
        pq.push({stone[0][i],{0,i}});
        visited[0][i] = 1;
    }
    for(int i=1;i<n;i++){
        pq.push({stone[i][0],{i,0}});
        visited[i][0] = 1;
        pq.push({stone[i][m-1],{i,m-1}});
        visited[i][m-1] = 1;
    }
    for(int i=1;i<1000000;i++){
        while(!pq.empty()){
            auto tem = pq.top();
            int nowy = tem.second.first;
            int nowx = tem.second.second;
            int nowk = tem.first;
            if(nowk<=i){
                pq.pop();
                k--;
            }
            else break;
            for(int i=0;i<4;i++){
                int nextx = nowx + dx[i];
                int nexty = nowy + dy[i];
                if(nextx>=m || nextx<0 || nexty>=n || nexty<0)continue;
                if(!visited[nexty][nextx]){
                    visited[nexty][nextx] = 1;
                    pq.push({stone[nexty][nextx],{nexty,nextx}});
                }
            }
        }
    if(k<=0){
            cout << i ;
            break;
        }
    }
}
// 강도가 높을수록 돌을 많이캠 <-> 강도가 낮을수록 돌을 적게캠 