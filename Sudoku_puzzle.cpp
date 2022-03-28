#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

int a[10][10];
bool valid(int i, int j, int num);
bool Check_the_num(int i, int j);
void find_next_to_fill(int& i, int& j);
void Print_Sudoku();

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
		}
	}
	if (!Check_the_num(0, 0)) {
		cout << "Error...this Sudoku puzzle is Invalid\n";
		return 0;
	}
	else cout << "Here is your solved Sudoku puzzle" << endl;
	Print_Sudoku();
	return 0;
}

void find_next_to_fill(int& i, int& j) {
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (a[i][j] == 0) {
				return;
			}
		}
	}
	i = j = -1;
}

bool valid(int j, int i, int num) {
	for (int x = 0; x < 9; x++) {
		if (a[i][x] == num) {
			return false;
		}
	}
	for (int y = 0; y < 9; y++) {
		if (a[y][j] == num) {
			return false;
		}
	}
	int section_i = 3 * (i / 3), section_j = 3 * (j / 3);
	for (int x = section_i; x < section_i + 3; x++) {
		for (int y = section_j; y < section_j + 3; y++) {
			if (a[x][y] == num) {
				return false;
			}
		}
	}
	return true;
}

bool Check_the_num(int i, int j) {
	find_next_to_fill(i, j);
	if (i == -1) {
		return true;
	}
	for (int num = 1; num <= 9; num++) {
		if (valid(j, i, num)) {
			a[i][j] = num;
			if (Check_the_num(i, j)) {
				return true;
			}
			a[i][j] = 0;
		}
	}
	return false;
}

void Print_Sudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return;
}