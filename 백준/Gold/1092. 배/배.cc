#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> crain;
vector<int> box;

int usedbox[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,tem;
    int crainmax = -1;
    int boxmax = -1;
    int cnt=0;
    int real=1;
    int result=0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> tem;
        if(crainmax<tem){
            crainmax = tem;
        }
        crain.push_back(tem);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> tem;
        if(boxmax<tem){
            boxmax = tem;
        }
        box.push_back(tem);
    }
    sort(crain.begin(),crain.end());
    sort(box.begin(),box.end());
    if(boxmax>crainmax){
        cout << -1;
    }
    else{
        while(real){
        real=0;
        for(int i=n-1;i>=0;i--){
            cnt = upper_bound(box.begin(),box.end(),crain[i]) - box.begin();
            while(0<=cnt && cnt<=m){
                if(cnt!=0){
                    cnt--;
                }
                if(usedbox[cnt]==0 && box[cnt]<=crain[i]){
                    usedbox[cnt]=1;
                    cnt=-1;
                }
                if(cnt==0){
                    cnt--;
                }
            }
        }
        result++;
        for(int i=0;i<m;i++){
            if(usedbox[i]==0){
                real=1;
            }
        }        
    }
    cout << result;
    }
    
}