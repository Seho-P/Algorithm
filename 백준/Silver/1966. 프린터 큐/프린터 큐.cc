#include <iostream>
#include <queue>
using namespace std;

int prank[10];

int main(){
    int t,n,m,tem;
    int cnt = 0;
    queue<int> pq;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=1;i<=9;i++){
            prank[i]=0;
        }
        for(int i=0;i<n;i++){
            cin >> tem;
            prank[tem]++;
            pq.push(tem);
        }
        while(!pq.empty()){
            bool isreal = true;
            int a = pq.front();
            pq.pop();
            for(int i=a+1;i<=9;i++){
                if(prank[i]>0){
                    isreal=false;
                    break;
                }
            }
            if(isreal){
                prank[a]--;
                cnt++;
                if(m==0){
                    break;
                }
                m--;
            }
            else{
                pq.push(a);
                if(m==0){
                    m = pq.size()-1;
                }
                else{
                    m--;
                }
            }
        }
        cout << cnt << "\n";
        cnt = 0;
        while(!pq.empty())pq.pop();
    }
}