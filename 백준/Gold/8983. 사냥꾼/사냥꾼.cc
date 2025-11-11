#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int m,n,l;
    int result = 0;
    cin >> m >> n >>l;
    vector<int> gunidx(m);
    vector<pair<int,int>> aniidx(n);
    for(int i=0;i<m;i++){
        cin >> gunidx[i];
    }
    int temx,temy;
    for(int i=0;i<n;i++){
        cin >> temx >> temy;
        aniidx[i] = {temx,temy};
    }
    sort(gunidx.begin(),gunidx.end());
    sort(aniidx.begin(),aniidx.end());
    int nowgidx = 0;
    int nowaidx = 0;
    while(nowgidx<m && nowaidx<n){
        int nowgun = gunidx[nowgidx];
        pair<int,int> nowani = aniidx[nowaidx];
        if(abs(nowani.first-nowgun)+nowani.second<=l){
            result++;
            nowaidx++;
        }
        else{
            if(nowgun<nowani.first){
                nowgidx++;
            }
            else{
                nowaidx++;
            }
        }
    }
    cout << result;
}

