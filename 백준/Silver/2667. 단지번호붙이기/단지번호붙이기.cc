#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int box[26][26];
int sum;
int result;
vector<int> apart;
int xpos[4] = {0,0,-1,1};
int ypos[4] = {1,-1,0,0};

void dfs(int n,int a,int b){
    box[a][b] = 0;
    for(int i=0;i<4;i++){
        int xx = a + xpos[i];
        int yy = b + ypos[i];
        if(xx<0 || yy<0 || xx>=n || yy>=n)continue;
        if(box[xx][yy]==1){
            dfs(n,xx,yy);
            sum++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string ap;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ap;
        for(int p=0;p<n;p++){
            box[p][i] = int(ap[p])-48;
        }
    }
    for(int i=0;i<n;i++){
        for(int p=0;p<n;p++){
            if(box[p][i] == 1){
                dfs(n,p,i);
                result++;
                sum ++;
                apart.push_back(sum);
                sum = 0;
            }
        }
    }
    sort(apart.begin(),apart.end());
    cout << result << "\n";
    for(int k:apart){
        cout << k << "\n";
    }
}