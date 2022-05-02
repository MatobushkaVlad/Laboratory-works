#include <iostream>
#include "inc/matrix.hpp"

using mt::math::Vec2i;
using mt::math::Vec3i;
using mt::math::Mat23i;

int main()
{
	Mat23i A;
	std::cin >> A;

	Vec3i B;
	std::cin >> B;

	Vec2i C;

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


	std::cout << "----------------Test substraction-------------------" << std::endl;
	{
		C = A * B;
		std::cout << C << std::endl;
	}
	std::cout << "--------------------Test substraction done!-----------------------" << std::endl;


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
