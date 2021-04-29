#include<iostream>
#include <cstring>
#include <iomanip>
#define MAX_VALUE 100
using namespace std;

double MinCost(int* n, int l, int size_n) {
	double min = MAX_VALUE; //최소 평균 대여 비용
	double avg = 0;
	int cnt = 0;

	for (int w = 0; w < size_n - l + 1; w++) { 
		for (int i = w; i < size_n - l + 1; i++) { 
			for (int j = w; j < l + i; j++) {
				avg += n[j];
				cnt++;
			}
			avg = avg / cnt;
			if (avg < min) {
				min = avg;
			}
			avg = 0;
			cnt = 0;
		}
	}
	return min;
}

int main() {
	int c, temp;
	cin >> c; //테스트 케이스의 수 C
	int* l = new int[c]; //공연 팀의 수 L
	int* num_n = new int[c];

	int** n = new int* [c]; // 공연장을 대여할 수 있는 날들의 수 N
	for (int i = 0; i < c; i++) {
		cin >> num_n[i] >> l[i];
		n[i] = new int[num_n[i]];
		memset(n[i], 0, sizeof(int) * num_n[i]); //메모리 공간을 0으로 초기화
		for (int j = 0; j < num_n[i]; j++) {
			cin >> temp;
			n[i][j] = temp;
		}
	}

	for (int i = 0; i < c; i++) {
		printf("%.12lf\n", MinCost(n[i], l[i], num_n[i]));
	}

	for (int i = 0; i < c; i++) {
		delete[]  n[i];
	}
	delete[] n; // 메모리 해제
}