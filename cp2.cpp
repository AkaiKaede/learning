#include <iostream>

int main()
{
	int sum = 0, value = 0;
	while (std::cin >> value) //遇到文件结束符退出循环（键盘上为ctrl+z）
	{
		sum += value;
	}
	std::cout << "the sum is " << sum << std::endl;
	return 0;
}