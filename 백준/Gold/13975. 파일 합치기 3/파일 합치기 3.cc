#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
    int t,k,tem;
    long long result;
    priority_queue<long long,vector<long long>,greater<long long>> chap;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> k;
        result=0;
        for(int p=0;p<k;p++){
            cin >> tem;
            chap.push(tem);
        }
        while(chap.size()>1){
            long long a = chap.top();
            chap.pop();
            long long b = chap.top();
            chap.pop();
            result += a+b;
            chap.push(a+b);
        }
        cout << result << "\n";
        chap.pop();
    }
}