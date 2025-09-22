#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> gong;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,c,tem,sum;
    int result=0;
    cin >> n >> c;
    for(int i=0;i<n;i++){
        cin >> tem;
        gong.push_back(tem);
    }
    sort(gong.begin(),gong.end());
    int start =1;
    int end = gong[n-1] - gong[0];
    while(start<=end){
        int mid = (start+end)/2;
        int prev = gong[0];
        sum =1;
        for(int i=1;i<n;i++){
            if(gong[i]-prev>=mid){
                sum++;
                prev = gong[i];
            }
        }
        if(sum<c){
            end = mid-1;
        }
        else if(sum>=c){
            result = max(mid,result);
            start = mid+1;
        }
    }
    cout << result;
}
