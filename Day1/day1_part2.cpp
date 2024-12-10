#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

// answer: 23384288

int main() {
	// �������ļ�
	std::ifstream inputFile("input_day1.txt");
	if (!inputFile) {
		std::cerr << "�޷����ļ���" << std::endl;
		return 1;
	}

	std::vector<int> set1, set2;
	int left, right;

	// ��ȡ�ļ����ݵ������б�
	while (inputFile >> left >> right) {
		set1.push_back(left);
		set2.push_back(right);
	}

	inputFile.close(); // �ر��ļ�

	// ���� simlist �ֵ�
	std::unordered_map<int, long long> simlist;
	for (const auto& elem : set2) {
		if (std::find(set1.begin(), set1.end(), elem) != set1.end()) {
			simlist[elem] += elem;
		}
	}

	// ���� gap
	long long gap = 0;
	for (const auto& elem : set1) {
		if (simlist.find(elem) != simlist.end()) {
			gap += simlist[elem];
		}
	}

	// ������
	std::cout << "gap ��ֵΪ: " << gap << std::endl;

	return 0;
}
