#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int,int>> house[100001];
int visited[100001];
int result = 99999999;
bool check = true;

int main(){
    int n,m,s,e;
    int h1,h2,k;
    cin >> n >> m >> s >> e;
    for(int i=0;i<m;i++){
        cin >> h1 >> h2 >> k;
        house[h1].push_back({k,h2});
        house[h2].push_back({k,h1});
    }
    priority_queue<pair<int,int>> housek;
    housek.push({result,s});
    while(!housek.empty()){
        int nowk = housek.top().first;
        int nowh = housek.top().second;
        housek.pop();
        if(visited[nowh])continue;
        visited[nowh]=1;
        result = min(result,nowk);
        if(nowh==e)break;
        // cout << nowh << nowk<<endl;
        
        for(int i=0;i<int(house[nowh].size());i++){
            if(visited[house[nowh][i].second]==0){
                housek.push({house[nowh][i].first,house[nowh][i].second});
            }
        }
        
    }
    if(visited[e])cout <<result;
    else cout << 0;
}