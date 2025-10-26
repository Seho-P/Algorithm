#include <iostream>
#include <cmath>
using namespace std;

int nn[101][101];

int main(){
    int n,l;
    cin >> n >> l;
    int result=2*n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> nn[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int prev = -1;
        bool dif = false;
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(prev==-1){
                prev = nn[i][j];
                cnt++;
            }
            else{
                //2이상 차이날때
                if(abs(prev-nn[i][j])>=2){
                    dif=false;
                    result--;
                    break;
                }
                //지금까지 높이 차이가 없을때
                else if(!dif){
                    if(prev==nn[i][j]){
                        cnt++;
                    }
                    else if(prev<nn[i][j]){
                        prev=nn[i][j];
                        if(cnt>=l){
                            cnt=1;
                        }
                        else{
                            result--;
                            break;
                        }
                    }
                    else if(prev>nn[i][j]){
                        prev = nn[i][j];
                        dif=true;
                        cnt=1;
                        if(dif && cnt==l){
                            dif = false;
                            cnt = 0;
                        }
                    }
                }
                //높이 차이가 있던 경우
                else if(dif){
                    if(prev==nn[i][j]){
                        cnt++;
                        if(cnt==l){
                            dif=false;
                            cnt=0;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        if(dif){
            result--;
        }
    }
    for(int i=0;i<n;i++){
        int prev = -1;
        bool dif = false;
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(prev==-1){
                prev = nn[j][i];
                cnt++;
            }
            else{
                //2이상 차이날때
                if(abs(prev-nn[j][i])>=2){
                    dif=false;
                    result--;
                    break;
                }
                //지금까지 높이 차이가 없을때
                else if(!dif){
                    if(prev==nn[j][i]){
                        cnt++;
                    }
                    else if(prev<nn[j][i]){
                        prev=nn[j][i];
                        if(cnt>=l){
                            cnt=1;
                        }
                        else{
                            result--;
                            break;
                        }
                    }
                    else if(prev>nn[j][i]){
                        prev = nn[j][i];
                        dif=true;
                        cnt=1;
                        if(dif && cnt==l){
                            dif = false;
                            cnt = 0;
                        }
                    }
                }
                //높이 차이가 있던 경우
                else if(dif){
                    if(prev==nn[j][i]){
                        cnt++;
                        if(cnt==l){
                            dif=false;
                            cnt=0;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        if(dif){
            result--;
        }
    }
    cout <<result;
}