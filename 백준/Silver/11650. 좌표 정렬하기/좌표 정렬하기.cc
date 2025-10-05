#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int x,y;
    vector<pair<int,int>> xyxy;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        xyxy.push_back({x,y});
    }
    sort(xyxy.begin(),xyxy.end());
    for(int i=0;i<n;i++){
        cout << xyxy[i].first << " " << xyxy[i].second << "\n";
    }
}