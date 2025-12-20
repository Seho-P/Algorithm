#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int laba[51][51];
int visited[51][51];
vector<pair<int,int>> virus1;
vector<pair<int,int>> virusgo;
int result = 9999;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


int bfs(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]!=-1){
                visited[i][j]=0;
            }
        }
    }
    queue<pair<int,int>> temvi;
    for(auto l:virusgo){
        temvi.push(l);
        visited[l.first][l.second]=1;
    }
    while(!temvi.empty()){
        auto l = temvi.front();
        temvi.pop();
        for(int i=0;i<4;i++){
            int yy = l.first+dy[i];
            int xx = l.second+dx[i];
            if(yy<0 || xx <0 || yy>=N || xx>=N)continue;
            if(visited[yy][xx]==0){
                visited[yy][xx]=visited[l.first][l.second]+1;
                temvi.push({yy,xx});
            }
        }
    }
    int maxtime = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(laba[i][j]==0){
                if(visited[i][j]==0){
                    return -1;
                }
                else{
                    maxtime = max(maxtime,visited[i][j]);
                }
            }
        }
    }
    return maxtime-1;
}

void selecvirus(int start,int cnt){
    if(cnt==M){
        int tem = bfs();
        if(tem!=-1){
            result = min(result,tem);
        }
        return;
    }
    for(int i=start;i<=int(virus1.size())-M+cnt;i++){
        virusgo.push_back(virus1[i]);
        selecvirus(i+1,cnt+1);
        virusgo.pop_back();
    }
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> laba[i][j];
            if(laba[i][j]==2){
                virus1.push_back({i,j});
            }
            else if(laba[i][j]==1){
                visited[i][j]=-1;
            }
        }
    }
    selecvirus(0,0);
    if(result==9999)cout<<-1;
    else cout << result;
}

//bfs로