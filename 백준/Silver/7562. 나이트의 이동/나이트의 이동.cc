#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int xpos[8] = {-1,-2,-2,-1,1,2,2,1};
int ypos[8] = {2,1,-1,-2,-2,-1,1,2};
using k = pair<int,int>;
queue<k> graph;
int result[301][301];
int visited[301][301];

int main(){
    int t,l;
    int startx,starty;
    int endx,endy;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> l;
        cin >> startx >> starty;
        cin >> endx >> endy;
        graph.push({startx,starty});
        visited[startx][starty] = 1;
        while(!graph.empty()){
            k tem = graph.front();
            if(tem.first == endx && tem.second == endy){
                while(!graph.empty()){
                    graph.pop();
                }
                break;
            }
            graph.pop();
            for(int p=0;p<8;p++){
                int xx = tem.first + xpos[p];
                int yy = tem.second + ypos[p];
                if(xx < 0 || yy>=l || xx>=l || yy<0)continue;
                if(visited[xx][yy] == 0){
                    result[xx][yy] = result[tem.first][tem.second] + 1;
                    visited[xx][yy] = 1;
                    graph.push({xx,yy});
                }
            }
        }
        cout << result[endx][endy] << "\n";
        fill(result[0],result[301],0);
        fill(visited[0],visited[301],0);
    } 
}