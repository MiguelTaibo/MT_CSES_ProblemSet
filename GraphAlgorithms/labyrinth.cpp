#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 1e4;
const int Mxn = 1e8;
int N,m, grid[mxn][mxn];
array<int,2> paths[Mxn];
char L[4] = {'D','U','R','L'};

int ind;

struct Nodo { int x, y, len, m, idx; };
Nodo newNodo(int x, int y, int len, int m, int past) {
    Nodo n;
    n.x = x;
    n.y = y;
    n.len = len;
    n.m = m;
    ind++;
    n.idx = ind;
    paths[n.idx][0]=m;
    paths[n.idx][1]=past;
    return n;
}

Nodo A,B;

/*
10
10
......A...
..........
B.........
..........
..........
..........
..........
..........
..........
..........

*/


bool tryFast() {
  int xM, yM, xD=A.x-B.x, yD=A.y-B.y;

  if (xD<0) xM=1;
  else xM = -1;
  if (yD<0) yM=1;
  else yM = -1;

  int len = 0;
  char res[mxn];

  for (int i = A.x; i!=A.x-xD;i+=xM) {
    if (grid[i][A.y]) {
      res[len++]=L[(int)(1-xM)/2];
    }
    else return true;
  }

  for (int j = A.y;j!=A.y-yD;j+=yM) {
    if (grid[B.y][j]) {
      res[len++]=L[(int)(5-yM)/2];
    }
    else return true;
  }
  cout << "YES" F;
  cout << len F;
  FOR(len)
    cout << res[i];
  cout F;
  return false;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> m;
  char temp;
  FOR(N) {
    FOR2(m) {
      cin >> temp;
      if (temp=='#') grid[i][j]=false;
      else grid[i][j]=true;
      if (temp=='A') {
        A.x=i; A.y=j; A.len=0;
      }
      else if (temp=='B') {
        B.x=i; B.y=j;
      }
    }
  }

  //FOR(n) { FOR2(m) cout << grid[i][j];  cout F; }

  if (tryFast()) {
    bool found = false;
    Nodo n;
    queue<Nodo> q;
    q.push(A);

    while (!q.empty()) {
      n = q.front();
      q.pop();

      if (n.x==B.x && n.y==B.y) { found = true; break; }
      if (n.x<N-1 && grid[n.x+1][n.y]) {
        grid[n.x+1][n.y]=false;
        q.push(newNodo(n.x+1,n.y,n.len+1,0,n.idx));
      }
      if (n.x>0 && grid[n.x-1][n.y]) {
        grid[n.x-1][n.y]=false;
        q.push(newNodo(n.x-1,n.y,n.len+1,1,n.idx));
      }
      if (n.y<m-1 && grid[n.x][n.y+1]) {
        grid[n.x][n.y+1]=false;
        q.push(newNodo(n.x,n.y+1,n.len+1,2,n.idx));
      }
      if (n.y> 0 && grid[n.x][n.y-1]) {
        grid[n.x][n.y-1]=1;
        q.push(newNodo(n.x,n.y-1,n.len+1,3,n.idx));
      }
    }

    if (found) {
      cout << "YES" << endl;
      cout << n.len F;
      int temp = n.idx;
      char res[n.len];
      for (int i = 0; i<n.len;i++) {
        res[i] = L[paths[temp][0]];
        temp = paths[temp][1];
      }
      for (int i = n.len-1;i>=0;i--){
        cout << res[i];
      } cout F;
    }
    else {
      cout << "NO" F;
    }
  }

}
