#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int cnt = -1;
int dx[4] = {0,0,1,0};
int dy[4] = {0,1,-1,1};

void dfs(int n,int r,int c,int x,int y){
    int zlength = pow(2,n)/2;
    if(n==1){
        for(int i=0;i<4;i++){
            x +=dx[i];
            y +=dy[i];
            cnt++;
            if(x==r && y==c){
                cout << cnt;
            }
        }
    }
    else{
        for(int i=0;i<4;i++){
            x +=dx[i]*(zlength);
            y +=dy[i]*(zlength);
            if(x<=r && r<x+zlength && y<=c &&c<y+zlength){
                dfs(n-1,r,c,x,y);
            }
            else{
                cnt+=(zlength*zlength);
            }
        }
    }

}
int main(){
    int n,r,c;
    cin >> n >> r >> c;
    dfs(n,r,c,0,0);
}