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

	// 定义匹配 mul(X,Y)、do() 和 don't() 指令的正则表达式
	std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");
	std::sregex_iterator iter(memory_data.begin(), memory_data.end(), pattern);
	std::sregex_iterator end;

	int total_sum = 0;
	bool is_enabled = true; // 初始状态下，乘法操作启用

	// 遍历所有匹配项
	while (iter != end) {
		std::smatch match = *iter;
		std::string matched_str = match.str();

		if (matched_str == "do()") {
			is_enabled = true; // 启用乘法操作
		}
		else if (matched_str == "don't()") {
			is_enabled = false; // 禁用乘法操作
		}
		else if (is_enabled && match[1].matched && match[2].matched) {
			// 仅在乘法操作启用且匹配到 mul(X,Y) 时处理
			int x = std::stoi(match[1].str());
			int y = std::stoi(match[2].str());
			total_sum += x * y;
		}

		++iter;
	}

	// 输出结果
	std::cout << "总和: " << total_sum << std::endl;

	return 0;
}
