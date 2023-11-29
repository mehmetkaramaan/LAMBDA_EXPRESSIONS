#include <string>

int main()
{
	std::string str{ "hasan" };

	str.assign("mehmet");

	auto f = [str]() {str.assign("karaman)"}; //gecersiz
}