#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int,int>> q;
int box[1001][1001];
int result=0;
int xpos[4] = {-1,1,0,0};
int ypos[4] = {0,0,1,-1};

int answer(int m,int n,int d){
    if(result == 0){
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int p=0;p<m;p++){
            if(box[p][i]==0){
                return -1;
            }
        }
    }
    return d-1;
}

int main(){
    int m,n;
    int tem;
    int d=1;
    pair<int,int> t;
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int p=0;p<m;p++){
            cin >> tem;
            box[p][i]=tem;
            if(tem==1){
                q.push({p,i});
            }
            else if(tem==0){
                result = -1;
            }
        }
    }
    if(result==0){
        while(!q.empty()) q.pop();
    }
    while(!q.empty()){
        t = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx = xpos[i] + t.first;
            int yy = ypos[i] + t.second;
            if(xx<0 || yy<0 || xx>=m || yy>=n)continue;
            if(box[xx][yy]==0){
                box[xx][yy] = box[t.first][t.second] + 1;
                q.push({xx,yy});
                if(d<box[xx][yy]){
                    d = box[xx][yy];
                }
            }
        }
    }
    cout << answer(m,n,d) << "\n";

}