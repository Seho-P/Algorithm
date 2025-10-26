#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n,l,m;
    int temx,temy;
    int maxg=-1;
    cin >> n >> l >> m;
    vector<pair<int,int>> gogi;
    vector<pair<int,int>> mulidx;
    for(int i=0;i<m;i++){
        cin >> temx >> temy;
        gogi.push_back({temx,temy});
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            mulidx.push_back({gogi[i].first,gogi[j].second});
        }
    }
    pair<int,int> endidx = {n,n};
    for(auto gidx:mulidx){
        int temg=0;
        for(int i=1;i<(l/2);i++){
            pair<int,int> temidx = {gidx.first+i,gidx.second+l/2-i};
            if(1){
                for(auto nowidx:gogi){
                    if(gidx.first<=nowidx.first && gidx.second<=nowidx.second && nowidx.first<=temidx.first && nowidx.second<=temidx.second){
                        temg++;
                    }
            }    
            if(maxg<temg){
                maxg=temg;
            }
            temg=0;
            }
        }
    }
    cout << maxg;
}