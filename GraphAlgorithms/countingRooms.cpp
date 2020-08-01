#include <bits/stdc++.h>
using namespace std;

int const mnx = 1e4+1;
int n,m;
int grid[mnx][mnx];

void checkNext(int grid[][mnx], int i , int j);

void printGrid(int grid[][mnx], int n, int m)
{

  for (int i = 0; i<n;i++) {
      for (int j = 0; j<m ;j++) {
        cout << grid[i][j];
      }
      cout << endl;
  }
}

void checkNext(int grid[][mnx], int i , int j)
{
  grid[i][j]= 0;

  if (i<n-1 && grid[i+1][j]==1) {
    checkNext(grid,i+1,j);
  }
  if (j<m-1 && grid[i][j+1]==1) {
    checkNext(grid,i,j+1);
  }
  if (i>0 && grid[i-1][j]==1) {
    checkNext(grid,i-1,j);
  }
  if (j>0 && grid[i][j-1]==1) {
    checkNext(grid,i,j-1);
  }

}

void error() {
  cout << "error" <<endl;
}


int main()
{

  cin >> n >> m;


  //error();

  char input[m];

  //error();
  for (int i= 0; i<n;i++) {

    cin >> input;
    //cout <<input << endl;
    for (int j = 0; j<m; j++) {
      if (input[j]=='#')
        grid[i][j]=0;
      else if (input[j]=='.')
        grid[i][j]=1;
    }
    //error();
  }


  //printGrid(grid, n,m);
  int sol = 0;
  for (int i = 0; i<n ; i++) {
    for (int j = 0; j<m; j++) {
      if (grid[i][j]==1) {
        sol++;
        checkNext(grid, i, j);
      }
    }
    //printGrid(grid, n, m);
  }
  cout << sol <<endl;

  //printGrid(grid,n,m);
}
