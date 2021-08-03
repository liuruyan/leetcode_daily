#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


// int findUnsortedSubarray(vector<int>& nums) {

//     vector<int> nums_cop = nums;
//     sort(nums_cop.begin(),nums_cop.end());
//     int index = 0,i;
//     while(!nums_cop.empty()&&nums_cop[0]==nums[0]){
//         nums_cop.erase(nums_cop.begin());
//         nums.erase(nums.begin());
//     }
//     while(!nums_cop.empty()&&nums_cop[nums_cop.size()-1]==nums[nums.size()-1]){
//         nums_cop.erase(nums_cop.end()-1);
//         nums.erase(nums.end()-1);
//     }

//     return nums.size();
// }

int findUnsortedSubarray(vector<int>& nums) {

    int maxn = INT32_MIN,right = -1;
    int minn = INT32_MAX,left = -1;
    int n = nums.size();

    for(int i = 0;i<n;i++){
        if(nums[i]>maxn){
            maxn = nums[i];
        }
        else{
            right = i;
        }
        if(nums[n-i-1]<minn){
            minn = nums[n-i-1];
        }
        else{
            left = n-i-1;
        }
    }

    return right == -1 ? 0 : right - left + 1;

}


int findUnsortedSubarray(vector<int>& nums) {

    vector<int> nums_cop = nums;
    sort(nums_cop.begin(),nums_cop.end());
    int index = 0,i;
    for(i = 0;i<nums.size();i++){
        if(nums_cop[i]==nums[i])index++;
        else break;
    }
    for(int j = nums.size()-1;j>=i;j--){
        if(nums_cop[j]==nums[j])index++;
        else break;
    }
    return nums.size()-index;
}

int main(){
    vector<int> t = {2,6,4,8,10,9,15};
    cout<<findUnsortedSubarray(t)<<endl;

}