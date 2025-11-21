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
            while(l2<ss){
                if(s[l2]=='C' && l1<l2){
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
            while(l2<ss){
                if(s[l2]=='B' && l1<l2){
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
    cout << result;
}
