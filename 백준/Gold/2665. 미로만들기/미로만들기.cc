#include <iostream>
#include <queue>
using namespace std;

int miro[51][51];
int visited[51][51];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

struct xyr{
    int rank;
    int x,y;
    bool operator<(const xyr& other) const{
        return rank > other.rank;
    }
};


int main(){
    int n;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            miro[i][j] = s[j]-'0';
        }
    }
    priority_queue<xyr> q;
    q.push({1,0,0});
    visited[0][0] = 1;
    while(!q.empty()){
        if(visited[n-1][n-1]!=0){
            break;
        }
        int x = q.top().x;
        int y = q.top().y;
        int rank = q.top().rank;
        q.pop();
        for(int i=0;i<4;i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx<0 || xx>=n || yy<0 || yy>=n)continue;
            if(miro[xx][yy]==1 && visited[xx][yy]==0){
                q.push({rank,xx,yy});
                visited[xx][yy]=rank;
            }
            else if(miro[xx][yy] == 0 && visited[xx][yy]==0){
                q.push({rank+1,xx,yy});
                visited[xx][yy]=rank+1;
            }
        }
    }
    cout << visited[n-1][n-1]-1;
}