#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// 定义方向数组，用于上下左右移动
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

// 检查是否在地图范围内
bool isValid(int x, int y, int rows, int cols) {
	return x >= 0 && x < rows && y >= 0 && y < cols;
}

// 深度优先搜索（DFS）计算从 trailhead 出发的路径评分
int dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int x, int y) {
	int rows = map.size();
	int cols = map[0].size();

	// 如果到达高度为9的位置，返回1表示找到一条路径
	if (map[x][y] == 9) {
		return 1;
	}

	visited[x][y] = true; // 标记当前点为已访问
	int totalPaths = 0;

	// 尝试向四个方向移动
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (isValid(nx, ny, rows, cols) && !visited[nx][ny] &&
			map[nx][ny] == map[x][y] + 1) {
			// 递归搜索，并累计路径数
			totalPaths += dfs(map, visited, nx, ny);
		}
	}

	visited[x][y] = false; // 回溯
	return totalPaths;
}

int main() {
	// 打开输入文件
	ifstream inputFile("input_day10.txt");
	if (!inputFile.is_open()) {
		cerr << "Failed to open the file." << endl;
		return 1;
	}

	// 读取地图
	vector<vector<int>> map;
	string line;
	while (getline(inputFile, line)) {
		vector<int> row;
		for (char c : line) {
			row.push_back(c - '0'); // 将字符转换为数字
		}
		map.push_back(row);
	}
	inputFile.close();

	int rows = map.size();
	int cols = map[0].size();

	// 用于记录访问过的节点
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));

	int totalScoreSum = 0;

	// 遍历所有的起点，找到高度为0的位置
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (map[i][j] == 0) {
				// 从 trailhead 开始计算路径评分
				int trailheadScore = dfs(map, visited, i, j);
				totalScoreSum += trailheadScore; // 累计 trailhead 的评分
			}
		}
	}

	cout << "Sum of all trailhead ratings: " << totalScoreSum << endl;

	return 0;
}
