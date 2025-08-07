#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

priority_queue<int> pn;
priority_queue<int,vector<int>,greater<>> nn;
queue<int> oo;
bool zet = false;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,tem;
    int sum=0;
    int result = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tem; 
        if(tem >1){
            pn.push(tem);
        }
        else if(tem<0){
            nn.push(tem);
        }
        else if(tem==1){
            oo.push(1);
        }
        else{
            zet = true;
        }
    }
    while(!pn.empty()){
        tem = pn.top();
        pn.pop();
        if(sum==0){
            sum = tem;
        }
        else{
            sum*=tem;
            result+= sum;
            sum=0;
        }
    }
    if(sum!=0){
        result+=sum;
        sum=0;
    }
    while(!nn.empty()){
        tem = nn.top();
        nn.pop();
        if(sum==0){
            sum = tem;
        }
        else{
            sum*=tem;
            result+= sum;
            sum=0;
        }
    }
    if(sum!=0){
        if(zet==false){
            result+=sum;
            sum=0;
        }
    }
    while(!oo.empty()){
        oo.pop();
        result++;
    }
    cout << result << "\n";
}