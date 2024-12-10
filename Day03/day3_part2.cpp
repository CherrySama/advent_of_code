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

	// ����ƥ�� mul(X,Y)��do() �� don't() ָ���������ʽ
	std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");
	std::sregex_iterator iter(memory_data.begin(), memory_data.end(), pattern);
	std::sregex_iterator end;

	int total_sum = 0;
	bool is_enabled = true; // ��ʼ״̬�£��˷���������

	// ��������ƥ����
	while (iter != end) {
		std::smatch match = *iter;
		std::string matched_str = match.str();

		if (matched_str == "do()") {
			is_enabled = true; // ���ó˷�����
		}
		else if (matched_str == "don't()") {
			is_enabled = false; // ���ó˷�����
		}
		else if (is_enabled && match[1].matched && match[2].matched) {
			// ���ڳ˷�����������ƥ�䵽 mul(X,Y) ʱ����
			int x = std::stoi(match[1].str());
			int y = std::stoi(match[2].str());
			total_sum += x * y;
		}

		++iter;
	}

	// ������
	std::cout << "�ܺ�: " << total_sum << std::endl;

	return 0;
}
