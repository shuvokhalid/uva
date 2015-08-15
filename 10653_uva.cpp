/**
   uva online judge
   problem name  :: Bombs! NO they are Mines!!;
   problem id    :: 10653;
   catagory      :: bfs_2D_grid;
   my solution........................
**/

#include <bits/stdc++.h>
using namespace std;

struct point {
	int x , y;
	point () {}
	point (int x_ , int y_) {
		x = x_;
		y = y_;
	}
};

const int N = 1002;
int matrix[N][N];
int fx[] = {1 , 0 , -1 , 0};  
int fy[] = {0 , 1 , 0 , -1};  
int level[N][N];
queue < point > Q;
bool visited[N][N];

void bfs (int sx , int sy , int row , int col) {
	visited[sx][sy] = true;
	Q.push(point (sx , sy));
	level[sx][sy] = 0;
	while (!Q.empty()) {
		point tt = Q.front();
		for (int i = 0; i < 4; i++) {
			int tx = tt.x + fx[i];
			int ty = tt.y + fy[i];
			if (tx >= 0 && tx < row and ty >= 0 && ty < col and !visited[tx][ty] and matrix[tx][ty] != -1) {
				visited[tx][ty] = true;
				level[tx][ty] = level[tt.x][tt.y] + 1;
				Q.push(point (tx , ty));
			}
		}
		Q.pop();
	}
}

int main () {
	int row , col;
	while (scanf ("%d%d" , &row , &col) == 2) {
	    if (row == 0 && col == 0) break;
		memset (matrix , 0 , sizeof (matrix));
		memset (visited , 0 , sizeof (visited));
		
		int n; scanf ("%d" , &n);
		for (int i = 0; i < n; i++) {
			int x , y , z;
			scanf ("%d%d" , &x , &y);
			for (int ii = 0; ii < y; ii++) {
				scanf ("%d" , &z);
				matrix[x][z] = -1;
			}
		}
		int s1 , s2; 
		scanf ("%d%d" , &s1 , &s2);
		bfs (s1 , s2 , row , col);
		int d1 , d2;
		scanf ("%d%d" , &d1 , &d2);
		printf ("%d\n" , level[d1][d2]);
	}
}