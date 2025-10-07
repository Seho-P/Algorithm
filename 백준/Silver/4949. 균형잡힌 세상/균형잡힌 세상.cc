#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<char> sekai;
    string s;
    while(1){
        s = "";
        bool balan = true;
        getline(cin,s);
        if(s==".")break;
        for(char k:s){
            if(k=='(' || k=='['){
                sekai.push_back(k);
            }
            else if(k==')'){
                if(sekai.back()=='('){
                    sekai.pop_back();
                }
                else {
                    balan=false;
                    break;
                }
            }
            else if(k==']'){
                if(sekai.back()=='['){
                    sekai.pop_back();
                }
                else{
                    balan=false;
                    break;
                }
            }
        }
    if(balan && sekai.empty()){
        cout << "yes" << "\n";
    }
    else{
        cout << "no" << "\n";
        sekai.clear();
    }
    }
}