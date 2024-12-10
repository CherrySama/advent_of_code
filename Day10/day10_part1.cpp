#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// ���巽�����飬�������������ƶ�
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

// ����Ƿ��ڵ�ͼ��Χ��
bool isValid(int x, int y, int rows, int cols) {
	return x >= 0 && x < rows && y >= 0 && y < cols;
}

// �������������DFS��Ѱ��������Ч·��
int dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int x, int y, set<pair<int, int>>& visitedTrail) {
	int rows = map.size();
	int cols = map[0].size();

	// ����Ѿ����ʹ���·�������� 0
	if (visitedTrail.find({ x, y }) != visitedTrail.end()) {
		return 0;
	}

	visited[x][y] = true;
	visitedTrail.insert({ x, y }); // ��Ǹõ��ѷ���

	// �������߶�Ϊ9��λ�ã�����1����ʾ�ҵ�һ��·��
	if (map[x][y] == 9) {
		visited[x][y] = false; // ����
		return 1;
	}

	int totalPaths = 0;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (isValid(nx, ny, rows, cols) && !visited[nx][ny] &&
			map[nx][ny] == map[x][y] + 1) {
			totalPaths += dfs(map, visited, nx, ny, visitedTrail);
		}
	}

	visited[x][y] = false; // ����
	return totalPaths;
}

int main() {
	// �������ļ�
	ifstream inputFile("input_day10.txt");
	if (!inputFile.is_open()) {
		cerr << "Failed to open the file." << endl;
		return 1;
	}

	// ��ȡ��ͼ
	vector<vector<int>> map;
	string line;
	while (getline(inputFile, line)) {
		vector<int> row;
		for (char c : line) {
			row.push_back(c - '0'); // ���ַ�ת��Ϊ����
		}
		map.push_back(row);
	}
	inputFile.close();

	int rows = map.size();
	int cols = map[0].size();

	// ���ڼ�¼���ʹ��Ľڵ�
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));

	int totalScore = 0;

	// �������е���㣬�ҵ��߶�Ϊ0��λ��
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (map[i][j] == 0) {
				set<pair<int, int>> visitedTrail; // ÿ�� trailhead ��ʼ���µ��ѷ���·������
				totalScore += dfs(map, visited, i, j, visitedTrail);
			}
		}
	}

	cout << "Total score of all trailheads: " << totalScore << endl;

	return 0;
}
