#include <iostream>
#include "matrix.hpp"

using mt::math::Vec21d;
using mt::math::Vec31d;
using mt::math::Vec13d;
using mt::math::Vec12d;

using mt::math::Mat22d;
using mt::math::Mat33d;

using mt::math::Mat23d;
using mt::math::Mat34d;
using mt::math::Mat45d;
using mt::math::Mat56d;
using mt::math::Mat67d;
using mt::math::Mat78d;
using mt::math::Mat89d;
using mt::math::Mat910d;
using mt::math::Mat1011d;

int main()
{
	Mat34d B({ {
		{1,3,4,60},
		{5,9,10,98},
		{20,12,30,54}
} });

	Mat23d A({ {
		{1,3,4},
		{5,9,10}
	} });

	Mat56d C({ {
		{3,2,5,6,15,7},
		{8,92,5,6,3,70},
		{3,1,5,7,23,76},
		{67,8,9,4,3,22},
		{55,6,2,4,1,88}
} });

	//A.Gauss();

	//B.Gauss();

	C.Gauss();

	std::cout << C;

	return 0;
}