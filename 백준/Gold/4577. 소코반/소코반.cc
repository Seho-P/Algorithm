#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> result;
char smap[16][16];
int r,c;
pair<int,int> w;
int count;

void check(int a,int b){
    pair<int,int> next = {a,b};
    if(smap[w.first + next.first][w.second + next.second]=='.'){
        smap[w.first + next.first][w.second + next.second] = 'w';
        if(smap[w.first][w.second] == 'W'){
            smap[w.first][w.second] = '+';
        }
        else{
            smap[w.first][w.second] = '.';
        }
        w = {w.first + next.first,w.second + next.second};
    }
    else if(smap[w.first + next.first][w.second + next.second]=='+'){
        smap[w.first + next.first][w.second + next.second] = 'W';
        if(smap[w.first][w.second] == 'W'){
            smap[w.first][w.second] = '+';
        }
        else{
            smap[w.first][w.second] = '.';
        }
        w = {w.first + next.first,w.second + next.second };
    }
    else if(smap[w.first + next.first][w.second + next.second]=='b'){
        if(smap[w.first + next.first*2][w.second + next.second*2]=='.'){
            smap[w.first + next.first*2][w.second + next.second*2]= 'b';
            smap[w.first + next.first][w.second + next.second] = 'w';
            if(smap[w.first][w.second] == 'W'){
                smap[w.first][w.second] = '+';
            }
            else{
                smap[w.first][w.second] = '.';
            }
            w = {w.first + next.first,w.second + next.second };
        }
        else if(smap[w.first + next.first*2][w.second + next.second*2]=='+'){
            smap[w.first + next.first*2][w.second + next.second*2]='B';
            smap[w.first + next.first][w.second + next.second] = 'w';
            if(smap[w.first][w.second] == 'W'){
                smap[w.first][w.second] = '+';
            }
            else{
                smap[w.first][w.second] = '.';
            }
            w = {w.first + next.first,w.second + next.second };
        }
    }
    else if(smap[w.first + next.first][w.second + next.second]=='B'){
        if(smap[w.first + next.first*2][w.second + next.second*2]=='.'){
            smap[w.first + next.first*2][w.second + next.second*2]= 'b';
            smap[w.first + next.first][w.second + next.second] = 'W';
            
            if(smap[w.first][w.second] == 'W'){
                smap[w.first][w.second] = '+';
            }
            else{
                smap[w.first][w.second] = '.';
            }
            w = {w.first + next.first,w.second + next.second };
        }
        else if(smap[w.first + next.first*2][w.second + next.second*2]=='+'){
            smap[w.first + next.first*2][w.second + next.second*2]='B';
            smap[w.first + next.first][w.second + next.second] = 'W';
            
            if(smap[w.first][w.second] == 'W'){
                smap[w.first][w.second] = '+';
            }
            else{
                smap[w.first][w.second] = '.';
            }
            w = {w.first + next.first,w.second + next.second };
        }
    }
}

bool check(){
    for(auto k:result){
        if(smap[k.first][k.second]!='B'){
            return false;
        }
    }
    return true;
}

void checkresult(){
    count ++;
    cout << "Game "<< count << ": ";
    for(auto k:result){
        if(smap[k.first][k.second]!='B'){
            cout << "incomplete" << "\n";
            return;
        }
    }
    cout << "complete" << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    while(r!=0  && c!=0){
        string sroute = "";
        for(int i=0;i<r;i++){
            for(int p=0;p<c;p++){
                cin >> smap[i][p];
                if(smap[i][p]=='w'){
                    w = {i,p};
                }
                else if(smap[i][p]=='W'){
                    w = {i,p};
                    result.push_back({i,p});
                }
                else if(smap[i][p]=='+' || smap[i][p] =='B'){
                    result.push_back({i,p});
                }
            }
        }
        cin >> sroute;
        int numc=0;
        for(char now:sroute){
            numc++;
            if(numc>=51){
                break;
            }
            if(now == 'U'){
                check(-1,0);
            }
            else if(now == 'D'){
                check(1,0);
            }
            else if(now == 'L'){
                check(0,-1);
            }
            else if(now == 'R'){
                check(0,1);
            }
            if(check()){
                break;
            }
        }
        checkresult();
        for(int i=0;i<r;i++){
            for(int p=0;p<c;p++){
                cout << smap[i][p];
            }
            cout << "\n";
        }
        result.clear();
        cin >> r >> c;
    }
}