#include <iostream>
#include <vector>
using namespace std;

int sdoku[10][10];
int row[10][10];
int col[10][10];
int box[10][10];
int checkct=1;

void solve(int n){
    int x = n/9;
    int y = n%9;
    if(n==81 && checkct==1){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << sdoku[i][j] << " ";
            }
            cout << "\n";
        }
        checkct=0;
    }
    if(checkct==0){
        return;
    }
    if(sdoku[x][y]==0){
        for(int i=1;i<=9;i++){
            if(row[x][i]==0 && col[y][i]==0 && box[(x/3)*3+(y/3)][i]==0){
                row[x][i] = 1;
                    col[y][i] = 1;
                    box[(x/3)*3+(y/3)][i]=1;
                    sdoku[x][y] = i;
                    solve(n+1);
                    row[x][i] = 0;
                    col[y][i] = 0;
                    box[(x/3)*3+(y/3)][i]=0;
                    sdoku[x][y] = 0;
            }
    }
    }
    else{
        solve(n+1);
    }
    
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> sdoku[i][j];
            if(sdoku[i][j]!=0){
                row[i][sdoku[i][j]]=1;
                col[j][sdoku[i][j]]=1;
                box[(i/3)*3+(j/3)][sdoku[i][j]]=1;
            }
            
        }
    }
    solve(0);
}