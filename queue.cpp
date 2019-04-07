#include <stack>
#include <iostream>
#include <queue>
// #include <cstdio>

using namespace std;

int main(){
  stack<int> s;
  queue<int> que;
  que.push(1);
  que.push(2);
  que.push(3);
  s.push(1);
  s.push(2);
  s.push(3);
  cout << "stack pop: " << s.top() << endl;//3
  // printf("%d\n",s.top());
  s.pop();

  cout << "que pop: " << que.front() <<endl; //1
  que.pop();

  cout << "stack pop: " <<s.top() << endl;//2
  // printf("%d\n",s.top());
  s.pop();


  cout << "que pop: " << que.front() <<endl; //2
  que.pop();


  cout << "stack pop: " <<s.top() << endl;//1
  // printf("%d\n",s.top());
  s.pop();


  cout << "que pop: " << que.front() <<endl; //3
  que.pop();


  return 0;

}