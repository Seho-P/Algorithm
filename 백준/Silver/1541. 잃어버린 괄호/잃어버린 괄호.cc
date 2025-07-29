#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    bool minus = false;
    string s;
    string tem = "";
    cin >> s;
    s+='+';
    for(char k:s){
        if(k!='+' && k!='-'){
            tem += k;
        }
        else{
            if(minus){
                sum-=stoi(tem);
                tem.clear();
            }
            else{
                sum+=stoi(tem);
                tem.clear();
                if(k=='-'){
                    minus=true;
                }
            }
        }
    }
    cout << sum;
}