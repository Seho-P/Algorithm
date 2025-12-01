#include <iostream>
using namespace std;

int acost[10001];
int coin[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> coin[i];

    const int INF = 1e9;

    for(int i = 1; i <= k; i++)
        acost[i] = INF;

    acost[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = coin[i]; j <= k; j++){
            if(acost[j - coin[i]] != INF)
                acost[j] = min(acost[j], acost[j - coin[i]] + 1);
        }
    }

    cout << (acost[k] == INF ? -1 : acost[k]);
}