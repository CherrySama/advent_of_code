#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

// answer: 23384288

int main() {
	// 打开输入文件
	std::ifstream inputFile("input_day1.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件！" << std::endl;
		return 1;
	}

	std::vector<int> set1, set2;
	int left, right;

	// 读取文件内容到两个列表
	while (inputFile >> left >> right) {
		set1.push_back(left);
		set2.push_back(right);
	}

	inputFile.close(); // 关闭文件

	// 构建 simlist 字典
	std::unordered_map<int, long long> simlist;
	for (const auto& elem : set2) {
		if (std::find(set1.begin(), set1.end(), elem) != set1.end()) {
			simlist[elem] += elem;
		}
	}

	// 计算 gap
	long long gap = 0;
	for (const auto& elem : set1) {
		if (simlist.find(elem) != simlist.end()) {
			gap += simlist[elem];
		}
	}

	// 输出结果
	std::cout << "gap 的值为: " << gap << std::endl;

	return 0;
}
