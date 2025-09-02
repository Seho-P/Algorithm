#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int res1 = 1;
    int res2 = 0;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    vector<int> start1(n), end(n);
    for(int i=0;i<n;i++){
        start1[i] = s1[i] -'0';
        end[i] = s2[i] - '0';
    }
    vector<int> start2 = start1;
    start1[0] = 1^start1[0];
    start1[1] = 1^start1[1];
    for(int i=1;i<n;i++){
        if(start1[i-1]!=end[i-1]){
            start1[i-1] = 1^start1[i-1];
            start1[i]   = 1^start1[i];
            start1[i+1] = 1^start1[i+1];
            res1++;
        }
        if(start2[i-1]!=end[i-1]){
            start2[i-1] = 1^start2[i-1];
            start2[i]   = 1^start2[i];
            start2[i+1] = 1^start2[i+1];
            res2++;
        }
    }
    if(start1[n-1] != end[n-1] && start2[n-1] == end[n-1]){
        cout << res2;
    }
    else if(start1[n-1] == end[n-1] && start2[n-1] != end[n-1]){
        cout << res1;
    }
    else if(start1[n-1] == end[n-1] && start2[n-1] == end[n-1]){
        cout << min (res1,res2);
    }
    else{
        cout << -1;
    }

}