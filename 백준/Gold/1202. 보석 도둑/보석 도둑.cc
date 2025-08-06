#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct compare{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        if(a.second!=b.second){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,compare> gem;
vector<int> bag;
multiset<int> bags;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long sum = 0;
    int n,k;
    int m,v,c;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> m >> v;
        gem.push({m,v});
    }
    for(int i=0;i<k;i++){
        cin >> c;
        bag.push_back(c);
    }
   sort(bag.begin(),bag.end());
   for(int i=0;i<k;i++){
    bags.insert(bag[i]);
   }
   while(!gem.empty() && !bags.empty()){
        m = gem.top().first;
        v = gem.top().second;
        gem.pop();
        auto idx = bags.lower_bound(m);
        if(idx!=bags.end()){
            sum+=v;
            bags.erase(idx);
        }
   }
   cout << sum;
    
}