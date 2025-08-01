#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pc;
// end , pc[int]
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> emptypc;
vector<pair<int,int>> all;
// start,end
vector<int> result;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int start,end;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> start >> end;
        all.push_back({start,end});
    }
    sort(all.begin(),all.end());
    emptypc.push({0,0});
    result.push_back(0);
    for(int i=0;i<n;i++){
        while(!pc.empty() && all[i].first > pc.top().first){
            emptypc.push({0,pc.top().second});
            pc.pop();
        }
         
        if(!emptypc.empty()){
            pc.push({all[i].second,emptypc.top().second});
            result[emptypc.top().second]++;
            emptypc.pop();
        }
        else{
            pc.push({all[i].second,pc.size()});
            result.push_back(1);
        }
    }
    cout << result.size() << "\n";
    for(int i=0;i<int(result.size());i++){
        cout << result[i] << " ";
    }

}