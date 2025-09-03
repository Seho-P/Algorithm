#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int all[51];

int main(){
    int n;
    int a=-100000;
    int b;
    vector<int> ra,rb;
    int cnt=0;
    bool re;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> all[i];
    }
    while(cnt<2 && a<100001){
        re = true;
        b = all[1] - all[0]*a;
        for(int i=1;i<n;i++){
            if(all[i]!=all[i-1]*a+b){
                re = false;
                break;
            }
        }
        if(re){
            cnt++;
            ra.push_back(a);
            rb.push_back(b);
        }
        a++;
    }
    if(n==1){
        cout << "A";
    }
    else if(cnt == 0){
        cout << "B";
    }
    else if( cnt >= 2){
        int result = all[n-1]*ra[0] + rb[0];
        re = true;
        for(int i=1;i<int(ra.size());i++){
            if(result!=(all[n-1]*ra[i]+rb[i])){
                re = false;
                break;
            }
        }
        if(re){
            cout << result;
        }
        else{
            cout << "A";
        }
        
    }
    else{
        cout << all[n-1]*ra[0] + rb[0];
    }
}