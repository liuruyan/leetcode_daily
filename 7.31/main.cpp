#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

map<int,map<int,vector<int>>> m;
void preorder(TreeNode* root,int raw,int col){
    if (!root) return;
    m[col][raw].push_back(root->val);
    preorder(root->left,raw+1,col-1);
    preorder(root->right,raw+1,col+1);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> tmp;
    preorder(root,0,0);
    for(auto &t:m){
        //ans.push_back(t.second);
        tmp.clear();
        for(auto &p:t.second){//p is a map
            sort(p.second.begin(),p.second.end());
            tmp.insert(tmp.end(),p.second.begin(),p.second.end());
        }
        ans.push_back(tmp);
    }
    return ans;
}
int main(){
    
   map<int,vector<vector<int>>> m1;

}

 