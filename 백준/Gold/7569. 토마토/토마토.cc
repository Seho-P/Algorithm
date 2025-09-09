#include <iostream>
#include <queue>
using namespace std;

struct toma
{
    int m;
    int n;
    int h;
};
int tomato[101][101][101];
int visitied[101][101][101];
queue<toma> ikt;
int xx[6] = {1,-1,0,0,0,0};
int yy[6] = {0,0,1,-1,0,0};
int zz[6] = {0,0,0,0,1,-1}; 

int main(){
    int m,n,h;
    int result=0;
    int zn = 0;
    bool zp;
    cin >> m >> n >>h;
    for(int i=0;i<h;i++){
        for(int p=0;p<n;p++){
            for(int q=0;q<m;q++){
                cin >> tomato[q][p][i];
                if(tomato[q][p][i]==1){
                    visitied[q][p][i]=1;
                    ikt.push({q,p,i});
                }
                else if(tomato[q][p][i]==0){
                    zn++;
                }
            }
        }
    }
    
    while(1){
        if(zn==0){
            break;
        }
        zp = true;
        int ikitsize = ikt.size(); 
        for(int i=0;i<ikitsize;i++){
            toma a = ikt.front();
            ikt.pop();
            for(int p=0;p<6;p++){
                int x = a.m + xx[p];
                int y = a.n + yy[p];
                int z = a.h + zz[p];
                if(x<0 || x>=m || y<0 || y>=n || z<0 || z>=h || visitied[x][y][z]==1)continue;
                if(tomato[x][y][z]==0){
                    tomato[x][y][z]=1;
                    visitied[x][y][z]=1;
                    ikt.push({x,y,z});
                    zn--;
                    zp=false;
                }
            }
        }
        if(zp){
            break;
        }
        result++;
        
    }
    if(zn==0){
        cout << result;
    }
    else{
        cout << -1;
    }
    
}