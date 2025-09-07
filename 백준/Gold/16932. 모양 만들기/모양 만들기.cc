#include <iostream>
using namespace std;

int n,m,num;
int nu=2;

int all[1001][1001];
int visit[1001][1001];

int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};

void dfs(int i,int p){
    visit[i][p]=1;
    for(int r=0;r<4;r++){
        int x = i+xx[r];
        int y = p+yy[r];
        if(x<0 || x>=n || y<0 || y>=m || visit[x][y]==1){
            continue;
        }
        if(all[x][y]==1){
            num++;
            dfs(x,y);
        }
    }
    return;
}

void dfsc(int i,int p,int num){
    visit[i][p]=nu;
    all[i][p]=num;
    for(int r=0;r<4;r++){
        int x = i+xx[r];
        int y = p+yy[r];
        if(x<0 || x>=n || y<0 || y>=m || visit[x][y] == 0){
            continue;
        }
        if(all[x][y]==1 && visit[x][y]==1){
            dfsc(x,y,num);
        }
    }
    return;
}

int main(){

    cin >> n>>m;
    int max=-1;
    for(int i=0;i<n;i++){
        for(int p=0;p<m;p++){
            cin >> all[i][p];
        }
    }
    for(int i=0;i<n;i++){
        for(int p=0;p<m;p++){
            if(all[i][p]==1){
                num=1;
                dfs(i,p);
                if(num>=1){
                    dfsc(i,p,num);
                    nu++;
                }
            }
        }
    }
    int sum;
    int co[4];
    int cn=0;
    int real=0;
    for(int i=0;i<n;i++){
        for(int p=0;p<m;p++){
            if(all[i][p]==0){
                sum =0;
                for(int r=0;r<4;r++){
                    int x = i+xx[r];
                    int y = p+yy[r];
                    co[r] = -r-1;
                    if(x>=0 && x<n && y>=0 && y<m ){
                        real =0;
                        co[r] = visit[x][y];
                        for(int k=0;k<r;k++){
                            if(co[k]==co[r]){
                                real=1;
                                break;
                            }
                        }
                        if(real==0){
                            sum+= all[x][y];
                        }
                    }
                    
                }
                
                if(sum+1>max){
                    
                    max = sum+1;
                }
            }
        }
    }
    cout << max;
}