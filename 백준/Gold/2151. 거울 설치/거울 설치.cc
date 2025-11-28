#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

char house[51][51];
int dist[51][51][4];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Node{
    int y, x, dir, cost;
    bool operator<(const Node& other) const{
        return cost > other.cost; // 최소 힙
    }
};

int main(){

    int n;
    cin >> n;

    vector<pair<int,int>> door;
    string s;

    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            house[i][j] = s[j];
            if(house[i][j] == '#') door.push_back({i,j});
        }
    }

    auto [sy, sx] = door[0];
    auto [ey, ex] = door[1];

    // 거리 배열 초기화
    for(int y=0;y<n;y++)
        for(int x=0;x<n;x++)
            for(int d=0;d<4;d++)
                dist[y][x][d] = 1e9;

    priority_queue<Node> pq;

    // 시작 지점: 네 방향 전부 0으로 시작
    for(int d=0;d<4;d++){
        dist[sy][sx][d] = 0;
        pq.push({sy, sx, d, 0});
    }

    while(!pq.empty()){
        Node cur = pq.top();
        pq.pop();

        int y = cur.y;
        int x = cur.x;
        int dir = cur.dir;
        int cost = cur.cost;

        if(cost > dist[y][x][dir]) continue;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(house[ny][nx] == '*') continue;

        // 도착
        if(ny == ey && nx == ex){
            cout << cost;
            return 0;
        }

        // 직진
        if(dist[ny][nx][dir] > cost){
            dist[ny][nx][dir] = cost;
            pq.push({ny, nx, dir, cost});
        }

        // 거울 설치 가능한 위치면 방향 전환
        if(house[ny][nx] == '!'){
            if(dir <= 1){
                // 상/하 → 좌/우
                for(int nd : {2,3}){
                    if(dist[ny][nx][nd] > cost + 1){
                        dist[ny][nx][nd] = cost + 1;
                        pq.push({ny, nx, nd, cost + 1});
                    }
                }
            }else{
                // 좌/우 → 상/하
                for(int nd : {0,1}){
                    if(dist[ny][nx][nd] > cost + 1){
                        dist[ny][nx][nd] = cost + 1;
                        pq.push({ny, nx, nd, cost + 1});
                    }
                }
            }
        }
    }

    return 0;
}