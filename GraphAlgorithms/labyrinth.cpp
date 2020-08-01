#include <bits/stdc++.h>
#include <list>
using namespace std;

const int mnx = 1e4;
const int pathlen = 5e5;
int n,m,x,y;
int grid[mnx][mnx];
const char ps[4] = {'U','D','L','R'};

struct Nodo {
  int x;
  int y;
  int len;
  list<char> move;
  Nodo* parent;
} ;

void printGrid(int grid[][mnx], int n, int m)
{

  for (int i = 0; i<n;i++) {
      for (int j = 0; j<m ;j++) {
        cout << grid[i][j];
      }
      cout << endl;
  }
}

void error() {
  cout << "error" <<endl;
}

void assingArray(char a[], char b[], int len)
{
  for (int i = 0; i<len;i++) {
    a[i]=b[i];
  }
}

void BFS(Nodo s, Nodo &res)
{
    // Create a queue for BFS
    list<Nodo> queue;

    // Mark the current node as visited and enqueue it
    grid[s.x][s.y]=0;
    queue.push_back(s);

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
        x = s.x; y = s.y;

        if (x>0 && grid[x-1][y]>=1) {

          Nodo node;
          node.parent = &s;
          node.len = s.len+1;
          node.x= s.x-1;
          node.y = s.y;
          node.move = s.move;
          node.move.push_back(ps[0]);
          //assingArray(node.move,s.move,s.len);
          //node.move[node.len-1] = ps[0];

          if (grid[node.x][node.y]==2) {
            res = node;
            //cout << "bien";
            break;
          }
          grid[node.x][node.y]=0;
          queue.push_back(node);
        }
        if (x+1<n && grid[x+1][y]>=1) {

          Nodo node;
          node.parent = &s;
          node.len = s.len+1;
          node.x= s.x+1;
          node.y = s.y;
          node.move = s.move;
          node.move.push_back(ps[1]);
          //assingArray(node.move,s.move,s.len);
          //node.move[node.len-1] = ps[1];

          if (grid[node.x][node.y]==2) {
            res = node;
            ////cout << "bien";
            break;
          }
          grid[node.x][node.y]=0;
          queue.push_back(node);
        }
        if (y>0 && grid[x][y-1]>=1) {

          Nodo node;
          node.parent = &s;
          node.len = s.len+1;
          node.x= s.x;
          node.y = s.y-1;
          node.move = s.move;
          node.move.push_back(ps[2]);
          //assingArray(node.move,s.move,s.len);
          //node.move[node.len-1] = ps[2];

          if (grid[node.x][node.y]==2) {
            res = node;
            //cout << "bien";
            break;
          }
          grid[node.x][node.y]=0;
          queue.push_back(node);
        }
        if (y+1<m && grid[x][y+1]>=1) {

          Nodo node;
          node.parent = &s;
          node.len = s.len+1;
          node.x= s.x;
          node.y = s.y+1;
          node.move = s.move;
          node.move.push_back(ps[3]);
          //assingArray(node.move,s.move,s.len);
          //node.move[node.len-1] = ps[3];

          if (grid[node.x][node.y]==2) {
            res = node;
            //cout << "bien";
            break;
          }
          grid[node.x][node.y]=0;
          queue.push_back(node);
        }

    }
}

int main()
{

  cin >> n >> m;

  char input[m];

  for (int i= 0; i<n;i++) {
    cin >> input;
    for (int j = 0; j<m; j++) {
      if (input[j]=='#')
        grid[i][j]=0;
      else if (input[j]=='.')
        grid[i][j]=1;
      else if (input[j]=='A') {
          grid[i][j]=-1;
          x = i; y = j;
      }
      else if (input[j]=='B')
        grid[i][j]=2;
    }
  }

  Nodo node;
  node.parent = NULL;
  node.x = x;
  node.y = y;
  node.len = 0;

  Nodo solution= node;
  BFS(node, solution);
  //cout << "jkskdf" << endl;

  if (solution.len>0) {
    cout << "YES" << endl;
    int len = solution.len;
    cout << solution.len << endl;
    for_each(solution.move.begin(), solution.move.end(), [](char a)
{
    std::cout<<a;
});
    cout <<endl;
  }
  else {
    cout << "NO" << endl;
  }


}
