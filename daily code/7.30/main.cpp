#include<iostream>
#include<math.h>
using namespace std;

//采用多项式展开的思想反向：a*26^(n-1)+b*26^(n-2)+……+..26^0

int titleToNumber(string columnTitle) {
    int ans = 0;
    int jishu = 1;
    for(int i = columnTitle.length()-1;i >= 0;i--){
        ans+=((columnTitle[i]-'A'+1)*jishu);
        jishu*=26;
        
    }
    return ans;
}

//采用进制转化思想正想：ans = ans*26+..

int right (string columnTitle){
    int ans = 0;
    for (int i = 0;i<columnTitle.length();i++){
        ans = ans*26+columnTitle[i]-'A'+1;
    }
    return ans;
}



int main(){
    
    cout<<right("ZY")<<endl;
    return 0;
}