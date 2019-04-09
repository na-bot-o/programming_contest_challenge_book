#include <iostream>

using namespace std;

int n,m,M;

int a[1001];

int dp[1001][1001];

int main(){
  cin >> n;
  cin >> m;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  cin >> M;

  for(int i = 0; i <= n; i++){
    dp[i][0] = 1;
  }
  for(int i = 0; i < n; i++){
    for(int j = 1; j <= m; j++){
      if(j - 1 - a[i] >= 0){
        dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
      } else {
        dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
      }
    }
    cout << endl;

  }


  cout << dp[n][m] << endl;
}