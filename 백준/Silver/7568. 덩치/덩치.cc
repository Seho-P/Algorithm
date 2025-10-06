#include <iostream>
using namespace std;

int hcm[51];
int wkg[51];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> hcm[i] >> wkg[i];
    }
    for(int i=0;i<n;i++){
        int result = 1;
        for(int j=0;j<n;j++){
            if(hcm[j]>hcm[i] && wkg[j]>wkg[i]){
                result++;
            }
        }
        cout << result<< " ";
    }
}