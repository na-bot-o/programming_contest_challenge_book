#include <iostream>

int n;
int m;
int M;

int dp[10001][10001];
using namespace std;

int main(){
  cin >> n;
  cin >> m;
  cin >> M;

  dp[0][0] = 1;
  for(int i = 1; i <= m; i++){
    for(int j = 0; j <= n; j++){
      
      //分割可能なら、分割前の数値同士を足す
      if(j - i >= 0){
        dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % M;
      } else {
        //分割できないので、目の値を持ってくる
        dp[i][j] = dp[i - 1][j];
      }

    }
    cout << endl;
  }
  cout << dp[m][n] << endl;


}