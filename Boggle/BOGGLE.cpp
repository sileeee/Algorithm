#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool visited[5][5][10] = { false, };
int cnt = 0; //한 단어의 특정글자 위치

struct position {
	int y;
	int x;
};

bool findWord(position move[8], string map[5], string word, int y, int x) {
	cnt++;
	if (word.size() == 0) return true;
	if (y < 0 || y>5 || x < 0 || x>5) return false;

	for (int i = 0; i < 8; i++) {
		if (visited[y + move[i].y][x + move[i].x][cnt] == true) //방문 기록 있으면 탐색 안 함
			continue;
		else {
			if (y + move[i].y < 0 || y + move[i].y>5 || x + move[i].x < 0 || x + move[i].x>5) 
				continue;
			if (word[0] == map[y + move[i].y][x + move[i].x]) {
				visited[y + move[i].y][x + move[i].x][cnt] = true; //기록
				if (findWord(move, map, word.substr(1), y + move[i].y, x + move[i].x))
					return true;
				else {
					cnt--;
					continue;
				}
			}
		}
	}
	if (word.size() != 0) {
		cnt = 0;
		return false;
	}
}

void findFirstWord(position move[8], string map[5], string word, int y, int x) {
	bool flag = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (word[0] == map[i][j]) {
				visited[i][j][0] = true;
				for (int w = 0; w < 8; w++) {
					if (findWord(move, map, word.substr(1), i + move[w].y, j + move[w].x)) {
						flag = 1;
						cout << word << " YES"<<endl;
						return;
					}
					else
						continue;
				}
				if (flag == 0) {
					cout << word << " NO"<<endl;
					return;
				}
			}
		}
	}
	cout << word << " NO" << endl;
	return;
}

int main() {
	int c, n;
	cin >> c;
	cin.ignore(); //개행문자를 안 만나도록 

	string map[5];
	string answer;
	position move[8] = { {0, 1}, {-1, 1}, {-1 , 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1} };

	for (int i = 0; i < c; i++) {
		//입력
		for (int j = 0; j < 5; j++) {
			getline(cin, map[j]);
		}
		cin >> n;
		cin.ignore();

		vector<string> word(n);
		for (int j = 0; j < n; j++) {
			getline(cin, word[j]);
		}
		//탐색 시작
		for (int i = 0; i < n; i++) {
			memset(visited, false, sizeof(visited));
			findFirstWord(move, map, word[i], 0, 0);
		}

	}

}
