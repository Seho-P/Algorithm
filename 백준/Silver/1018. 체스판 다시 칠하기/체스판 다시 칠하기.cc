#include <iostream>
#include <algorithm>
using namespace std;

char pchess[51][51];

string wb[9]={
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
                };

string bw[9]={
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
                };               

int main(){
    int n,m;
    string tem;
    int minsq = 70;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tem;
        for(int j=0;j<int(tem.size());j++){
            pchess[i][j] = tem[j];
        }
    }
    for(int i=0;i<=n-8;i++){
        for(int p=0;p<=m-8;p++){
            int cnt1=0;
            int cnt2=0;
            for(int j=i;j<i+8;j++){
                for(int q=p;q<p+8;q++){
                    if(wb[j-i][q-p]!=pchess[j][q]){
                        cnt1++;
                    }
                    if(bw[j-i][q-p]!=pchess[j][q]){
                        cnt2++;
                    }
                }
            }
            minsq = min({minsq,cnt1,cnt2});
        }
    }
    cout << minsq;
}