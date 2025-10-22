#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> graph[10001];
int visited[10001];
int max1 = 0;
int nidx = 0;

void dfs(int n,int res){
    visited[n] = 1;
    if(graph[n].size()==1 && res!=0){
        if(max1<res){
            max1=res;
            nidx = n;
        }
        visited[n]=0;
    }
    else{
        for(auto l:graph[n]){
            if(visited[l.first]==0){
                dfs(l.first,res+l.second);
            }
        }
    visited[n]=0;
    }
    
}

int main(){
    int n;
    int a,b,c;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> a >> b >>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dfs(1,0);
    dfs(nidx,0);
    cout << max1 ;
}