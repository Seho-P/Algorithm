#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    string p;
    string strtem;
    string tem;
    bool flag;
    bool emptyc;
    
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> p;
        cin >> n;
        cin >> strtem;
        deque<int> num;
        flag=true;
        emptyc=false;
        for(int r=1;r<int(strtem.size());r++){
            if(strtem[r]==',' || strtem[r]==']'){
                if(tem!=""){
                    num.push_back(stoi(tem));
                    tem="";
                }
            }
            else{
                tem+=strtem[r];
            }
        }
        for(char k:p){
            if(k=='R'){
                flag=!flag;
            }
            else{
                if(num.empty()){
                    emptyc=true;
                    break;
                }
                if(flag)num.pop_front();
                else num.pop_back();
            }
        }
        if(emptyc){
            cout << "error" <<"\n";
        }
        else{
            cout << '[';
            if(!flag)reverse(num.begin(),num.end());
            for(int r=0;r<int(num.size());r++){
                cout << num[r];
                if(r==int(num.size())-1){
                    break;
                }
                cout << ',';
            }
            cout << ']' << "\n";
        }
        
    }
}