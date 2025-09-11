#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int virus[9][9];
int visited[9][9];
vector<pair<int,int>> zeroidx;
queue<pair<int,int>> virusidx;

int x[4] = {0,0,-1,1};
int y[4] = {1,-1,0,0};

int main(){
    int n,m;
    cin >> n >>m;
    for(int i=0;i<n;i++){
        for(int p=0;p<m;p++){
            cin >> virus[i][p];
            if(virus[i][p]==0){
                zeroidx.push_back({i,p});
            }
            else if(virus[i][p]==2){
                virusidx.push({i,p});
                visited[i][p] = 1;
            }
            else{
                visited[i][p] = 1;
            }
        }
    }

    int visitedcopy[9][9];
    queue<pair<int,int>> virusidxcopy;
    int min = 100;
    
    for(int i=0;i<int(zeroidx.size())-2;i++){
        for(int p=i+1;p<int(zeroidx.size())-1;p++){
            for(int q=p+1;q<int(zeroidx.size());q++){
                memcpy(visitedcopy,visited,sizeof(visited));
                virusidxcopy = virusidx;
                int cnt = 0;
                visitedcopy[zeroidx[i].first][zeroidx[i].second] = 1;
                visitedcopy[zeroidx[p].first][zeroidx[p].second] = 1;
                visitedcopy[zeroidx[q].first][zeroidx[q].second] = 1;
                while(!virusidxcopy.empty()){
                    int a = virusidxcopy.front().first;
                    int b = virusidxcopy.front().second;
                    virusidxcopy.pop();
                    for(int r=0;r<4;r++){
                        int xx = a+x[r];
                        int yy = b+y[r];
                        if(xx<0 || xx>=n || yy<0 || yy>=m || visitedcopy[xx][yy]==1)continue;
                        visitedcopy[xx][yy]=1;
                        virusidxcopy.push({xx,yy});
                        cnt++;      
                    }
                }
                if(min>cnt){
                    min = cnt;
                }
            }
        }
    }
    cout << zeroidx.size()-min-3;
}