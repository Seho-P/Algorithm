#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    string a,b,tem;
    cin >> a >> b;
    while(a.size()!=b.size()){
        if(b[b.size()-1] == 'A'){
            tem = b.substr(0,b.size()-1);
            b = tem;
            
        }
        else if(b[b.size()-1] == 'B'){
            tem =  b.substr(0,b.size()-1);;
            reverse(tem.begin(),tem.end());
            b = tem;
        }
    }
    if(a==b){    
        cout << 1 << "\n";
    }
    else{
        cout << 0 << "\n";
    }
}