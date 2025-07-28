#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

vector<int> card;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,tem;
    int a,b;
    int sum=0;
    priority_queue<int,vector<int>,greater<int>> card;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tem;
        card.push(tem);
    }
    for(int i=0;i<n-1;i++){
        a = card.top();
        card.pop();
        b = card.top();
        card.pop();
        sum= sum +a+b;
        card.push(a+b);
    }
    cout << sum;
}