#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct abc{
    int start;
    int end;
    int time;
};
vector<abc> abcd;

bool compare2(const abc a,const abc b){
    if(a.end==b.end){
        return a.start<b.start;
    }
    return a.end<b.end;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int sum=1;
    int start,end;
    cin >> n;
    int a,b;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        abcd.push_back({a,b,b-a});
    }
    sort(abcd.begin(),abcd.end(),compare2);
    start = abcd[0].start;
    end = abcd[0].end;
    for(int i=1;i<n;i++){
        if(end<=abcd[i].start){
            end = abcd[i].end;
            sum++;
        }
    }
    cout << sum << endl;
}