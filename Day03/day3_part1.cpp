#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
	// 打开输入文件
	std::ifstream inputFile("input_day3.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件！" << std::endl;
		return 1;
	}

	// 读取文件内容到字符串
	std::string memory_data((std::istreambuf_iterator<char>(inputFile)),
							 std::istreambuf_iterator<char>());
	inputFile.close();

	// 定义匹配有效 mul 指令的正则表达式
	std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
	std::smatch matches;
	std::string::const_iterator search_start(memory_data.cbegin());
	int total_sum = 0;

	// 查找所有匹配项
	while (std::regex_search(search_start, memory_data.cend(), matches, pattern)) {
		int x = std::stoi(matches[1].str());
		int y = std::stoi(matches[2].str());
		total_sum += x * y;
		search_start = matches.suffix().first;
	}

	// 输出结果
	std::cout << "总和: " << total_sum << std::endl;

	return 0;
}
