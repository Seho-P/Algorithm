#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    string s;
    vector<int> idx(26,0);
    int maxcat = 1;
    int cnt = 0;
    cin >> n >> s;
    int l=0,r=0;
    while(r<(int(s.size()))){
        if(idx[s[r]-'a']==0)cnt++;
        idx[s[r]-'a']++;
        r++;
        while(cnt>n){
            idx[s[l]-'a']--;
            if(idx[s[l]-'a']==0)cnt--;
            l++;
        }
        maxcat = max(maxcat,r-l);
    }
    cout << maxcat;
}