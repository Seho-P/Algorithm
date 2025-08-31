#include <iostream>
using namespace std;

int main(){
    long long s;
    long long n = 0;
    cin >> s;
    while(s>0){
        n++;
        s -=n;
    }
    if(s<0){
        n--;
    }
    cout << n;
}