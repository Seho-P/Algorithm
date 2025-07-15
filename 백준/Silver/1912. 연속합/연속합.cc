#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int tem;
    int 
    long sum = 0;
    long result = -1001;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tem;
        sum+=tem;
        
        if(result<sum){
            result = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    cout << result << "\n";
}