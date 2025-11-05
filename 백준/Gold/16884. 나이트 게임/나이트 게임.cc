#include <iostream>
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        if(n%2==0){
            cout<<"cubelover" << "\n" ;
        }
        else{
            cout<<"koosaga" << "\n";
        }
    }
}