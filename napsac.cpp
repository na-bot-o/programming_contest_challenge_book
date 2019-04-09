#include <iostream>

using namespace std;

int dp[101][101];
int n,w[101],v[101];
int W;

int rec(int i, int j){
  if(dp[i][j] >= 0){
    //if you have already researched, use this again
    return dp[i][j];
  }
  int res;
  //指定数以上の品物はない
  if(i == n){
    res = 0;
  //重量オーバーなので足さない
  } else if(j < w[i]){
    res = rec(i + 1, j);
  } else {
    //足さないバージョンと足すバージョンの最大値をとる
    res = max(rec(i + 1,j),rec(i + 1, j - w[i]) + v[i]);
  }
  return dp[i][j] = res;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> w[i] >> v[i];
  }
  cin >> W;
  memset(dp,-1,sizeof(dp));
  cout << rec(0,W) << endl;
}

