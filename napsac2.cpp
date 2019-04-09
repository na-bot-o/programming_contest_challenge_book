#include <iostream>

using namespace std;

int dp[101][10001];
int n;
int W;
int w[10000001];
int v[101];

#define INF 100000000

int main(){
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> w[i] >> v[i];
  }
  cin >> W;

  //dpテーブルの値を大きい値で埋める
  fill(dp[0],dp[0]+ 100 * 100 + 1, INF);
  //初期の重さは0(品物持ってない)
  dp[0][0] = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 100 * 100; j++){
      if(j < v[i]){
        //価値の最大値をオーバーしていたら追加しない
        dp[i + 1][j] = dp[i][j];
      } else {
        //指定していた価値を満たす最小の重さをメモする(荷物を追加するかしないか)
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
      }
    }
  }
  int res = 0;
  //荷物をすべて持っているなかで重さ制限をクリアしつつ、より最大の価値を持つ値がresになる
  for(int i = 0; i <= 10000; i++){
    if(dp[n][i] <= W) res = i;
  }
  cout << res << endl;
}