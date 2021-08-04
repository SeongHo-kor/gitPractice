#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
struct info {
	int sr, sc;
	int er, ec;
};
struct axis{
	int r,c;
};
int area[65][65];
int temp_area[65][65];
int magic[1001];
int visited[65][65];
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };
int N, Q;
vector<info> squre_point;

int pow(int n) {
	int num = 1;
	while (n--) {
		num *= 2;
	}
	return num;
}
void input() {
	cin >> N >> Q;
	N = pow(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		cin >> magic[i];
	}
}
void copy_map(int A[][65],int B[][65]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = B[i][j];
		}
	}
}
void divided_area(int q) {
	int p_num = pow(q);
	int num = p_num - 1;
	int r = 0;
	int c = 0;
	while (1) {
		info now;
		now.sr = r; now.sc = c;
		now.er = r + num; now.ec = c + num;
		squre_point.push_back(now);
		c += p_num;
		if (c == N) {
			r += p_num;
			c = 0;
		}
		if (r == N && c == 0)break;
	}
}
void rotate_area() {
	for (int i = 0; i < (int)squre_point.size(); i++) {
		int sr = squre_point[i].sr;
		int sc = squre_point[i].sc;

		int er = squre_point[i].er;
		int ec = squre_point[i].ec;
		
		int r = sr; int c = sc;
		for (int i = sc; i <= ec; i++) {
			for (int j = er; j >= sr; j--) {
				temp_area[r][c] = area[j][i];
				c++;
			}
			c = sc;
			r++;
		}
	}
	copy_map(area, temp_area);
	memset(temp_area, 0, sizeof(temp_area));
}
void minus_area() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (area[i][j] == 0)continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
				if (area[nr][nc] == 0)continue;
				cnt++;
			}
			if (cnt < 3)temp_area[i][j] = area[i][j] - 1;
			else temp_area[i][j] = area[i][j];
		}
	}
	copy_map(area, temp_area);
	memset(temp_area, 0, sizeof(temp_area));
}
int squre_sum() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			res += area[i][j];
		}
	}
	return res;
}
int max_divided_squre() {
	int cnt = 1;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (area[i][j] == 0)continue;
			int res = 1;
			axis now;
			now.r = i; now.c = j;
			queue<axis> q;
			q.push(now);
			visited[i][j] = cnt;
			while (!q.empty()) {
				axis cur = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					axis next;
					next.r = cur.r + dr[k];
					next.c = cur.c + dc[k];
					if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= N)continue;
					if (area[next.r][next.c] == 0)continue;
					if (visited[next.r][next.c] > 0)continue;
					visited[next.r][next.c] = cnt;
					res++;
					q.push(next);
				}
			}
			cnt++;
			if (ans < res)ans = res;
		}
	}
	return ans;
}
void solved() {
	for (int i = 0; i < Q; i++) {
		squre_point.clear();
		divided_area(magic[i]);
		rotate_area();
		minus_area();
	}
	cout << squre_sum() << '\n';
	cout << max_divided_squre() << '\n';
}
int main() {
	input();
	solved();
	
	return 0;
}
