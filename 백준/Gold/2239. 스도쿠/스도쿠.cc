#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define GROUP(i, j) i/3*3+j/3

int sudoku[9][9]
	, row_mask[9]
	, col_mask[9]
	, block_mask[9];
vector<pair<int,int>> to_fill;

void backtrack(int idx = 0) {
	static bool complete = 0;

    if (idx == to_fill.size()) { // 종료조건
        complete = true;
        return;
    }
    
    if (complete) return;
    
	auto &[r, c] = to_fill[idx];
	int b = GROUP(r, c);
    
    for (int num = 1; num <= 9; num++) {
        int bit = 1 << (num - 1);
        if ((row_mask[r] | col_mask[c] | block_mask[b]) & bit) continue;  // 이미 같은 행, 열, 블록에서 쓰였는가
        
        sudoku[r][c] = num;
        row_mask[r]   |= bit; // or로 기록하기
        col_mask[c]   |= bit;
        block_mask[b] |= bit;
        
        backtrack(idx + 1);
        if (complete) return; // 다 만들어놓고 되돌리면 의미가 없음
        
        sudoku[r][c] = 0;
        row_mask[r]   &= ~bit; // and, not으로 되돌리기
        col_mask[c]   &= ~bit;
        block_mask[b] &= ~bit;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
			char c;
			cin >> c;
            sudoku[i][j] = c - '0';

            if (sudoku[i][j]) {
                int bit = 1 << (sudoku[i][j] - 1);
				// 1 - 000000001
				// 2 - 000000010
				// 3 - 000000100
				// ...
				// 9 - 100000000
                row_mask[i]   		   |= bit;
                col_mask[j]   		   |= bit;
                block_mask[GROUP(i,j)] |= bit;
            }
			
			else
                to_fill.emplace_back(i,j);
				// https://velog.io/@ehdbs28/emplaceback-%EA%B3%BC-pushback%EC%9D%98-%EC%B0%A8%EC%9D%B4%EC%A0%90
				// 더 효율적임
        }
    }

    backtrack();

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j)
			cout << sudoku[i][j];
		cout << '\n';
	}
}
