#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> snowh;
//ㅠㅠ
int main(){
    int n,tem;
    int max = INT_MAX;
    
    int sum;
    cin >> n;
    int left;
    int right;
    for(int i=0;i<n;i++){
        cin >> tem;
        snowh.push_back(tem);
        
    }
    sort(snowh.begin(),snowh.end());
    for(int i=0;i<n-3;i++){
        for(int j=i+3;j<n;j++){
            left = i+1;
            right = j-1;
            while(left<right){
                sum = (snowh[i]+snowh[j]-(snowh[left]+snowh[right]));
                max = min(max,abs(sum));
                if(sum>0){
                    left++;
                }
                else{
                    right--;
                }
            }   
        }
    }
    cout << max;
}

