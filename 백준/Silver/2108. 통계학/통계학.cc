#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int pl[8001];

int main(){
    double n;
    int min=4001;
    int max=-4001;
    double sum=0;
    int cnt=-1,cnt2=0,cntres=0,cnt2res;
    cin >> n;
    vector<int> tong(n);
    for(int i=0;i<n;i++){
        cin>> tong[i];
        sum+=tong[i];
        pl[4000+tong[i]]++;
        if(tong[i]<min){
            min = tong[i];
        }
        if(tong[i]>max){
            max = tong[i];
        }
    }
    cout<<int(round(sum/n)) << "\n";
    sort(tong.begin(),tong.end());
    cout<<tong[n/2] << "\n";
    for(int i=0;i<=8000;i++){
        if(cnt<pl[i]){
            cnt=pl[i];
            cntres=i-4000;
            cnt2=0;
        }
        else if(cnt==pl[i] && cnt2==0){
            cnt2res=i-4000;
            cnt2++;
        }
    }
    if(cnt2>=1){
        cout << cnt2res << "\n";
    }
    else{
        cout << cntres<< "\n";
    }
    cout << max-min<< "\n";
}