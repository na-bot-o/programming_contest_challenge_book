#include <iostream>

using namespace std;

int n;
int w[101], v[101];
int W;
int dp[101][10001]; //dp table

int main(){
  //input data
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> w[i] >> v[i];
  }
  cin >> W;

  // iは荷物の配列、jは荷物の重さの配列
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= W; j++){
      //重量オーバーになるなら追加しない
      if(j < w[i]) {
        dp[i + 1][j] = dp[i][j];
      } else {
        //荷物を乗せる場合とのせない場合で価値がmaxな方を足す
        dp[i + 1][j] = max(dp[i][j],dp[i + 1][j - w[i]] + v[i]);
      }
    } 
  }

  cout << dp[n][W] << endl;



}