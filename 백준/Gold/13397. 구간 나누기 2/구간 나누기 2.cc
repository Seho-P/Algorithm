#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> alln;
vector<int> result;

int checknum(int mid){
    int cnt = 0;
    int max = 0;
    int min = 10001;
    for(int k=0;k<int(alln.size());k++){
        if(max<alln[k]){
            max = alln[k];
        }
        if(min>alln[k]){
            min = alln[k];
        }
        if(max-min>mid){
            cnt++;
            min = alln[k];
            max = alln[k];
        }
        if(k==int(alln.size())-1){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n,m,tem;
    cin >> n >> m ;
    for(int i=0;i<n;i++){
        cin >> tem;
        alln.push_back(tem);
    }
    int l=0;
    int r=20000;
    while(l<r){
        int mid = (l+r)/2;
        if(checknum(mid)>m){
            l= mid+1;
        }
        else if(checknum(mid)<=m){
            r = mid;
            result.push_back(mid);
        }
    }
    sort(result.begin(),result.end());
    cout << result[0];
}
// mid가 작아지면 구간이 많아짐
// mid가 커지면 구간이 적어짐 
// 구간 1 = 짱큼 , 구간 100 : 짱 작음 
// 목표 : 구간 m개 이하에서 최소 mid 구하기 