#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int alpha[26]; 

bool compare(int a,int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int ten=9;
    int sum=0;
    string tem;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tem;
        for(int p=0;p<int(tem.size());p++){
            alpha[tem[tem.size()-p-1]-'A'] += pow(10,p);
        }
    }
    sort(alpha,alpha+26,compare);
    for(int k:alpha){
        if(ten==-1){
            break;
        }
        sum+= k*ten;
        ten--;
    }
    cout << sum << "\n";
}

