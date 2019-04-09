#include <iostream>

using namespace std;
#define INF 10000000

int n;
int a[10000001];

int dp[10000001];

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int res = 0;

  for(int i = 0; i < n; i++){
    dp[i] = 1;
    for(int j = 0; j < i; j++){
      //起点よりその前の値が低い場合、部分列になるので1足す
      if (a[j] < a[i]){
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    //各起点より前から取得できる部分数列の数の最大値を取得
    res = max(res, dp[i]);
  }
  cout << res << endl;


  // other solves
  // fill(dp, dp + n, INF);
  // for(int i = 0; i < n; i++){
  //   *lower_bound(dp, dp + n, a[i]) = a[i];
  // }
  // cout << lower_bound(dp, dp + n, INF) - dp << endl;
}