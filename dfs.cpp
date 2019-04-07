#include <iostream>

using namespace std;

int main(){

}
int N,M;
char field[MAX_N][MAX_M + 1]
//n number of seisuu
//a array of seisuu
//k sum value
void dfs(int x, int y){
  field[x][y] = '.';

  for(int dx = -1; dy <= 1; dx++){
    for(int dy = -1; dy <= 1; dy++){
      int nx = x + dx, ny = y + dy;

      if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W'){
        dfs(nx,ny);
      }
    }

  }
  return;
}

void solve(){
  int res = 0;
  for(int i = 0; i<N;i++){
    for(int j = 0; j <M; j++){
      if(field[i][j]== 'W'){
        dfs(i,j);
        res++;
      }
    }
  }
  cout << res << endl;
}