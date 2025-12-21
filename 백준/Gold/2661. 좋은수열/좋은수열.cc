#include <iostream>
#include <string>
using namespace std;

int N;
bool check = false;

void syy(string now,int cnt){
    if(check)return;
    for(int i=1;i<int(now.size())/2+1;i++){
        if(now.substr(now.size()-i,i)==now.substr(now.size()-i-i,i))return;
    }
    if(cnt==N){
        cout << now;
        check=true;
        return;
    }
    for(int i=0;i<N;i++){
        syy(now+"1",cnt+1);
        syy(now+"2",cnt+1);
        syy(now+"3",cnt+1);    
    }
    
}


int main(){
    cin >> N;
    syy("",0);

}

