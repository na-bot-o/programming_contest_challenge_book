#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N;
  int R;
  int X[1000];


  cin >> N;
  cin >> R;
  for (int value = 0; value<N;value++){
      cin >> X[value];
  }

  sort(X, X + N);

  int i = 0, ans = 0;

  while(i < N){
    //カバーしていない左足の点
    int s = X[i++];
    while(i < N && X[i] <= s + R) i++;

    //カバーされる最も右側の点まで移動
    int p = X[i-1];
    while(i < N && X[i] <= p + R) i++;

    ans++;
  }

  cout << ans << endl;


  return 0;
}