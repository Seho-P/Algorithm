#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int result =0;
    int l1=0,l2=0;
    int ss = s.size();
    while(l1<ss && l2<ss){
        if(s[l1]=='B'){
            l2=l1+1;
            while(l2<ss){
                if(s[l2]=='C'){
                    s[l1]='0';
                    s[l2]='0';
                    result++;
                    l1++;
                    l2++;
                    break;
                }
                l2++;
            }
        }
        else{
            l1++;
        }
    }
    l1=0,l2=0;
    while(l1<ss && l2<ss){
        if(s[l1]=='A'){
            l2=l1+1;
            while(l2<ss){
                if(s[l2]=='B'){
                    s[l1]='0';
                    s[l2]='0';
                    result++;
                    l1++;
                    l2++;
                    break;
                }
                l2++;
            }
        }
        else{
            l1++;
        }
    }
    
    // cout << s;
    cout << result;
}
