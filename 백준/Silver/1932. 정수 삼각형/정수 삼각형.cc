#include <iostream>
#include <algorithm>
using namespace std;

int tri[501][501];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int result = 0;
    for(int i=1;i<=n;i++){
        for(int p=1;p<=i;p++){
            cin >> tri[i][p];
            tri[i][p] += max(tri[i-1][p-1],tri[i-1][p]);
            if(i==n){
                result = max(result,tri[i][p]);
            }
        }
    }
    cout << result << "\n";
}