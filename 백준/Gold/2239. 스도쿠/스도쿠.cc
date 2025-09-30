#include <iostream>
using namespace std;

int sdoku[10][10];
int row[10][10];
int col[10][10];
int nemo[10][10];
int checkt = 1;

void dfs(int n){
    int x = n / 9;
    int y = n % 9;
    if(n==81 && checkt==1){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << sdoku[i][j];
            }
            cout << endl;
        }
        checkt=0;
        return;
    }
    if(checkt==0){
        return;
    }
    if(sdoku[x][y]==0){
        for(int i=1;i<=9;i++){
            if(row[x][i]==0 && col[y][i]==0 && nemo[(x/3)*3+(y/3)][i]==0){
                row[x][i] = 1;
                col[y][i] = 1;
                nemo[(x/3)*3+(y/3)][i]=1;
                sdoku[x][y] = i;
                dfs(n+1);
                row[x][i] = 0;
                col[y][i] = 0;
                nemo[(x/3)*3+(y/3)][i]=0;
                sdoku[x][y] = 0;
            }
        }
    }
    else{
        dfs(n+1);
    }
    
}

int main(){
    string s;
    for(int i=0;i<9;i++){
        cin >> s;
        for(int j=0;j<9;j++){
            sdoku[i][j] = s[j] - '0';
            if(sdoku[i][j]!=0){
                row[i][sdoku[i][j]]=1;
                col[j][sdoku[i][j]]=1;
                nemo[(i/3)*3+(j/3)][sdoku[i][j]]=1;
            }
        }
    }
    dfs(0);
}
