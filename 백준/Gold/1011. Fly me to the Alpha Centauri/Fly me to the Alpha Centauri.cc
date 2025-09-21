#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n,x,y,result;
    long cnt;
    cin >> n;
    while(n--){
        cin >> x >> y;
        result =0;
        cnt = 1;
        while(1){
            if(cnt*cnt<y-x){
                cnt++;
            }
            else if(cnt*cnt>y-x){
                cnt--;
                break;
            }
            else{
                break;
            }
        }
        result= cnt*2-1;
        y-=cnt*cnt;
        result+=(y-x)/cnt;
        if((y-x)%cnt!=0){
            result++;
        }
        cout << result << "\n";
    }
}