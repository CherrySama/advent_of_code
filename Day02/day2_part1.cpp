#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>


bool isSafeReport(const std::vector<int>& levels) {
	if (levels.size() < 2) return true; // ��������ı�����Ϊ��ȫ

	bool increasing = true;
	bool decreasing = true;

	for (size_t i = 1; i < levels.size(); ++i) {
		int diff = levels[i] - levels[i - 1];
		if (std::abs(diff) < 1 || std::abs(diff) > 3) {
			return false; // ���ڼ����ֵ����1��3֮��
		}
		if (diff > 0) decreasing = false;
		if (diff < 0) increasing = false;
	}

	return increasing || decreasing; // ����ȫ����ȫ��
}

int main() {
	std::ifstream inputFile("input_day2.txt");
	if (!inputFile) {
		std::cerr << "�޷����ļ���" << std::endl;
		return 1;
	}

	std::string line;
	int safeReportCount = 0;

	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);
		std::vector<int> levels;
		int level;
		while (iss >> level) {
			levels.push_back(level);
		}
		if (isSafeReport(levels)) {
			++safeReportCount;
		}
	}

	inputFile.close();
	std::cout << "��ȫ���������Ϊ: " << safeReportCount << std::endl;
	return 0;
}
