#include <iostream>
#include <queue>
using namespace std;

int all[100001];

int main(){
    int n,k;
    cin >> n >> k;
    deque<pair<int,int>> sba; 
    sba.push_back({n,0});
    while(1){
        auto tem = sba.front();
        sba.pop_front();
        if(tem.first==k){
            cout << tem.second;
            break;
        }
        if(tem.first*2<=100000 && all[tem.first*2]!=1){
            sba.push_front({tem.first*2,tem.second});
            all[tem.first*2]=1;
        }
        if(0<=tem.first-1 && all[tem.first-1]!=1){
            sba.push_back({tem.first-1,tem.second+1});
            all[tem.first-1]=1;
        }
        if(tem.first+1<=100000 && all[tem.first+1]!=1){
            sba.push_back({tem.first+1,tem.second+1});
            all[tem.first+1]=1;
        }
    }
}