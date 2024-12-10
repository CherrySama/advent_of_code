#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
	// �������ļ�
	std::ifstream inputFile("input_day3.txt");
	if (!inputFile) {
		std::cerr << "�޷����ļ���" << std::endl;
		return 1;
	}

	// ��ȡ�ļ����ݵ��ַ���
	std::string memory_data((std::istreambuf_iterator<char>(inputFile)),
							 std::istreambuf_iterator<char>());
	inputFile.close();

	// ����ƥ����Ч mul ָ���������ʽ
	std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
	std::smatch matches;
	std::string::const_iterator search_start(memory_data.cbegin());
	int total_sum = 0;

	// ��������ƥ����
	while (std::regex_search(search_start, memory_data.cend(), matches, pattern)) {
		int x = std::stoi(matches[1].str());
		int y = std::stoi(matches[2].str());
		total_sum += x * y;
		search_start = matches.suffix().first;
	}

	// ������
	std::cout << "�ܺ�: " << total_sum << std::endl;

	return 0;
}
