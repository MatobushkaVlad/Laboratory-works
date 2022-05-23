#pragma once
#include <iostream>
#include <fstream>
#include <mathutils/matrix.hpp>

using mt::math::Vec21d;
using mt::math::Mat22d;

namespace image
{
	class BMP
	{
	public:
		struct Pixel
		{
			unsigned char b;
			unsigned char g;
			unsigned char r;
		};

		BMP::BMP();

		//READING FILE
		void Read(const std::string& filename);

		//WRITING FILE
		void Write(const std::string& filename);

		void Filter();

		void BlueFilter();
		
		void GreenFilter();

		void RedFilter();

		void Rotate(double angle);

		~BMP();
		
	private:

		int m_height = 0;
		int m_width = 0;
		//двойной динамический массив из жлементов типа Pixel
		Pixel** m_pixels = nullptr;
		Vec21d** m_coordinates = nullptr;

#pragma pack(1) //disable compiler memory aligment (Отключение выравнивания памяти компилятором)
		struct BMPHEADER  //14 byte structure
		{
			unsigned short Type;
			unsigned int Size;
			unsigned short Reversed1;
			unsigned short Reversed2;
			unsigned int OffBits;
		};
#pragma pack()

#pragma pack(1)
		struct BMPINFO //40 byte structure
		{
			unsigned int    Size;
			int             Width;
			int             Height;
			unsigned short  Planes;
			unsigned short  BitCount;
			unsigned int    Compression;
			unsigned int    SizeImage;
			int             XPelsPerMeter;
			int             YPelsPerMeter;
			unsigned int    ClrUsed;
			unsigned int    ClrImportant;
		};
#pragma pack()

	};

}