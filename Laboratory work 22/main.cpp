#include <iostream>
#include "inc/matrix.hpp"

using mt::math::Mat22i;
using mt::math::Vec21i;
using mt::math::Vec31i;
using mt::math::Mat23i;

int main()
{

	Mat22i A;
	std::cout << "Enter A" << std::endl;
	std::cin >> A;

	Vec21i B;
	std::cout << "Enter B" << std::endl;
	std::cin >> B;

	Vec21i C;

	std::cout << "----------------Test addition-------------------" << std::endl;
	{
		C = A + B;
		std::cout << C << std::endl;
	}
	std::cout << "------------------Test addition done!-------------------" << std::endl;


	std::cout << "----------------Test substraction-------------------" << std::endl;
	{
		C = A - B;
		std::cout << C << std::endl;
	}
	std::cout << "--------------------Test substraction done!-----------------------" << std::endl;


	std::cout << "----------------Test multiplication-------------------" << std::endl;
	{
		C = A * B;
		std::cout << C << std::endl;
	}
	std::cout << "--------------------Test multiplication done!-----------------------" << std::endl;


	std::cout << "----------------Test Determinant-------------------" << std::endl;
	{
		std::cout << C.Det() << std::endl;
	}
	std::cout << "--------------------Test Determinant done!-----------------------" << std::endl;


	std::cout << "----------------Test Reverse-------------------" << std::endl;
	{
		std::cout << C.Reverse() << std::endl;
	}
	std::cout << "--------------------Test Reverse done!-----------------------" << std::endl;


	std::cout << "----------------Test Transposition-------------------" << std::endl;
	{
		std::cout << C.Transp() << std::endl;
	}
	std::cout << "--------------------Test Transpositionn done!-----------------------" << std::endl;


	return 0;
}
