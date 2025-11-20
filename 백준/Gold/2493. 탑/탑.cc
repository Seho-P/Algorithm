#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> l(n);
    for(int i=0; i<n; i++) cin >> h[i];

    stack<int> s; // 인덱스 저장
    for(int i=0; i<n; i++) {
        while(!s.empty() && h[s.top()] < h[i]) s.pop();
        if(s.empty()) l[i] = 0;
        else l[i] = s.top() + 1; // 1-based index
        s.push(i);
    }

    for(int i=0; i<n; i++) cout << l[i] << " ";
}