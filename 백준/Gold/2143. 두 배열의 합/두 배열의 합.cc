#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long result;
int na[1000];
int ma[1000];
vector<long> asum;
vector<long> bsum;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long t,n,m;
    cin >> t >> n;
    for(int i=0;i<n;i++){
        cin >> na[i];
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> ma[i];
    }
    long sumav = 0;
    long sumbv = 0;
    for(int i=0;i<n;i++){
        sumav=na[i];
        asum.push_back(sumav);
        for(int j=i+1;j<n;j++){
            sumav+=na[j];
            asum.push_back(sumav);
        }
    }
    for(int i=0;i<m;i++){
        sumbv=ma[i];
        bsum.push_back(sumbv);
        for(int j=i+1;j<m;j++){
            sumbv+=ma[j];
            bsum.push_back(sumbv);
        }
    }
    sort(asum.begin(),asum.end());
    sort(bsum.begin(),bsum.end());
    for(long k:asum){
        auto kkl = lower_bound(bsum.begin(),bsum.end(),t-k);
        auto kkp = upper_bound(bsum.begin(),bsum.end(),t-k);
        if(kkl!=bsum.end()){
            if(t-k==bsum[kkl-bsum.begin()]){
                result+=(kkp-kkl);
            }
        }
    }
    cout << result;
}