#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;

int ubin(int left,int right,int k){
    
    while (left<right)
    {
        int mid = (left+right)/2;
        if(num[mid]<=k){
            left = mid +1;
        }
        else{
            right=mid;
        }
    }
    
    return right;
}

int lbin(int left,int right,int k){
    
    while (left<right)
    {
        int mid = (left+right)/2;
        if(num[mid]<k){
            left = mid +1;
        }
        else{
            right=mid;
        }
    }
    
    return right;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n,n2;
    int k;
    int sum;
    int pm ;
    int result = 0;
    for(int i=0;i<t;i++){
        cin >> n >> n2;
        for(int p=0;p<n;p++){
            cin >> k;   
            num.push_back(k);
        }
        sort(num.begin(),num.end());
        int left=0;
        int right= n;
        pm = INT_MAX;
        while(left<right-1){
            sum = num[left] + num[right-1];
            if(sum<=n2){
                if(pm>abs(sum-n2)){
                    pm=abs(sum-n2);
                    result = 0;
                }
                if(pm==abs(sum-n2)){
                    result+= ubin(left,right,num[left]) - left;
                }
                left = ubin(left,right,num[left]);
            }
            else if(sum>n2){
                if(pm>abs(sum-n2)){
                    pm=abs(sum-n2);
                    result = 0;
                }
                if(pm==abs(sum-n2)){
                result+= right - lbin(left,right,num[right-1]) ;
                }
                right = lbin(left,right,num[right-1]);
            }
        }
        cout << result << "\n";
        result = 0;
        num.clear();
        
    }

}