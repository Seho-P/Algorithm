#include <iostream>
#include <vector>
using namespace std;

int arr[301][301];
int nextarr[301][301];
int n,m,r;



int main(){
    cin >> n >> m >>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int layers = min(n,m) /2;
    for(int layer = 0;layer<layers;layer++){
        vector<int> temp;
        int top= layer, left = layer;
        int bottom = n-layer-1,right=m-layer-1;

        for(int j = left;j<right;j++)temp.push_back(arr[top][j]);
        for(int i = top;i<bottom;i++)temp.push_back(arr[i][right]);
        for(int j = right;j>left;j--)temp.push_back(arr[bottom][j]);
        for(int i = bottom;i>top;i--)temp.push_back(arr[i][left]);

        int temr = r%(temp.size());
        vector<int> rotvec(temp.size());
        for(int i=0;i<int(temp.size());i++){
            rotvec[i] = temp[(i+temr)%temp.size()];
        }
        int idx=0;
        for(int j = left;j<right;j++)arr[top][j]=rotvec[idx++];
        for(int i = top;i<bottom;i++)arr[i][right]=rotvec[idx++];
        for(int j = right;j>left;j--)arr[bottom][j]=rotvec[idx++];
        for(int i = bottom;i>top;i--)arr[i][left]=rotvec[idx++];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout <<  arr[i][j] << " ";
        }
        cout << "\n";
    }
    
}