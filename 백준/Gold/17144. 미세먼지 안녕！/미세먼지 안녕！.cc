#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

#define PII pair<int, int>
#define TIII tuple<int, int, int>

struct dust {
	vector<vector<int>> room;
	vector<PII> dust_pos; // {x, y}
	PII puricare = {-1, -1}; // {x, y}

	dust(int r, int c) {
		room = vector<vector<int>>(r, vector<int>(c));
	}

	void insert(int &x, int &y, int &v) {
		room[y][x] = v;

		if (v == -1 && puricare.first == -1) // 공기청정기 머리라면
			puricare = {x, y};
	}

	void spread() {
		static int w[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
		vector<TIII> update; // {x, y, v}

		for (auto &i : dust_pos) {
			auto &[x, y] = i;
			int spread_dust = room[y][x]/5
				, cnt = 0;

			for (int i = 0; i < 4; ++i) { // 사방향 다 막힌 경우는 없음, 최소 하나는 있다 (좌측 최상단, 바로 밑에 공기청정기)
				int mx = x + w[i][0], my = y + w[i][1];
				
				if (mx >= 0 && mx < room[0].size() && my >= 0 && my < room.size() && room[my][mx] != -1) {
					update.push_back({mx, my, spread_dust});
					++cnt;
				}
			}

			room[y][x] = room[y][x] - spread_dust * cnt;
		}

		for (auto &i : update) {
			auto &[x, y, v] = i;
			room[y][x] += v;
		}
	}

	void snort() { // 공기청정기는 항상 1열에 설치
		auto [x, y] = puricare;
		++x; // 공기청정기가 이동하면 큰일남
		int before = 0; // 공기청정기에서 나오는 바람은 깨끗함
		bool moved;

		// 위쪽
		do {
			moved = 0;

			int mx = x, my = y;

			if (x == 0) ++my;
			else if (y == 0) --mx;
			else if (x == room[0].size()-1) --my;
			else ++mx;
			
			if (room[my][mx] == -1) { // 공기청정기 안으로 들어간 경우
				room[y][x] = before; // 덮어쓰기
				continue; // break
			}
			else if (mx != x || my != y) {
				swap(room[y][x], before);
				x = mx, y = my, moved = 1;
			}
		} while (moved);

		// init
		x = puricare.first+1, y = puricare.second+1
		, before = 0; 

		// 아래쪽
		do {
			moved = 0;

			int mx = x, my = y;

			if (x == 0) --my;
			else if (y == room.size()-1) --mx;
			else if (x == room[0].size()-1) ++my;
			else ++mx;
			
			if (room[my][mx] == -1) { // 공기청정기 안으로 들어간 경우
				room[y][x] = before; // 덮어쓰기
				continue; // break
			}
			else if (mx != x || my != y) {
				swap(room[y][x], before);
				x = mx, y = my, moved = 1;
			}
		} while (moved);
	}

	void simulate() {
		dust_pos.clear();
		for (int i = 0; i < room.size(); ++i)
			for (int j = 0; j < room[0].size(); ++j)
				if (room[i][j] > 0)
					dust_pos.push_back({j, i});

		this->spread();
		this->snort();
	}
	
	int sum() {
		int result = 0;

		for (auto &i : room)
			for (auto &j : i)
				if (j != -1)
					result += j;
		
		return result;
	}

	void prt() {
		for (auto &i : room) {
			for (auto &j : i)
				cout << j << ' ';
			cout << '\n';
		}
	}
};

int main(){
    ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c, t;
	cin >> r >> c >> t;
	dust fine_dust(r, c);

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			int v;
			cin >> v;
			fine_dust.insert(j, i, v);
		}

	while (t--)
		fine_dust.simulate();

	cout << fine_dust.sum();
}