#include <iostream>
#include <vector>

using namespace std;

int main(){
    int k,tem;
    long result = 0;
    cin >> k;
    vector<int> nacoder;
    for(int i=0;i<k;i++){
        cin >> tem;
        if(tem!=0){
            nacoder.push_back(tem);
        }
        else{
            nacoder.pop_back();
        }
    }
    for(int k:nacoder){
        result+=k;
    }
    cout << result;
}