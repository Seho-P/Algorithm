#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result[6][3];
vector<pair<int,int>> games;

bool dfs(int idx){
    if(idx==15){
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                if(result[i][j]!=0)return false;
            }
        }
        return true;
    }
    int a = games[idx].first;
    int b = games[idx].second;
    if(result[a][0]>0 && result[b][2]>0){
        result[a][0]--;
        result[b][2]--;
        if(dfs(idx+1))return true;
        result[a][0]++;
        result[b][2]++;
    }
    if(result[a][1]>0 && result[b][1]>0){
        result[a][1]--;
        result[b][1]--;
        if(dfs(idx+1))return true;
        result[a][1]++;
        result[b][1]++;
    }
    if(result[a][2]>0 && result[b][0]>0){
        result[a][2]--;
        result[b][0]--;
        if(dfs(idx+1))return true;
        result[a][2]++;
        result[b][0]++;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int su,dr,fa;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            games.push_back({i,j});
        }
    }
    for(int i=0;i<4;i++){
        for(int p=0;p<6;p++){
            cin  >> su >> dr >> fa;
            result[p][0]=su;
            result[p][1]=dr;
            result[p][2]=fa;
        }
        if(dfs(0))cout << "1 ";
        else cout << "0 ";
    }
}


