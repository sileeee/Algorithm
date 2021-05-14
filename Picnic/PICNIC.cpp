#include <iostream>
#include <memory.h>
#include <stdio.h>

using namespace std;
bool hasPair[11] = { false, };
int cnt = 0;

void countPair(bool** friendArr, int n) {
	int start = -1;

	for (int i = 0; i < n; i++) {
		if (hasPair[i] == false) {
			start = i;
			break;
		}
	}
	if (start == -1) {
		cnt++;
		return;
	}

	for (int i = start + 1; i < n; i++) {
		if (hasPair[start] == false && hasPair[i] == false && friendArr[start][i] == 1) {
			hasPair[start] = hasPair[i] = true;
			countPair(friendArr, n);
			hasPair[start] = hasPair[i] = false;
		}
	}

}


int main() {
	int c, n, m;

	bool** friendArr = new bool* [10];
	for (int i = 0; i < 10; i++) {
		friendArr[i] = new bool[10];
		memset(friendArr[i], false, sizeof(bool) * 10);
	}

	scanf_s("%d", &c);
	int* cntBuff = new int[c];
	for (int i = 0; i < c; i++) {
		scanf_s("%d", &n);
		scanf_s("%d", &m);
		for (int j = 0; j < m; j++) {
			int x, y;
			scanf_s("%d", &x);
			scanf_s("%d", &y);
			friendArr[x][y] = friendArr[y][x] = true;
		}
		countPair(friendArr, n);
		cntBuff[i] = cnt;

		//다시 초기화
		cnt = 0;
		hasPair[10] = { false, };
		for (int i = 0; i < 10; i++) {
			memset(friendArr[i], false, sizeof(bool) * 10);
		}
	}
	for (int i = 0; i < c; i++) {
		cout << cntBuff[i] << endl;
	}
}