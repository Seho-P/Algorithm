#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

int visited[10];
long long A,B,N;

void solve(long n,long ns,long a,long b){
    if(a>=N || A!=0)return;
    if(ns==0){
        long temb = N-a;
        if(temb<0)return;
        if(temb==0)return;
        long bt = int(log10(temb))+1;
        queue<long> tem;
        while(bt>0){
            if(visited[temb%10]==1){
                while(!tem.empty()){
                    visited[tem.front()]=0;
                    tem.pop();
                }
                return;
            }
            tem.push(temb%10);
            visited[temb%10]=1;
            temb/=10;
            bt--;
        }
        A=a;
        B=N-a;
        return;
    }
    long nowt = pow(10,ns-1);
    for(int i=9;i>=0;i--){
        if(visited[i]==0){
            if(n==N && i==0){
                solve(n-i*nowt,ns-1,a+i*nowt,b);
            }
            else{
                visited[i]=1;
                solve(n-i*nowt,ns-1,a+i*nowt,b);
                visited[i]=0;
            }
            
        }
    }
}

int main(){
    cin >> N;
    solve(N,int(log10(N))+1,0,0);
    if(A==0)cout << -1;
    else cout << A << " + " << B;
    
    
}

// 1 2 6 24 120 720 5040 40320 32만 300만 