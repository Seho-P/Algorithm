#include <iostream>
#include <string>
#include <queue>
using namespace std;

char house[51][51];
pair<int,int> startdoor = {-1,-1};
pair<int,int> enddoor;

//상하좌우
//  0상 / 3우 \ 2좌
//  1하 / 2좌 \ 3우 
//  2좌 / 1하 \ 0상
//  3우 / 0상 \ 1하
int result;
int minresult = 9999;
int cntm;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int mirror[4][2] = {{3,2},{2,3},{1,0},{0,1}};
char mir[2] = {'0','1'};

struct mhd{
    int y;
    int x;
    int cur;
    int result;
    bool operator<(const mhd a)const{
        return this->result > a.result;
    }
};



int main(){
    int n;
    int cur;
    
    string tem;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tem;
        for(int j=0;j<n;j++){
            house[i][j]=tem[j];
            if(house[i][j]=='#'){
                if(startdoor.first==-1) startdoor = {i,j};
                else enddoor = {i,j};
            }
            else if(house[i][j]=='!') cntm++;
        }
    }
    
    priority_queue<mhd> mlist;
    for(int i=0;i<4;i++){
        mlist.push({startdoor.first,startdoor.second,i,0});
    }
    
    while(!mlist.empty()){
        mhd nowmhd = mlist.top();
        mlist.pop();
        while(1){
            nowmhd.y+=dy[nowmhd.cur];
            nowmhd.x+=dx[nowmhd.cur];
            if(house[nowmhd.y][nowmhd.x]!='.')break;
        }
        if(nowmhd.y == enddoor.first && nowmhd.x == enddoor.second){
            minresult = nowmhd.result;
            break;
        }
        // cout << nowmhd.y << " " << nowmhd.x << endl;
        if(house[nowmhd.y][nowmhd.x]=='!'){
            mlist.push({nowmhd.y,nowmhd.x,mirror[nowmhd.cur][0],nowmhd.result+1});
            mlist.push({nowmhd.y,nowmhd.x,mirror[nowmhd.cur][1],nowmhd.result+1});
            mlist.push({nowmhd.y,nowmhd.x,nowmhd.cur,nowmhd.result});
        }
    }
    cout << minresult;
}