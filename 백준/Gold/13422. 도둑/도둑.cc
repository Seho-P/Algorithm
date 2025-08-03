#include <iostream>
#include <vector>
using namespace std;

vector<int> housemoney;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,m,k,tem;
    int sum =0;
    int count = 0;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n >> m >> k;
        for(int p=0;p<=n-1;p++){
            cin >> tem;
            housemoney.push_back(tem);
            sum +=tem;
            if(p>=m-1){
                if(sum<k){
                    count++;
                }
                sum-=housemoney[p-m+1];
                if(p==n-1 && n!=m){
                    for(int q=0;q<m-1;q++){
                        sum+=housemoney[q];
                        if(sum<k){
                            count++;
                        }
                        sum-=housemoney[n-m+1+q];
                    }
                }
            }
        }
        cout << count << "\n";
        housemoney.clear();
        sum = 0;
        count = 0;
    }

}