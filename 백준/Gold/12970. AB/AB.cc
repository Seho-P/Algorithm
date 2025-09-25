#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    string result;
    cin >> n >> k;
    if(n%2==0 && k>(n/2)*(n/2)){
        cout << -1;
    }
    else if(n%2!=0 && k>(n/2)*(n/2+1)){
        cout << -1;
    }
    else{
        for(int i=0;i<n;i++){
            if(i<n/2){
                result+="A";
            }
            else{
                result+="B";
            }
        }
    }
    int cnt = (n/2)*(n-n/2);
    for(int i=n/2;i<n;i++){
        int temidx = i;
        while(temidx>i-n/2){
            if(cnt>k){
                cnt--;
                temidx--;
            }
            else{
                break;
            }
        }
        swap(result[temidx],result[i]);
        if(cnt==k){
            break;
        }
    }
    cout << result;
}