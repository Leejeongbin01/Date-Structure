#pragma once
#include <iostream>
#include <fstream>
#include "헤더.h"
#include <stack>
using namespace std;

class maze
{
private:
	int width;
	int height;
	int** map;
	stack<Location> s;
	Location exit;
public:
	maze() {
		init(0, 0);
	}
	~maze() {
		reset();
	}
	void init(int w, int h) {
		map = new int* [h];
		for (int i = 0; i < h; i++) {
			map[i] = new int[w];
		}
	}
	void reset() {
		for (int i = 0; i < height; i++)
		{
			delete[] map[i];
		}
		delete[]map;
	}
	void load(char* fname) {
		ifstream fin(fname, ios::in);

		fin >> width >> height;
		init(width, height);
		int tmp;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				fin >> tmp;
				map[i][j] = tmp;
				if (map[i][j] == 5) {
					Location entry(j, i);
					s.push(entry);
				}
				else if (map[i][j] == 9) {
					exit.col = i;
					exit.row = j;
				}
			}
			cout << endl;
		}
		fin.close();
	}
	bool is(int r, int c) {
		if (r < 0 || c < 0 || r >= 20 || c >= 10) {
			return false;
		}
		else {
			return map[c][r] == 1 || map[c][r] == 9;
		}
	}
	void print() {
		cout << "전체 미로의 크기  = " << height << " " << width << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (map[i][j] == 1)
				{
					cout << " ";
				}
				else if (map[i][j]) {
					cout << "X";
				}
				else if (map[i][j] == 7) {
					cout << "O";
				}
				else if (map[i][j] == 5) {
					cout << "E";
				}
				else if (map[i][j] == 9) {
					cout << "U";
				}
			}
			cout << endl;
		}
	}
	void search() {
		while (!s.empty() == false) {
			//비어 있지 않으면
			Location here = s.top();
			s.pop();

			int r = here.row;
			int c = here.col;
			map[c][r] = 7;
			if (exit.col == c && exit.row == r) {
				return;
			}
			else {
				map[c][r] = 7;
				if (is(r - 1, c)) {
					s.push(Location(r - 1, c));
				}
				if (is(r + 1, c)) {
					s.push(Location(r + 1, c));
				}
				if (is(r, c - 1)) {
					s.push(Location(r, c - 1));
				}
				if (is(r, c + 1)) {
					s.push(Location(r, c + 1));
				}
			}
		}
	}
};