#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib> 

int main() {
	// 打开文件
	std::ifstream inputFile("input_day1.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件!" << std::endl;
		return 1;
	}

	std::vector<int> leftList, rightList;
	int left, right;

	// 从文件读取数据
	while (inputFile >> left >> right) {
		leftList.push_back(left);
		rightList.push_back(right);
	}

	inputFile.close(); // 关闭文件

	// 对两个列表排序
	std::sort(leftList.begin(), leftList.end());
	std::sort(rightList.begin(), rightList.end());

	// 计算配对距离的总和
	long long totalDistance = 0;
	for (size_t i = 0; i < leftList.size(); ++i) {
		totalDistance += std::abs(leftList[i] - rightList[i]);
	}

	// 输出结果
	std::cout << "配对距离总和为: " << totalDistance << std::endl;

	return 0;
}
