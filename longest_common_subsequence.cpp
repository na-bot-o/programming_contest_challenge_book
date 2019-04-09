#include <iostream>

using namespace std;

int n;
int m;

int dp[1001][1001];

int main(){
  cin >> n;
  cin >> m;

  char s[n];
  char t[m];

  cin >> s;
  cin >> t;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(s[i] == t[j]){
        //文字列が一致していたら1足す
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        //前段の値の最大値をおく
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }
  cout << dp[n][m] << endl;
}