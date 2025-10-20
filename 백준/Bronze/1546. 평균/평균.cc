#include <iostream>
using namespace std;

double gimal[1001];

int main(){
    double max = -1;
    double n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> gimal[i];
        if(gimal[i]>max){
            max = gimal[i];
        }
    }
    double sum = 0;
    for(int i=0;i<n;i++){
        gimal[i] = (gimal[i]/max)*double(100);
        sum += gimal[i];
    }
    cout << sum/n;
}