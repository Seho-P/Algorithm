#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

vector<int> leftbook;
vector<int> rightbook;


int n,m,tem;
int result = 0;

void rightvec(int a){
    int k=rightbook.size()%m-1;
    if(rightbook.size()%m!=0){
        for(int i=k;i<=int(rightbook.size())-1;i+=m){
            result += rightbook[i]*2;
        }
        if(a==1){
            result -= rightbook[rightbook.size()-1];
        }
    }
    else{
        for(int i=m-1;i<int(rightbook.size());i+=m){
            result += rightbook[i]*2;
        }
        if(a==1){
        result -= rightbook[rightbook.size()-1];
    }
    }
    
}

void leftvec(int a){
    int k=leftbook.size()%m-1;
    if(leftbook.size()%m!=0){
        for(int i=k;i<=int(leftbook.size())-1;i+=m){
            result -= leftbook[i]*2;
        }
        if(a==1){
            result += leftbook[leftbook.size()-1];
        }
    }
    else{
        for(int i=m-1;i<int(leftbook.size());i+=m){
            result -= leftbook[i]*2;
        }
        if(a==1){
            result += leftbook[leftbook.size()-1];
        }
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tem;
        if(tem<0){
            leftbook.push_back(tem);
        }
        else{
            rightbook.push_back(tem);
        }
    }
    sort(leftbook.begin(),leftbook.end(),greater());
    sort(rightbook.begin(),rightbook.end());
    if(leftbook.empty()){
        leftbook.push_back(0);
    }
    if(rightbook.empty()){
        rightbook.push_back(0);
    }
    if(-leftbook[leftbook.size()-1]>rightbook[rightbook.size()-1]){
        rightvec(0);
        leftvec(1);   
    }
    else{
        leftvec(0);
        rightvec(1);
    }
    cout << result;
}