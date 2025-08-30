#include <iostream>
#include <math.h>
using namespace std;


int water[32];

int main(){
    int n,k,tem;
    int sum = 0;
    cin >> n >> k;
    int cnt=0;
    int result = 0;
    water[0] = n;
    while(1){
        tem = water[cnt];
        if(tem<=1){
            break;
        }
        water[cnt+1] = tem/2;
        water[cnt] = tem%2;
        cnt++;
    }
    for(int i=cnt;i>=0;i--){
        sum += water[i];
    }
    cnt =0;
    while(cnt <31){
        if(sum<=k){
            break;
        }
        if(water[cnt]==1){
                result += pow(2,cnt);
                water[cnt]=0;
                water[cnt+1]++;
            }
        else if(water[cnt]==2){
            sum--;
            water[cnt]=0;
            water[cnt+1]++;
        }
        cnt++;
    }
    cout << result << endl;
}