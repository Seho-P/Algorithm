#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long m,n,l;
    long result = 0;
    cin >> m >> n >>l;
    vector<long> gunidx(m);
    vector<pair<long,long>> aniidx(n);
    for(int i=0;i<m;i++){
        cin >> gunidx[i];
    }
    long temx,temy;
    for(int i=0;i<n;i++){
        cin >> temx >> temy;
        aniidx[i] = {temx,temy};
    }
    sort(gunidx.begin(),gunidx.end());
    sort(aniidx.begin(),aniidx.end());
    for(auto now:aniidx){
        auto ridx = lower_bound(gunidx.begin(),gunidx.end(),now.first) - gunidx.begin();
        auto lidx = ridx-1;
        if(ridx < m && abs(gunidx[ridx]-now.first)+now.second<=l){
            result++;
        }
        else{
            if(lidx>=0 && abs(gunidx[lidx]-now.first)+now.second<=l){
                result++;
            }
        }
    
    }
    cout << result;
}
