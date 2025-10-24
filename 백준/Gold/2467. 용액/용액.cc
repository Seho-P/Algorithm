#include <iostream>
#include <math.h>
using namespace std;

long liquid[100001];

int main(){
    long n,tem;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> liquid[i];   
    }
    long resl,resr;
    long mindif = 2000000001;
    long left = 0;
    long right = n-1;
    while(left<right){
        tem = liquid[left] + liquid[right];
        if(abs(mindif)>abs(tem)){
            mindif = tem;
            resl = liquid[left];
            resr = liquid[right];
        }
        if(tem>0){
            right--;
        }
        else if(tem<0){
            left++;
        }
        else{
            resl = liquid[left];
            resr = liquid[right];
            break;
        }
    }
    cout << resl << " " << resr;
}

//좌 - > 우 로 숫자를 바꾸면 +
// 우 - > 좌 로 숫자를 바꾸면 -
// 즉 양수면 우를 좌로, 음수면 좌를 우로 !