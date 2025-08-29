#include <iostream>
using namespace std;

int dice[6];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    long long min = 51;
    long long twomin = 101;
    long long threemin = 151;
    int max = -1;
    long long result = 0;
    cin >> n;
    for(int i=0;i<6;i++){
        cin >> dice[i];
        if(dice[i]<=min){
            min = dice[i];
        }
        if(dice[i]>max){
            max = dice[i];
        }
    }
    for(int i=0;i<6;i++){
        for(int p=0;p<6;p++){
            for(int q=0;q<6;q++){
                if(dice[i]<=min){
                min = dice[i];
                if(min+dice[p]<=twomin && p!=5-i && p!=i){
                    twomin = min+dice[p];
                    if(twomin + dice[q]<=threemin && q!=i && q!=5-i && q!=p && q!=5-p){
                        threemin = twomin + dice[q];
                    }
                }
            }
            }
        }
    }
    if(n==1){
        for(int i=0;i<6;i++){
            result+=dice[i];
        }
        result-=max;
    }
    else{
        result+=threemin*4; // 윗면 꼭짓점
        result+=twomin*(n-1)*4; // 꼭짓점부터 바닥까지 4개 기둥
        result+=twomin*(n-2)*4; // 윗면 꼭짓점 잇는 선
        result+=min*((n-2)*(n-2)); // 윗면 중앙 1칸 부분  -4n+4 n-2
        result+=min*(n*n-3*n+2)*4; // 옆면 4개 
    }
    cout << result;


}