#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct fff{
    int a,start,end;
};
struct cmp{
    bool operator()(fff a,fff b){
        return a.end>b.end;
    }
};




bool cmpf(const fff a ,const fff b){
    return a.start<b.start;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int a,b,c;
    priority_queue<fff,vector<fff>,cmp> qq;
    vector<fff> allr;

    cin >> t;
    vector<int> result(t+1,-1);
    for(int i=0;i<t;i++){
        cin >> a >> b >> c;
        fff q = {a,b,c};
        allr.push_back(q);
    }
    sort(allr.begin(),allr.end(),cmpf);
    int lev = 0;
    for(int i=0;i<t;i++){
        fff q = allr[i];
        if(!qq.empty() && qq.top().end <= q.start ){
            result[q.a] = result[qq.top().a];
            qq.pop();
        }
        else{
            lev++;
            result[q.a] = lev;
        }
        qq.push(q);
    }
    cout << lev << "\n";
    for(int i=0;i<t;i++){
        cout << result[i+1] << "\n";
    }
}