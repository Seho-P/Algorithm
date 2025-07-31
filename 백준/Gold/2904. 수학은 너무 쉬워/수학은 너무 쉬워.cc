#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> pn;
vector<int> sum;
vector<int> num;
int trymin;
int summax = 1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int tem;
    int max=-1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tem;
        num.push_back(tem);
        if(max<tem){
            max = tem;
        }
    }
    int prime[max+1];
    for(int i=0;i<=max;i++){
        prime[i] = 1;
    }
    for(int i=2;i<=max;i++){
        if(prime[i]!=0){
            pn.push_back(i);
            sum.push_back(0);
            for(int p=i*2;p<=max;p+=i){
                prime[p]=0;
            }
        }
    }
    int all[n][sum.size()];
    for(int i=0;i<n;i++){
        for(int p=0;p<sum.size();p++){
            all[i][p] = 0;
        }
    }
    for(int i=0;i<n;i++){
        tem = num[i];
        int pl = 0;
        while(tem!=1){
            if(tem%pn[pl]==0){
                sum[pl]++;
                all[i][pl]++;
                tem/=pn[pl];
            }
            else{
                pl++;
            }
        }
    }
    for(int i=0;i<int(sum.size());i++){
        tem=0;
        tem = sum[i]/n;
        summax *= pow(pn[i],tem);
        if(tem!=0){
            for(int p=0;p<n;p++){
                if(all[p][i]<tem){
                    trymin += (tem-all[p][i]);
                }
            }
        }
    }
    cout << summax << " " << trymin << "\n";
}