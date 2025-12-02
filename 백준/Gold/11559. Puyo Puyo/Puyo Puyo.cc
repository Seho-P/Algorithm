#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char puyo[15][10];
int visited[15][10];
int result;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool bfs(int y,int x,char co){
    queue<pair<int,int>> p;
    vector<pair<int,int>> nowpu;
    int cnt=0;
    p.push({y,x});
    nowpu.push_back({y,x});
    while(!p.empty()){
        pair<int,int> tem = p.front();
        p.pop();
        cnt++;
        for(int i=0;i<4;i++){
            int yy = tem.first+dy[i];
            int xx = tem.second+dx[i];
            if(!visited[yy][xx] && puyo[yy][xx]==co){
                visited[yy][xx]=1;
                p.push({yy,xx});
                nowpu.push_back({yy,xx});
            }    
        }
    }
    if(cnt>=4){
        for(auto l: nowpu){
            puyo[l.first][l.second]='.';
        }
        return true;
    }
    return false;
}

bool pupu(){
    bool suc = false;
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            if(!visited[i][j]){
                visited[i][j]=1;
                if(bfs(i,j,puyo[i][j])){
                    suc = true;
                }
            }
        }
    }
    return suc;
}

void resetpuyo(){
    for(int i=0;i<6;i++){
        queue<pair<int,int>> emp;
        for(int j=11;j>=0;j--){
            if(puyo[j][i]=='.'){
                emp.push({j,i});
            }
            else{
                if(!emp.empty()){
                    auto l = emp.front();
                    emp.pop();
                    puyo[l.first][l.second] =  puyo[j][i];
                    visited[l.first][l.second] = 0;
                    puyo[j][i]='.';
                    emp.push({j,i});
                }
                else{
                    visited[j][i]=0;
                }
            }
        }
    }
}

int main(){
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin>> puyo[i][j];
            if(puyo[i][j]!='.'){
                visited[i][j]=0;
            }
            else{
                visited[i][j]=1;
            }
        }
    }
    while(1){
        if(pupu()){
            result++;
            resetpuyo();
        }
        else{
            break;
        }
    }
    cout << result;
}