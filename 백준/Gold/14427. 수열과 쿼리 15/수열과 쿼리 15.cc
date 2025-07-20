#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

vector<int> v;
int arr[100001];
int segtree[400000];

int seg(int node, int start, int end){
    if( start == end){
        return segtree[node] = start;
    }
    int mid = (start+end) /2;

    int left = seg(node*2,start, mid);
    int right = seg(node*2+1, mid+1, end);

    if(arr[left]<=arr[right]){
        return segtree[node] = left;
    }
    else{
        return segtree[node] = right;
    }
}

int changeseg(int node,int start,int end, int index){
    if (index < start || index > end) return segtree[node];
    if (start == end) return segtree[node] = start;
    int mid = (start+end)/2;
    int left = changeseg(node*2,start,mid,index);
    int right = changeseg(node*2+1,mid+1,end,index);

    if(arr[left]<=arr[right]){
        return segtree[node] = left;
    }
    else{
        return segtree[node] = right;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int a,b;
    cin >> n;
    int tem;
    for(int i=1;i<=n;i++){
        cin >> tem;
        arr[i]= tem;    
    }
    seg(1,1,n);
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> tem;
        if(tem==1){
            cin >> a >> b;
            arr[a]=b;
            changeseg(1,1,n,a);
        }
        else if(tem==2){
            cout << segtree[1] <<"\n";
        }
    }
}