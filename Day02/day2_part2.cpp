#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

// 判断给定的级别列表是否安全
bool isSafeReport(const std::vector<int>& levels) {
	if (levels.size() < 2) return true; // 单个级别的报告视为安全

	bool increasing = true;
	bool decreasing = true;

	for (size_t i = 1; i < levels.size(); ++i) {
		int diff = levels[i] - levels[i - 1];
		if (std::abs(diff) < 1 || std::abs(diff) > 3) {
			return false; // 相邻级别差值不在1到3之间
		}
		if (diff > 0) decreasing = false;
		if (diff < 0) increasing = false;
	}

	return increasing || decreasing; // 必须全增或全减
}

// 判断是否可以通过移除一个级别使报告安全
bool canBeMadeSafeByRemovingOne(const std::vector<int>& levels) {
	if (isSafeReport(levels)) return true; // 如果原报告已安全

	// 遍历levels列表的每个元素
	for (size_t i = 0; i < levels.size(); ++i) {
		bool increasing = true;
		bool decreasing = true;

		for (size_t j = 1; j < levels.size(); ++j) {
			if (j == i) continue; // 跳过被移除的元素

			size_t prev = (j == i + 1) ? j - 2 : j - 1; // 处理跳过元素后的前一个索引
			if (prev >= levels.size()) continue;

			int diff = levels[j] - levels[prev];
			if (std::abs(diff) < 1 || std::abs(diff) > 3) {
				increasing = false;
				decreasing = false;
				break;
			}

			if (diff > 0) decreasing = false;
			if (diff < 0) increasing = false;
		}

		if (increasing || decreasing) return true;
	}

	return false;
}

int main() {
	std::ifstream inputFile("input_day2.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件！" << std::endl;
		return 1;
	}

	std::string line;
	int count = 0;

	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);
		std::vector<int> levels;
		int level;
		while (iss >> level) {
			levels.push_back(level);
		}
		if (canBeMadeSafeByRemovingOne(levels)) {
			++count;
		}
	}

	inputFile.close();
	std::cout << "满足条件的报告数量为: " << count << std::endl;
	return 0;
}
