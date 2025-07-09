#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<long,long>> q;

long bfs(long b){
    while(!q.empty()){
        pair<long,long> tem = q.front();
        q.pop();
        if(tem.first*2<=b){ 
            if(tem.first*2==b)return tem.second+1;
            q.push({tem.first*2,tem.second+1});
        }
        if(tem.first*10 + 1 <=b){
            if(tem.first*10 + 1==b)return tem.second+1;
            q.push({tem.first*10 + 1,tem.second+1});
        }
    }
    return -1;
}

int main(){
    long a,b;
    cin >> a >> b;
    q.push({a,1});
    
    cout << bfs(b)<<"\n";
}