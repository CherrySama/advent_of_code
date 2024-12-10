#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib> 

int main() {
	// ���ļ�
	std::ifstream inputFile("input_day1.txt");
	if (!inputFile) {
		std::cerr << "�޷����ļ�!" << std::endl;
		return 1;
	}

	std::vector<int> leftList, rightList;
	int left, right;

	// ���ļ���ȡ����
	while (inputFile >> left >> right) {
		leftList.push_back(left);
		rightList.push_back(right);
	}

	inputFile.close(); // �ر��ļ�

	// �������б�����
	std::sort(leftList.begin(), leftList.end());
	std::sort(rightList.begin(), rightList.end());

	// ������Ծ�����ܺ�
	long long totalDistance = 0;
	for (size_t i = 0; i < leftList.size(); ++i) {
		totalDistance += std::abs(leftList[i] - rightList[i]);
	}

	// ������
	std::cout << "��Ծ����ܺ�Ϊ: " << totalDistance << std::endl;

	return 0;
}
