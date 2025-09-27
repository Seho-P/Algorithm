#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int all[21][21];
int minrs = 50000;
vector<int> linkteam;
vector<int> startteam;

void solve(){
    int a=0,b=0;
    for(int i=0;i<int(linkteam.size())-1;i++){
        for(int j=i+1;j<int(linkteam.size());j++){
            a += all[linkteam[i]][linkteam[j]] + all[linkteam[j]][linkteam[i]];
        }
    }
    for(int i=0;i<int(startteam.size())-1;i++){
        for(int j=i+1;j<int(startteam.size());j++){
            b += all[startteam[i]][startteam[j]] + all[startteam[j]][startteam[i]];
        }
    }
    minrs = min(minrs,abs(a-b));
    linkteam.clear();
    startteam.clear();
}

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> all[i][j];
        }
    }

    for(int mask = 0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                linkteam.push_back(i);
            }
            else{
                startteam.push_back(i);
            }
        }
        if(!linkteam.empty() && !startteam.empty()){
            solve();
        }
    }
    cout << minrs;

}