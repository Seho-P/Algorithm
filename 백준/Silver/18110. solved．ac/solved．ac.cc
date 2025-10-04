#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    double n;
    cin >> n;
    if(n==0){
        cout << 0;
    }
    else{
        vector<int> solvdac(n);
        for(int i=0;i<n;i++){
            cin >> solvdac[i];
        }
        sort(solvdac.begin(),solvdac.end());
        double excep = round(n*0.15);
        double sum = 0;
        for(int i=excep;i<n-excep;i++){
            sum+=solvdac[i];
        }
        cout << round(sum/(n-excep*2));
    }
    
}