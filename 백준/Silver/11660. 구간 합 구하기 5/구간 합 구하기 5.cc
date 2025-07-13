#include <iostream>
#include <algorithm>
using namespace std;


int box[1025][1025];
int dp[1025][1025];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int x1,y1,x2,y2;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int p=1;p<=n;p++){
            cin >> box[i][p];
            dp[i][p] = box[i][p] + dp[i][p-1] + dp[i-1][p] - dp[i-1][p-1];
        }
    }
    for(int i=0;i<m;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << "\n";
    }
}
