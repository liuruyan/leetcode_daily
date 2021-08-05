#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int array[101][101];
void v2a(vector<vector<int>>& times,int n){

    for(int i =0;i<n;i++){
       for(int j = 0;j<n;j++){
           array[i][j] = 999;
       }
    }
    for(auto &i:times){
        array[i[0]-1][i[1]-1] = i[2];
    }

}

//djistra find max(min(dis))
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    int dis[n],flags[n],min = 999,next = 0;
    memset(dis,999,sizeof(dis));
    memset(flags,0,sizeof(flags));
    v2a(times,n);
    for(int i = 0;i<n;i++)dis[i] = array[k-1][i];
    dis[k-1] = 0;
    flags[k-1] = 1;
    while(1){

        for(int i = 0;i<n;i++)
            if(dis[i]<min&&flags[i]==0){min = dis[i];next = i;}
        if(min == 999) break;
        for(int i =0;i<n;i++){
            if(flags[i]==0 && dis[next]+array[next][i]<dis[i]){
                dis[i] = dis[next]+array[next][i];
            }
        }
        flags[next] = 1;
        min = 999;
    }
    for(int i=0;i<n;i++){
        if(flags[i]==0)return -1;
    }
    sort(dis,dis+n);
    return dis[n-1];

}

int main(){
    vector<vector<int>> times = {{1,2,1}};
    cout<<networkDelayTime(times,2,1)<<endl;
}