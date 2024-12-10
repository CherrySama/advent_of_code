#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

// �жϸ����ļ����б��Ƿ�ȫ
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

// �ж��Ƿ����ͨ���Ƴ�һ������ʹ���氲ȫ
bool canBeMadeSafeByRemovingOne(const std::vector<int>& levels) {
	if (isSafeReport(levels)) return true; // ���ԭ�����Ѱ�ȫ

	// ����levels�б��ÿ��Ԫ��
	for (size_t i = 0; i < levels.size(); ++i) {
		bool increasing = true;
		bool decreasing = true;

		for (size_t j = 1; j < levels.size(); ++j) {
			if (j == i) continue; // �������Ƴ���Ԫ��

			size_t prev = (j == i + 1) ? j - 2 : j - 1; // ��������Ԫ�غ��ǰһ������
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
		std::cerr << "�޷����ļ���" << std::endl;
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
	std::cout << "���������ı�������Ϊ: " << count << std::endl;
	return 0;
}
