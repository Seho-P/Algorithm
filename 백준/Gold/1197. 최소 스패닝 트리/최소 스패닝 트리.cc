#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,pair<int,int>> t;
vector<t> graph;
int parents[10001];

int findp(int a){
    if(parents[a] == a) return a;
    return parents[a] = findp(parents[a]);
}

void unionp(int a,int b){
    a = findp(a);
    b = findp(b);
    parents[b] = a;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v,e;
    int a,b,c;
    int result = 0;
    cin >> v >> e;
    for(int i=1;i<=e;i++){
        cin >> a >> b >> c;
        graph.push_back({c,{a,b}});
    }
    for(int i=1;i<=v;i++){
        parents[i]=i;
    }
    sort(graph.begin(),graph.end());
    for(auto &edge : graph){
        int c = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(findp(u) != findp(v)){
            unionp(u,v);
            result += c;
        }
    }
    cout << result << "\n";
}