#include <iostream>
#include <vector>
using namespace std;

int su[9];
int N,M;
vector<int> abcd;

void dfs(int idx,int n,int m){
    if(m==0){
        for(int i=0;i<M;i++){
            cout << abcd[i] << " ";   
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=n-m+1;i++){
        abcd.push_back(i+idx);
        dfs(idx+i,n-i,m-1);
        abcd.pop_back();
    }
}

int main(){
    cin >> N >> M;
    dfs(0,N,M);
}