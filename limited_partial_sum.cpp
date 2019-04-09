#include <iostream>

using namespace std;

int n;
int a[100001],m[100001];
int K;

int dp[101];

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i] >> m[i];
  }
  cin >> K;

  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= K; j++) {
      //i番目の数値の個数を置いておく(前の値が部分和で出力可能な場所)
      if(dp[j] >= 0){
        dp[j] = m[i];
        // 残りがないor足した値にならない場所なら-1 (3から3足して4,5にならない)
      } else if (j < a[i] || dp[j - a[i]] <= 0){
        dp[j] = -1;
        // 値を使って残りの個数を1個減らす
      } else {
        dp[j] = dp[j - a[i]] - 1;
      }
    }
  }
  // K番目の値は0以上(すでにある数をつかってあらわせる)場合はYes
  if (dp[K] >= 0){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

}