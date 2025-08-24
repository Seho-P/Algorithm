#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> all;

int solve2(){
    double sum = 0;
    int n = all.size();
    for(int x : all) sum += x;
    double avg = sum / n;

    int floorAvg = int(avg);
    int ceilAvg = floorAvg + 1;

    int sumFloor = 0, sumCeil = 0;
    for(int x : all) {
        sumFloor += (x - floorAvg) * (x - floorAvg);
        sumCeil += (x - ceilAvg) * (x - ceilAvg);
    }

    if(sumFloor <= sumCeil) return floorAvg;
    else return ceilAvg;
}

int main(){
    int result2;
    int n,t;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        all.push_back(t);
    }
    sort(all.begin(),all.end());
    result2= solve2();
    
    cout << all[(n-1)/2] << " " << result2 << endl; 
}