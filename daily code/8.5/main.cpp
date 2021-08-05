#include <iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//判断是否有环，环内所有节点都不安全
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n);

    function<bool(int)> safe = [&](int x) {
        if(color[x]>0){
            return color[x] == 2;
        }
        color[x] = 1;
        for(int y :graph[x]){
            if(!safe(y))
            return false;
        }
        color[x] = 2;
        return true;
    };
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(safe(i)){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){}