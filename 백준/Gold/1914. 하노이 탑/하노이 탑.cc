#include <iostream>
#include <algorithm>
using namespace std;


void hanoi(int start,int end,int mid,int n){
    if(n>0){
        hanoi(start,mid,end,n-1);
        cout << start << " " << end << "\n";
        hanoi(mid,end,start,n-1);
    }
}

string addstring(const string &a, const string &b){
    string res;
    int carry = 0;
    int i = (int)a.size() - 1 , j = (int)b.size()-1;
    while(i>=0 || j>=0 || carry){
        int sum = carry;
        if(i>=0) sum += a[i--] - '0';
        if(j>=0) sum += b[j--] - '0';
        res.push_back(sum%10+'0');
        carry = sum / 10;
    }
    reverse(res.begin(),res.end());
    return res;
}

string pow22(int n){
    string res = "1";
    for(int i=0;i<n;i++){
        res = addstring(res,res);
    }
    return res;
}

string subOnestring(string s){
    int i = s.size()-1;
    while(i>=0){
        if(s[i]>'0'){
            s[i]--;
            break;
        }
        else{
            s[i] = '9';
            i--;
        }
    }
    if(s[0]=='0' && s.size()!=1)s.erase(s.begin());
    return s;
}

int main(){
    int n;
    cin >> n;
    string cnt = pow22(n);
    cnt = subOnestring(cnt);
    cout << cnt << "\n";
    if(n<=20){
        hanoi(1,3,2,n);
    }
}