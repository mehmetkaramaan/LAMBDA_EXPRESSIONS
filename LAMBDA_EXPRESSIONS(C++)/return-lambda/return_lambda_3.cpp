#include <string>
#include <iostream>

struct Memo
{
	auto func()
	{
		return [str = str] { std::cout << str << '\0'; };
	}

	std::string str;
};

int main()
{
	auto f1 = Memo{ "mehmet" }.func();
	auto f2 = Memo{ "karaman" }.func();

	f1();
	f2();
}