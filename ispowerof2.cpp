/*快速判断一个数是否为2的整数次幂 */
#include <iostream>
using namespace std;

bool ispowerof2(int num)
{
	return (num & (num - 1)) == 0;
}

int main()
{
	int num;
	cin >> num;
	cout << ispowerof2(num) << endl;
	return 0;
}


