#include<iostream>


using namespace std;
int N;
//ÁÂÇÏ¿ìÀ§
int dr[8] = { 0,1,0,-1,-1,-1,1,1};
int dc[8] = { -1,0,1,0,-1,1,-1,1};
int area[501][501];
int sr, sc;
int ans = 0;
/*
			2
		10	7	1
	5	a	y	x
		10	7	1
			2

		1	x	1
	2	7	y	7	2
		10	a	10
			5

		2
	1	7	10
	x	y	a	5
	1	7	10
		2

			5
		10	a	10
	2	7	y	7	2
		1	x	1
*/
void spread_dust(int r, int c, int d) {
	if (area[r][c] == 0)return;
	int nr, nc;
	int sum = 0;

	sum += (area[r][c] * 1) / 100;
	sum += (area[r][c] * 10) / 100;
	sum += (area[r][c] * 7) / 100;
	sum += (area[r][c] * 2) / 100;

	sum += (area[r][c] * 1) / 100;
	sum += (area[r][c] * 10) / 100;
	sum += (area[r][c] * 7) / 100;
	sum += (area[r][c] * 2) / 100;

	sum += (area[r][c] * 5) / 100;

	if (d == 0) {
		
		nr = r + dr[0]*2;
		nc = c + dc[0]*2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c] * 5)/100;
		else {
			area[nr][nc] += (area[r][c] * 5)/100;
		}
		nr = r + dr[1];
		nc = c + dc[1];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*7)/100;
		else {
			area[nr][nc] += (area[r][c]*7)/100;
		}

		nr = r + dr[1] * 2;
		nc = c + dc[1] * 2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*2)/100;
		else {
			area[nr][nc] += (area[r][c]*2)/100;
		}

		nr = r + dr[3];
		nc = c + dc[3];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*7)/100;
		else {
			area[nr][nc] += (area[r][c]*7)/100;
		}

		nr = r + dr[3] * 2;
		nc = c + dc[3] * 2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*2)/100;
		else {
			area[nr][nc] += (area[r][c]*2)/100;
		}

		nr = r + dr[4];
		nc = c + dc[4];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*10)/100;
		else {
			area[nr][nc] += (area[r][c]*10)/100;
		}
		nr = r + dr[5];
		nc = c + dc[5];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*1)/100;
		else {
			area[nr][nc] += (area[r][c]*1)/100;
		}
		nr = r + dr[6];
		nc = c + dc[6];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*10)/100;
		else {
			area[nr][nc] += (area[r][c]*10)/100;
		}
		nr = r + dr[7];
		nc = c + dc[7];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*1)/100;
		else {
			area[nr][nc] += (area[r][c]*1)/100;
		}
		nr = r + dr[0];
		nc = c + dc[0];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N) ans += area[r][c] - sum;
		else area[nr][nc] += area[r][c] - sum;
	}
	else if (d == 1) {
		nr = r + dr[1] * 2;
		nc = c + dc[1] * 2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*5)/100;
		else {
			area[nr][nc] += (area[r][c]*5)/100;
		}

		nr = r + dr[0];
		nc = c + dc[0];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*7)/100;
		else {
			area[nr][nc] += (area[r][c]*7)/100;
		}

		nr = r + dr[0] * 2;
		nc = c + dc[0] * 2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*2)/100;
		else {
			area[nr][nc] += (area[r][c]*2)/100;
		}

		nr = r + dr[2];
		nc = c + dc[2];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*7)/100;
		else {
			area[nr][nc] += (area[r][c]*7)/100;
		}

		nr = r + dr[2] * 2;
		nc = c + dc[2] * 2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*2)/100;
		else {
			area[nr][nc] += (area[r][c]*2)/100;
		}

		nr = r + dr[4];
		nc = c + dc[4];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*1)/100;
		else {
			area[nr][nc] += (area[r][c]*1)/100;
		}
		nr = r + dr[5];
		nc = c + dc[5];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*1)/100;
		else {
			area[nr][nc] += (area[r][c]*1)/100;
		}
		nr = r + dr[6];
		nc = c + dc[6];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*10)/100;
		else {
			area[nr][nc] += (area[r][c]*10)/100;
		}
		nr = r + dr[7];
		nc = c + dc[7];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*10)/100;
		else {
			area[nr][nc] += (area[r][c]*10)/100;
		}
		nr = r + dr[1];
		nc = c + dc[1];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N) ans += area[r][c] - sum;
		else area[nr][nc] += area[r][c] - sum;
	}
	else if (d == 2) {
		nr = r + dr[2] * 2;
		nc = c + dc[2] * 2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*5)/100;
		else {
			area[nr][nc] += (area[r][c]*5)/100;
		}

		nr = r + dr[1];
		nc = c + dc[1];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*7)/100;
		else {
			area[nr][nc] += (area[r][c]*7)/100;
		}

		nr = r + dr[1] * 2;
		nc = c + dc[1] * 2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*2)/100;
		else {
			area[nr][nc] += (area[r][c]*2)/100;
		}

		nr = r + dr[3];
		nc = c + dc[3];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*7)/100;
		else {
			area[nr][nc] += (area[r][c]*7)/100;
		}

		nr = r + dr[3] * 2;
		nc = c + dc[3] * 2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*2)/100;
		else {
			area[nr][nc] += (area[r][c]*2)/100;
		}

		nr = r + dr[4];
		nc = c + dc[4];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*1)/100;
		else {
			area[nr][nc] += (area[r][c]*1)/100;
		}
		nr = r + dr[5];
		nc = c + dc[5];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*10)/100;
		else {
			area[nr][nc] += (area[r][c]*10)/100;
		}
		nr = r + dr[6];
		nc = c + dc[6];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*1)/100;
		else {
			area[nr][nc] += (area[r][c]*1)/100;
		}
		nr = r + dr[7];
		nc = c + dc[7];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*10)/100;
		else {
			area[nr][nc] += (area[r][c]*10)/100;
		}
		nr = r + dr[2];
		nc = c + dc[2];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N) ans += area[r][c] - sum;
		else area[nr][nc] += area[r][c] - sum;
	}
	else if (d == 3) {
		nr = r + dr[3] * 2;
		nc = c + dc[3] * 2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*5)/100;
		else {
			area[nr][nc] += (area[r][c]*5)/100;
		}

		nr = r + dr[0];
		nc = c + dc[0];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*7)/100;
		else {
			area[nr][nc] += (area[r][c]*7)/100;
		}

		nr = r + dr[0] * 2;
		nc = c + dc[0] * 2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*2)/100;
		else {
			area[nr][nc] += (area[r][c]*2)/100;
		}

		nr = r + dr[2];
		nc = c + dc[2];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*7)/100;
		else {
			area[nr][nc] += (area[r][c]*7)/100;
		}

		nr = r + dr[2] * 2;
		nc = c + dc[2] * 2;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*2)/100;
		else {
			area[nr][nc] += (area[r][c]*2)/100;
		}

		nr = r + dr[4];
		nc = c + dc[4];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*10)/100;
		else {
			area[nr][nc] += (area[r][c]*10)/100;
		}
		nr = r + dr[5];
		nc = c + dc[5];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*10)/100;
		else {
			area[nr][nc] += (area[r][c]*10)/100;
		}
		nr = r + dr[6];
		nc = c + dc[6];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*1)/100;
		else {
			area[nr][nc] += (area[r][c]*1)/100;
		}
		nr = r + dr[7];
		nc = c + dc[7];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)ans += (area[r][c]*1)/100;
		else {
			area[nr][nc] += (area[r][c]*1)/100;
		}
		
		nr = r + dr[3];
		nc = c + dc[3];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N) ans += area[r][c] - sum;
		else area[nr][nc] += area[r][c] - sum;
		
	}
	area[r][c] = 0;
}
void move_tornado() {
	int cnt = 0;
	int dir = 0;
	int m_cnt = 1;
	int n_cnt = 0;
	temp_area[sr][sc] = 1;
	while (1) {
		n_cnt = m_cnt;
		while (n_cnt--) {
			sr += dr[dir];
			sc += dc[dir];
			temp_area[sr][sc] = 1;
			spread_dust(sr, sc, dir);
			if (sr == 0 && sc == 0)break;
			
		}
		if (sr == 0 && sc == 0)break;
		cnt++;
		dir++;
		if (cnt == 2) {
			cnt = 0;
			m_cnt++;
		}
		if (dir == 4)dir = 0;
	}
	
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];
		}
	}
	sr = sc = N / 2;
	move_tornado();
	cout << ans << '\n';
}