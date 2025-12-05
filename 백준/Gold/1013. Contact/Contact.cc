#include <iostream>
#include <string>
using namespace std;

bool CheckContract(string s,int cnt,int leng){
    bool real = false;
    while(1){
        if(s[cnt]=='0'){
            if(s[cnt+1]=='1'){
                cnt+=2;
            }
            else{
                return false;
            }
        }
        else{
            break;
        }
    }
    if(cnt==leng)return true;
    if(s[cnt+1]=='0' && s[cnt+2]=='0'){
        cnt+=3;
    }
    else{
        return false;
    }
    while(s[cnt]=='0')cnt++;
    if(s[cnt]!='1')return false;
    while(s[cnt]=='1')cnt++;
    if(cnt==leng)return true;
    else{
        if(!real){
            real = CheckContract(s,cnt,leng);
        }
        if(!real && s[cnt-2]=='1'){
            real = CheckContract(s,cnt-1,leng);
        }
    }
    return real;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> s;
        if(CheckContract(s,0,s.size())){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}