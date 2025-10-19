#include <iostream>
using namespace std;

int aln[101];

int main(){
    int n,m;
    int result = -1;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> aln[i];
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int l=j+1;l<n;l++){
                if(result<aln[i]+aln[j]+aln[l] && aln[i]+aln[j]+aln[l]<=m){
                    result = aln[i]+aln[j]+aln[l];
                }
            }
        }
    }
    cout << result;
}