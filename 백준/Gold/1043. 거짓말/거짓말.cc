#include <iostream>
#include <vector>
using namespace std;

vector<int> realperson[51];
int parent[51];
vector<int> knowp;

int findp(int x){
    if(x==parent[x])return x;
    return parent[x] = findp(parent[x]);
}

void mer(int x,int y){
    int px = findp(x);
    int py = findp(y);
    if(px==py) return;
    parent[py] = px;
}

int main(){
    int n,m,r,tem;
    cin >> n >> m;
    
    int result = m;
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    cin >> r;
    if(r==0){
        cout << m;
    }
    else{
        for(int i=0;i<r;i++){
        cin >> tem;
        knowp.push_back(tem);
        }
        for(int i=0;i<m;i++){
            cin >> r;
            int prev;
            cin >> prev;
            realperson[i].push_back(prev);
            for(int j=1;j<r;j++){
                cin >> tem;
                mer(prev,tem);
                realperson[i].push_back(tem);
            }
        }
        for(int k:knowp){
            mer(knowp[0],k);
        }
        for(int i=0;i<m;i++){
            for(int j:realperson[i]){
                if(findp(j)==findp(knowp[0])){
                    result--;
                    break;
                }
            }
        }
        cout << result;
    }
    
}