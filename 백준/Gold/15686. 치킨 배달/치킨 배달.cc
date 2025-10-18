#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> chidx;
vector<pair<int,int>> hidx;
vector<int> chhsum[14];
vector<int> ressum[101];
int result = 25001;

void solve(int start,int m,int chnum,int hnum){
    if(m==0){
        int temres = 0;
        for(int i=0;i<hnum;i++){
            int temmin = 25001;
            for(int l:ressum[i]){
                temmin = min(temmin,l);
            }
            temres += temmin;
        }
        result = min(result,temres);
        return;
    }
    for(int i=start;i<chnum;i++){
        for(int j=0;j<hnum;j++){
            ressum[j].push_back(chhsum[i][j]);
        }
        solve(i+1,m-1,chnum,hnum);
        for(int j=0;j<hnum;j++){
            ressum[j].pop_back();
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    
    int tem,cnt;
    int chnum = 0;
    int hnum = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> tem;
            if(tem==2){
                chidx.push_back({i,j});
                chnum++;
            }
            else if(tem==1){
                hidx.push_back({i,j});
                hnum++;
            }
        }
    }
    cnt = 0;
    for(auto l:chidx){
        int cx = l.first;
        int cy = l.second;     
        for(auto k:hidx){
            chhsum[cnt].push_back(abs(k.first-cx) + abs(k.second-cy));
        }
        cnt++;
    }
    solve(0,m,chnum,hnum);
    cout << result;
}