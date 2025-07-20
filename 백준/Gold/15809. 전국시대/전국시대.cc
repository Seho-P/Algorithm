#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> s;
multiset<int> result;
int arr[100001];
int arrp[100001];


int findp(int a){
    if(arrp[a]==a) return a;
    return arrp[a] = findp(arrp[a]);
}

void unionp(int p,int q){
    p = findp(p);
    q = findp(q);
    arrp[q] = p;
    arr[p] += arr[q];
    arr[q] = 0;
}


int main(){
    int n,m;
    int a,b;
    int o,p,q;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        arrp[i] = i ;
    }
    for(int i=0;i<m;i++){
        cin >> o >> p >> q;
        if( o == 1){
            unionp(p,q);
        }
        else if ( o == 2){
            a = findp(p);
            b = findp(q);
            if(arr[a]==arr[b]){
                arrp[a] = 0;
                arrp[b] = 0;
                arr[a] = 0;
                arr[b] = 0;
            }
            else if(arr[a]<arr[b]){
                arrp[a] = b;
                arr[b] -= arr[a];
                arr[a] = 0 ;
            }
            else{
                arrp[b] = a;
                arr[a] -= arr[b];
                arr[b] = 0 ;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(findp(i)!=0){
            s.insert(findp(i));
        }
    }
    for(int k:s){
        result.insert(arr[k]);
    }
    cout << result.size() << "\n";
    for(int k:result){
        cout << k << " ";
    }
}