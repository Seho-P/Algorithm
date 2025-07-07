#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> hg[101];
int visited[101];
int result = 0;
int realresult =0;

void dfs(int h1,int h2){
    if(h1==h2){
        realresult = result;
    }
    for(int k:hg[h1]){
        if(!visited[k]){
            visited[k] = 1;
            result++;
            dfs(k,h2);
            result--;
        }
    }
}

int main(){
    int n;
    int h1,h2;
    int m;
    int x,y;
    cin >> n;
    cin >> h1 >> h2;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y ;
        hg[x].push_back(y);
        hg[y].push_back(x);
    }
    visited[h1] = 1;
    dfs(h1,h2);
    if( realresult){
        cout << realresult << "\n";
    }
    else{
        cout << -1 << "\n";
    }

}