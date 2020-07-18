
#include <list>
#include <stdlib.h>
#include <iostream>

struct Solution {
    int grid[7][7];
    char path[48]="???????????????????????????????????????????????";
    int suma = 0;
    int x = 0;
    int y = 0;
};

bool inRange(int n)
{
    bool res = (0<=n && n<7);
    return res;
}

int * checkNeightbors(int grid[7][7], int x, int y, int res[4])
{
    if (inRange(x-1) && grid[x-1][y]==0) {
        res[0] = 1;
    } if (inRange(x+1) && grid[x+1][y]==0) {
        res[1] = 1;
    } if (inRange(y-1) && grid[x][y-1]==0) {
        res[2] = 1;
    } if (inRange(y+1) && grid[x][y+1]==0) {
        res[3] = 1;
    }
    return res;
}

int numNeightbors(int grid[7][7], int x, int y)
{
    int res = 0;
    if (inRange(x-1) && grid[x-1][y]==0) {
        res++;
    } if (inRange(x+1) && grid[x+1][y]==0) {
        res++;
    } if (inRange(y-1) && grid[x][y-1]==0) {
        res++;
    } if (inRange(y+1) && grid[x][y+1]==0) {
        res++;
    }
    return res;
}

int sum(int list[4])
{
    int res = 0;
    for (int i=0;i<4;i++) {
        if (list[i]==1)
            res++;
    }
    return res;
}

bool compList(int must[4], int imps[4])
{
    for (int i=0; i<4;i++) {
        if (imps[i]==1 && must[i]==1)
            return true;
    }
    return false;
}

char to_string(int n)
{
    if (n==1) {
        return '1';
    } else {
        return '0';
    }
}

void printGrid(int grid[7][7])
{
    char pr[7];
    for (int i=0; i<7;i++) {
        for (int j = 0; j<7; j++) {
            pr[j]=to_string(grid[i][j]);
        }
        std::cout << " " << pr << std::endl;
    }
    std::cout << "\n";
}

void tryNextMoves(Solution &s, char input[48], int respuesta[48])
{
    respuesta[s.suma]++;
    if (s.suma==47) {
        if (input[47]=='?') {
            respuesta[48]++;
        }
        else if (input[47]=='L' && s.x==6 && s.y==1) {
            respuesta[48]++;
        }
        else if (input[47]=='D' && s.x==5 && s.y==0) {
            respuesta[48]++;
        }
    }

    int res[4] = {0,0,0,0};
    int *nn = checkNeightbors(s.grid,s.x,s.y, res);
    int must[4] = {0,0,0,0};
    int imps[4] = {0,0,0,0};


    if (nn[0]==1) {
        int n = numNeightbors(s.grid,s.x-1,s.y);
        if (n==0) {
            return;
        } else if (n==1) {
            must[0]=1;
        }
    }
    if (nn[1]==1) {
        int n = numNeightbors(s.grid,s.x+1,s.y);
        if (n==0) {
            return;
        } else if (s.x+1==6 && s.y==0) {
            imps[1]=1;
        } else if (n==1) {
            must[1]=1;
        }
    }
    if (nn[2]==1) {
        int n = numNeightbors(s.grid,s.x,s.y-1);
        if (n==0) {
            return;
        } else if (s.x==6 && s.y-1==0) {
            imps[2]=1;
        } else if (n==1) {
            must[2]=1;
        }
    }
    if (nn[3]==1) {
        int n = numNeightbors(s.grid,s.x,s.y+1);
        if (n==0) {
            return;
        } else if (n==1) {
            must[3]=1;
        }
    }

    if (sum(must)>1) {
        return;
    }
    else if (sum(must)==1) {
        if (sum(imps)==0 || !(compList(must,imps))) {
            nn = must;
        }
    }
    else if (imps[1]!=0) {
        nn[1]=0;
    }
    else if (imps[2]==1) {
        nn[2]=0;
    }

    if (input[s.suma]=='?') {
        if (nn[0]==1) {
            Solution temp = s;
            temp.path[temp.suma]='U';
            temp.suma++;
            temp.x--;
            temp.grid[temp.x][temp.y]=1;
            tryNextMoves(temp,input, respuesta);
        }
        if (nn[1]==1) {
            Solution temp = s;
            temp.path[temp.suma]='D';
            temp.suma++;
            temp.x++;
            temp.grid[temp.x][temp.y]=1;
            tryNextMoves(temp,input, respuesta);
        }
        if (nn[2]==1) {
            Solution temp = s;
            temp.path[temp.suma]='L';
            temp.suma++;
            temp.y--;
            temp.grid[temp.x][temp.y]=1;
            tryNextMoves(temp,input, respuesta);
        }
        if (nn[3]==1) {
            Solution temp = s;
            temp.path[temp.suma]='R';
            temp.suma++;
            temp.y++;
            temp.grid[temp.x][temp.y]=1;
            tryNextMoves(temp,input, respuesta);
        }
    }
    else if (input[s.suma]=='U') {
        if (nn[0]==1) {
            Solution temp = s;
            temp.path[temp.suma]='U';
            temp.suma++;
            temp.x--;
            temp.grid[temp.x][temp.y]=1;
            tryNextMoves(temp,input, respuesta);
        }
    }
    else if (input[s.suma]=='D') {
        if (nn[1]==1) {
            Solution temp = s;
            temp.path[temp.suma]='D';
            temp.suma++;
            temp.x++;
            temp.grid[temp.x][temp.y]=1;
            tryNextMoves(temp,input, respuesta);
        }
    }
    else if (input[s.suma]=='L') {
        if (nn[2]==1) {
            Solution temp = s;
            temp.path[temp.suma]='L';
            temp.suma++;
            temp.y--;
            temp.grid[temp.x][temp.y]=1;
            tryNextMoves(temp,input, respuesta);
        }
    }
    else if (input[s.suma]=='R') {
        if (nn[3]==1) {
            Solution temp = s;
            temp.path[temp.suma]='R';
            temp.suma++;
            temp.y++;
            temp.grid[temp.x][temp.y]=1;
            tryNextMoves(temp,input, respuesta);
        }
    }

}

int main()
{

    int respuesta[49];
    for (int i =0;i<49;i++) {
        respuesta[i]=0;
    }

    char input[48];
    std::cin >> input;
    //std::cout <<input[47] << std::endl;

    Solution s;
    for (int i = 0; i<7; i++) {
        for (int j = 0; j<7; j++) {
            s.grid[i][j]=0;
        }
    }
    s.grid[0][0]=1;

    tryNextMoves(s,input,respuesta);

    std::cout << respuesta[48] << std::endl;




}