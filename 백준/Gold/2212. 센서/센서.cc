#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sensor;
vector<int> dif;


int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    int n,k,tem;
    int sum =0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> tem;
        sensor.push_back(tem);
    }
    sort(sensor.begin(),sensor.end());
    for(int i=1;i<n;i++){
        dif.push_back(sensor[i]-sensor[i-1]);
    }
    sort(dif.begin(),dif.end());
    for(int i=0;i<n-k;i++){
        sum+=dif[i];
    }
    cout << sum;
}