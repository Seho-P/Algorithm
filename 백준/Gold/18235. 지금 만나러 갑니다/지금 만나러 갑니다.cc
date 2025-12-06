#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int N,A,B;
int dy[] = {1,-1};
int visited[500001][2][20];

int main(){
    int result = -1;
    cin >> N >> A >> B;
    queue<pair<pair<int,int>,int>> ori;
    ori.push({{A,0},0});
    ori.push({{B,1},0});
    visited[A][0][0]=1;
    visited[B][1][0]=1;
    while(!ori.empty()){
        auto nowori = ori.front();
        if(nowori.second>20)break;
        int nowjump = pow(2,nowori.second);
        ori.pop();
        if(visited[nowori.first.first][0][nowori.second] && visited[nowori.first.first][1][nowori.second]){
            result = nowori.second;
            break;
        }
        for(int i=0;i<2;i++){
            int yy = nowori.first.first+nowjump*dy[i];
            if(yy<=0 || yy>N )continue;
                visited[yy][nowori.first.second][nowori.second+1]=1;
                ori.push({{yy,nowori.first.second},nowori.second+1});
        }
    }
    cout << result << endl;
}