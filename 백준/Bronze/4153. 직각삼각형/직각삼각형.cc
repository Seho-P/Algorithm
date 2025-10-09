#include <iostream>
using namespace std;

void result1(int a,int b,int c){
    if((a*a)==(b*b)+(c*c)){
        cout << "right" <<  "\n";
    }
    else{
        cout << "wrong" << "\n";
    }
}

int main(){
    int a,b,c;
    while(1){
        cin >> a >> b >> c;
        if(a==b && b==0  && c==0){
            break;
        }
        if(a>b && a>c){
            result1(a,b,c);;
        }
        else if(b>a && b>c){
            result1(b,a,c);
        }else if(c>a && c>b){
            result1(c,a,b);
        }

    }
}