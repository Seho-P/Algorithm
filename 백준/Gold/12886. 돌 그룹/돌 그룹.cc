#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int,int>> stone;
bool visited[1501][1501];

void stone_group(int a,int b){
    int aa = a + a;
    int bb = b - a;
    if(aa>bb){
        int tem = aa;
        aa = bb;
        bb = tem;
    }
    if(!visited[aa][bb]){
        stone.push({aa,bb});
        visited[aa][bb] = true;
    }
}

int main(){
    int a,b,c;
    int abc[3];
    pair<int,int> tem;
    int sum=0;
    int result = 0;
    cin >> a >> b >> c;
    stone.push({a,b});
    visited[a][b] = true;
    sum = a+b+c;
    if(sum%3!=0){
        cout << "0" << "\n";
        return 0;
    }
    while(!stone.empty()){
        tem = stone.front();
        stone.pop();
        abc[0] = tem.first;
        abc[1] = tem.second;
        abc[2] = sum - abc[0] - abc[1];
        sort(abc,abc+3);
        stone_group(abc[0],abc[1]);
        stone_group(abc[1],abc[2]);
        stone_group(abc[0],abc[2]);
    }
    if(visited[sum/3][sum/3]){
        result=1;
    }
    cout << result << "\n";

}
