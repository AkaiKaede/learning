#include <iostream>

int main()
{
	int sum = 0, value = 0;
	while (std::cin >> value) //�����ļ��������˳�ѭ����������Ϊctrl+z��
	{
		sum += value;
	}
	std::cout << "the sum is " << sum << std::endl;
	return 0;
}