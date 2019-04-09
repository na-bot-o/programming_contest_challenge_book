#include <iostream>

using namespace std;

typedef long long ll;

int main(){
  int N;
  int L [20001];

  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> L[i];
  }

  ll ans = 0;


  while (N > 1) {
    int mii1 = 0, mii2 = 1;
    if(L[mii1] > L[mii2]) swap(mii1,mii2);

    for(int i = 2; i < N; i++){
      if(L[i] < L[mii1]){
        mii2 = mii1;
        mii1 = i;
      }
      else if (L[i] < L[mii2]){
        mii2 = i;
      }
    }

    // 一番短いのと2番めに短いのを足す
    int t = L[mii1] + L[mii2];
    ans += t;
    // 一番短い板の場所に上で足した値を、二番目に短い板の場所に一番右端の板の値をおく
    if(mii1 == N - 1) swap(mii1, mii2);
    L[mii1] = t;
    L[mii2] = L[N - 1];
    //一番右の配列を削除
    N--;

    cout << endl;
    
  }

  cout << ans << endl;

}