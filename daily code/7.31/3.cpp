#include<iostream>
#include<algorithm>
#include<string.h>
#include<list>
using namespace std;
list<char> L;

int lengthOfLongestSubstring(string s) {
    int ans=0,mostL = 0;
    for (int iter = 0;iter<s.length();iter++){
        for(int i = iter;i<s.length();i++){
            if(find(L.begin(),L.end(),s[i])!=L.end()){
                break;
            }
            L.push_back(s[i]);
            mostL++;
        }
        ans = ans>mostL?ans:mostL;
        L.clear();
        mostL=0;
    }
    return ans;  
}

int main(){

    cout<<lengthOfLongestSubstring(" 121")<<endl;

}