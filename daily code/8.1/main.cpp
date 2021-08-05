#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//需要一个稳定排序 升序
void bubble(int *pls,int *count_n,int n){
    int tmp = 0;
    for(int i = 1;i<n;i++){
        for(int j = 0;j<n-i;j++){
            if(count_n[j]>count_n[j+1]){
                tmp = count_n[j+1];
                count_n[j+1] = count_n[j];
                count_n[j] = tmp;

                tmp = pls[j+1];
                pls[j+1] = pls[j];
                pls[j] = tmp;
            }
        }
    }
}

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

    int n = mat.size();
    int pls[n],count_n[n];
    for(int i = 0;i<n;i++){
        pls[i] = i;
        count_n[i] = count(mat[i].begin(),mat[i].end(),1);
    }

    bubble(pls,count_n,n);
    vector<int> ans(pls,pls+k);
    return ans;
}


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> power;
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n - 1, pos = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (mat[i][mid] == 0) {
                    r = mid - 1;
                }
                else {
                    pos = mid;
                    l = mid + 1;
                }
            }
            power.emplace_back(pos + 1, i);
        }

        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q(power.begin(),power.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
