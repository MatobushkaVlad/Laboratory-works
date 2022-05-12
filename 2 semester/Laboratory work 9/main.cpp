#include <iostream>
#include <fstream>
#include "inc/bmp.hpp"

int main()
{
	int choose = 0;
	std::cout << "Choose filter to use: " << std::endl;
	std::cout << "1) User's filter " << std::endl;
	std::cout << "2) Blue filter " << std::endl;
	std::cout << "3) Green filter " << std::endl;
	std::cout << "4) Red filter" << std::endl;

	std::cin >> choose;

	if (choose == 1)
	{
		int blue = 0;
		int green = 0;
		int red = 0;

		image::BMP bmp;

		std::cout << "--------Enter color change value-------" << std::endl;

		std::cout << "Blue: "; std::cin >> blue;
		std::cout << "Green: "; std::cin >> green;
		std::cout << "Red: "; std::cin >> red;

		std::cout << "----------------------------------------" << std::endl;

		bmp.Read("in.bmp");

		bmp.Filter(blue, green, red);

		bmp.Write("out.bmp");
	}
	else if (choose == 2)
	{
		image::BMP bmp;

		bmp.Read("in.bmp");

		bmp.BlueFilter();

		bmp.Write("out.bmp");
	}
	else if (choose == 3)
	{
		image::BMP bmp;

		bmp.Read("in.bmp");

		bmp.GreenFilter();

		bmp.Write("out.bmp");
	}
	else
	{
		image::BMP bmp;

		bmp.Read("in.bmp");

		bmp.RedFilter();

		bmp.Write("out.bmp");
	}

	return 0;
}