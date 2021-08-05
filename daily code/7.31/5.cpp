#include<iostream>
using namespace std;
//dp question
// int dp(int i,int j,string s){
//     if(i==j) return 1;
//     else if(i+1==j) return s[j]==s[i];
//     else{
//         return s[i]==s[j]&&dp(i+1,j-1,s)==1?1:0;
//     }
// }


// string longestPalindrome(string s) {
//     int dpa[s.length()][s.length()];
//     int ans_i,ans_j,longS=0;
    
//     for(int i = 0;i<s.length();i++){
//         for (int j = i; j < s.length(); j++){
//             dpa[i][j] = dp(i,j,s);
//         }
//     }

//     for(int i = 0;i<s.length();i++){
//         for(int j = i;j<s.length();j++){
//             if(dpa[i][j]){
//                 if(longS>(j-i+1))continue;
//                 ans_i = i;ans_j=j;
//                 longS = j-i+1;
//             }
//         }
//     }
//     string ans = s.substr(ans_i,longS);
//     return ans;

// }
pair<int,int> expandstring(string s,int i,int j){
    while(i>=0 && j<s.length() && s[i] == s[j]){
        i--;j++;
    }
    return {i+1,j-1};
}
string longestPalindrome(string s){
    int start = 0,end = 0;
    for(int i = 0;i<s.length();i++){
        pair<int,int> one = expandstring(s,i,i);
        pair<int,int> two = expandstring(s,i,i+1);

        if(one.second-one.first>end-start){
            end = one.second;start = one.first;
        }

        if(two.second-two.first>end-start){
            end = two.second;start = two.first;
        }
    }
    return s.substr(start,end-start+1);

}

int main(){
    cout<<longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth")<<endl;

}