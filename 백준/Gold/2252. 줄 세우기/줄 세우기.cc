#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> alln[32001];
int visited[32001];

void tsology(int n){
    queue<int> pq;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int nown = pq.front();
        cout << nown << " ";
        pq.pop();
        for(int k:alln[nown]){
            visited[k]--;
            if(visited[k]==0){
                pq.push(k);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int tf,tb;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> tf >> tb;
        alln[tf].push_back(tb);
        visited[tb]++;
    }
    tsology(n);
}


