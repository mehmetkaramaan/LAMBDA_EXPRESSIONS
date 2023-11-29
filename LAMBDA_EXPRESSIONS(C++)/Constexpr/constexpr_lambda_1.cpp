#include <array>
#include <iostream>

int main()
{
	auto fsquare = [](auto val) { return val * val; };
	std::array<int, fsquare(5)> a1;  //1

	std::cout << a1.size() << "\n";

	auto f1 = [](int x) {  //2
		static int cnt = 0;
		++cnt;
		return x * cnt;
		};
	//std::array<int, f1(10)> a2; //gecersiz
	std::cout << f1(20) << "\n";

	auto f2 = [](int x)constexpr { //3 f2 nesnesinin tanimi gecersiz
		static int cnt = 0;
		++cnt;
		return x * cnt;
		};

}

//1 fsquare(5) ifadesi C++17 ile birlikte art�k varsay�lan �ekilde constexpr. 
//Dolay�s�yla fonksiyona sabit ifadeleri ile yap�lan �a�r�dan elde edilen geri d�n�� de�eri sabit ifadesi gereken yerlerde kullan�labilir.

//2 f1 tan�m�mda static yerel de�i�ken kullan�ld��� i�in art�k bu lambda constexpr kabul edilmiyor.

//3 f2 nesnesinin ise tan�m� ge�ersiz.e�er constexpr anahtar s�zc��� kullan�lmasayd� tan�m ge�erli olacakt�.