#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

char L[4] = {'U','D','L','R'};

typedef long long ll;
const int mxn = 2e4;
const int MXN = 1e8;
int x,m,n, a[mxn], ind;
bool grid[mxn][mxn];
char res[mxn];
bool found = false;

// arr(3)={x,y,step}
queue<arr(3)> mons;
queue<arr(5)> you;
array<int,2> paths[MXN];

arr(5) newNodo(int x, int y, int len, int m, int past) {
    ind++;
    paths[ind][0]=m;
    paths[ind][1]=past;
    return {x,y,len,m,ind};
}

bool inRangeX(int x) {
  return 0<=x && x<n;
}

bool inRangeY(int y) {
  return 0<=y && y<m;
}

void printGrid() {
  FOR(n) {
    FOR2(m) {
      cout << grid[i][j];
    } cout F;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  char input[mxn];
  for (int i = 0; i<n;i++) {
    cin >> input;
    for (int j = 0; j<m;j++) {
      if (input[j]=='#') {
        grid[i][j]=false;
      }
      else if (input[j]=='.') {
        grid[i][j]=true;
      }
      else if (input[j]=='A') {
        grid[i][j]=false;
        you.push({i,j,0});
      }
      else if (input[j]=='M') {
        grid[i][j]=false;
        mons.push({i,j,0});
      }
    }
  }

  arr(3) p;
  arr(5) y;
  int len=0;
  while(!found && !you.empty()) {
    //cout << len F;
    //cout << mons.size() SPACE you.size() F;
    //printGrid();
    while (!mons.empty()) {
      p = mons.front();
      if (p[2]>len) {break;}
      mons.pop();
      if (inRangeX(p[0]-1) && grid[p[0]-1][p[1]]) {
        grid[p[0]-1][p[1]]=false;
        mons.push({p[0]-1,p[1],p[2]+1});
      }
      if (inRangeX(p[0]+1) && grid[p[0]+1][p[1]]) {
        grid[p[0]+1][p[1]]=false;
        mons.push({p[0]+1,p[1],p[2]+1});
      }
      if (inRangeY(p[1]-1) && grid[p[0]][p[1]-1]) {
        grid[p[0]][p[1]-1]=false;
        mons.push({p[0],p[1]-1,p[2]+1});
      }
      if (inRangeX(p[1]+1) && grid[p[0]][p[1]+1]) {
        grid[p[0]][p[1]+1]=false;
        mons.push({p[0],p[1]+1,p[2]+1});
      }
    }
    while(!you.empty()) {
      y = you.front();
      if (y[2]>len) {break;}
      you.pop();
      if (y[0]==n-1 || y[1]==m-1 || y[0]==0 || y[1]==0) {found = true; break;}
      if (inRangeX(y[0]-1) && grid[y[0]-1][y[1]]) {
        grid[y[0]-1][y[1]]=false;
        you.push(newNodo(y[0]-1,y[1],y[2]+1,0,y[4]));
      }
      if (inRangeX(y[0]+1) && grid[y[0]+1][y[1]]) {
        grid[y[0]+1][y[1]]=false;
        you.push(newNodo(y[0]+1,y[1],y[2]+1,1,y[4]));
      }
      if (inRangeY(y[1]-1) && grid[y[0]][y[1]-1]) {
        grid[y[0]][y[1]-1]=false;
        you.push(newNodo(y[0],y[1]-1,y[2]+1,2,y[4]));
      }
      if (inRangeY(y[1]+1) && grid[y[0]][y[1]+1]) {
        grid[y[0]][y[1]+1]=false;
        you.push(newNodo(y[0],y[1]+1,y[2]+1,3,y[4]));
      }

    }

    len++;

  }

  if (found) {
    cout << "YES" << endl;
    cout << y[2] F;
    int temp = y[4];
    char res[y[2]];
    for (int i = 0; i<y[2];i++) {
      res[i] = L[paths[temp][0]];
      temp = paths[temp][1];
    }
    for (int i = y[2]-1;i>=0;i--){
      cout << res[i];
    } cout F;
  }
  else {
    cout << "NO" F;
  }





}
