#include <iostream>
#include <vector>
using namespace std;

int n;
int result;
int alltree=0;
int visited[100001];
vector<pair<int,int>> stree(100001);

void dfs(int x){
    // cout << alltree << " " << x << endl ;
    if(visited[x]==1){
        if(alltree==n){
            cout << result;
            return;
        }
    }
    int nowl = stree[x].first;
    int nowr = stree[x].second;
    if(nowl!= -1 && visited[nowl]==0){
        result++;
        dfs(nowl);
        result++;
    }
    if(visited[x]==0){
        visited[x]=1;
        alltree++;
        if(alltree==n){
            cout << result;
            return;
        }
    }
    if(nowr!=-1 && visited[nowr]==0){
        result++;
        dfs(nowr);
        result++;
    }
}

int main(){
    int a,b,c;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        stree[a] = {b,c}; 
    }
    dfs(1);
}