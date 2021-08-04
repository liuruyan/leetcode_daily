#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int triangleNumber(vector<int>& nums) {
    int n = nums.size(),ans = 0;
    sort(nums.begin(),nums.end());
    if(n == 1||n==0||n==2) return ans;
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            int left = j+1,right = n-1,k=j;
            while(left<=right){
                int mid = (left+right)/2;
                if(nums[mid]<nums[i]+nums[j]){
                    left = mid+1;
                    k = mid;
                }
                else{
                    right = mid-1;
                }
            }
            ans+=(k-j);
        }
    }
    return ans;
}
//暴力 
// int triangleNumber(vector<int>& nums) {
//     int MIN,MAX;
//     int n = nums.size(),ans = 0;
//     if(n == 1||n==0||n==2) return ans;
//     for(int i = 0;i<n-1;i++){
//         for(int j = i+1;j<n;j++){
//             MIN = abs(nums[i]-nums[j]);
//             MAX = nums[i]+nums[j];
//             for(int k = 0;k<n;k++){
//                 if(k!=i&&k!=j&&nums[k]<MAX&&nums[k]>MIN) ans++;
//             }
//         }
//     }
//     return ans/3;
// }

int main(){


}