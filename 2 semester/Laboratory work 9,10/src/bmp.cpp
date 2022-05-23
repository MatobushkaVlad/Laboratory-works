#include "bmp.hpp"
#include <iostream>

using mt::math::Vec21d;
using mt::math::Mat22d;

namespace image
{
	BMP::BMP()
	{
		m_width = 0;
		m_height = 0;

	}

	void BMP::Read(const std::string& filename)
	{
		std::ifstream in(filename, std::ios::binary);

		BMPHEADER bmpheader;

		//Read 14 bytes byte by byte and fill BMPHEADER srtucture (—читать 14 байтов побайтово и заполнить структуру BMPHEADER)
		//reinterpret_cast<char*>(&bmpheader) (представл€ет/интерпритирует структуру в виде элемента char размером 14 байт)
		in.read(reinterpret_cast<char*>(&bmpheader), sizeof(BMPHEADER));

		BMPINFO bmpinfo;

		in.read(reinterpret_cast<char*>(&bmpinfo), sizeof(BMPINFO));

		m_height = bmpinfo.Height;
		m_width = bmpinfo.Width;

		//massive for pixels
		m_pixels = new Pixel * [m_height];
		for (int i = 0; i < m_height; i++)
			m_pixels[i] = new Pixel[m_width];

		//massive for coordinates
		m_coordinates = new Vec21d * [m_height];
		for (int i = 0; i < m_height; i++)
			m_coordinates[i] = new Vec21d[m_width];
		for(int i = 0 ; i < m_height; i++)
			for (int j = 0; j < m_width; j++)
			{
				m_coordinates[i][j].set(0, 0, j);
				m_coordinates[i][j].set(1, 0, i);
			}

		for (int i = 0; i < m_height; i++)
		{
			for (int j = 0; j < m_width; j++)
				in.read(reinterpret_cast<char*>(&m_pixels[i][j]), sizeof(Pixel));
			if ((3 * m_width) % 4 != 0)
			{
				for (int j = 0; j < 4 - (3 * m_width) % 4; j++)
				{
					char c;
					in.read(&c, 1);
				}
			}
		}
	}

	void BMP::Write(const std::string& filename)
	{
		std::ofstream out(filename, std::ios::binary);

		BMPHEADER bmpheader_new;

		bmpheader_new.Type = 0x4D42;
		bmpheader_new.Size = 14 + 40 + 3 * (m_height * m_width);
		if (m_width % 4 != 0)
			bmpheader_new.Size += (4 - (3 * m_width) % 4) * m_height;
		bmpheader_new.OffBits = 54;
		bmpheader_new.Reversed1 = 0;
		bmpheader_new.Reversed2 = 0;

		out.write(reinterpret_cast<char*>(&bmpheader_new), sizeof(BMPHEADER));

		BMPINFO bmpinfo_new;
		bmpinfo_new.BitCount = 24;
		bmpinfo_new.ClrImportant = 0;
		bmpinfo_new.ClrUsed = 0;
		bmpinfo_new.Compression = 0;
		bmpinfo_new.Height = m_height;
		bmpinfo_new.Planes = 1;
		bmpinfo_new.Size = 40;
		bmpinfo_new.SizeImage = bmpheader_new.Size - 54;
		bmpinfo_new.Width = m_width;
		bmpinfo_new.XPelsPerMeter = 0;
		bmpinfo_new.YPelsPerMeter = 0;

		out.write(reinterpret_cast<char*>(&bmpinfo_new), sizeof(BMPINFO));

		for (int i = 0; i < m_height; i++)
		{
			for (int j = 0; j < m_width; j++)
				out.write(reinterpret_cast<char*>(&m_pixels[i][j]), sizeof(Pixel));
			if ((3 * bmpinfo_new.Width) % 4 != 0)
			{
				for (int j = 0; j < 4 - (3 * m_width) % 4; j++)
				{
					char c;
					out.write(&c, 1);
				}
			}
		}
	}

	void BMP::Filter()
	{
		int blue = 0;
		int green = 0;
		int red = 0;

		std::cout << "--------Enter color change value-------" << std::endl;

		std::cout << "Blue: "; std::cin >> blue;
		std::cout << "Green: "; std::cin >> green;
		std::cout << "Red: "; std::cin >> red;

		std::cout << "----------------------------------------" << std::endl;

		for (int i = 0; i < m_height; i++)
		{
			for (int j = 0; j < m_width; j++)
			{
				if ((m_pixels[i][j].b + blue < 256) && (m_pixels[i][j].b + blue > 0)
					&& (m_pixels[i][j].g + green < 256) && (m_pixels[i][j].g + green > 0)
					&& (m_pixels[i][j].r + red < 256) && (m_pixels[i][j].r + red > 0))
				{
					m_pixels[i][j].b += blue;
					m_pixels[i][j].g += green;
					m_pixels[i][j].r += red;
				}
			}
		}
	}

	void BMP::BlueFilter()
	{
		for (int i = 0; i < m_height; i++)
		{
			for (int j = 0; j < m_width; j++)
			{
				m_pixels[i][j].b = 255;
			}
		}
	}

	void BMP::GreenFilter()
	{
		for (int i = 0; i < m_height; i++)
		{
			for (int j = 0; j < m_width; j++)
			{
				m_pixels[i][j].g = 255;
			}
		}
	}

	void BMP::RedFilter()
	{
		for (int i = 0; i < m_height; i++)
		{
			for (int j = 0; j < m_width; j++)
			{
				m_pixels[i][j].r = 255;
			}
		}
	}

	void BMP::Rotate(double angle)
	{
		//1 —мещение центра координат

		Vec21d T;
		T.set(0, 0, m_height / 2);
		T.set(1, 0, m_width / 2);

		//¬ычитание из координат смещени€
		for (int i = 0; i < m_height; i++)
			for (int j = 0; j < m_width; j++)
				m_coordinates[i][j] = m_coordinates[i][j] - T;

		//2 ѕоворот

		Mat22d R;
		R.set(0, 0, cos(angle)); R.set(0, 1, sin(angle));
		R.set(1, 0, -sin(angle)); R.set(1, 1, cos(angle));

		//New coor-s after rotate
		for (int i = 0; i < m_height; i++)
			for (int j = 0; j < m_width; j++)
				m_coordinates[i][j] = R * m_coordinates[i][j];

		//3 ѕеренос цветов в новый массив пикселей

		//Ќаходим минимальные и максимальные координаты нового изображени€
		int Xmax = INT_MIN;
		int Xmin = INT_MAX;
		int Ymax = INT_MIN;
		int Ymin = INT_MAX;

		for (int i = 0; i < m_height; i++)
			for (int j = 0; j < m_width; j++)
			{
				if (Xmax < m_coordinates[i][j].get(0, 0))
					Xmax = m_coordinates[i][j].get(0, 0);
				if (Xmin > m_coordinates[i][j].get(0, 0))
					Xmax = m_coordinates[i][j].get(0, 0);
				if (Ymax < m_coordinates[i][j].get(1, 0))
					Ymax = m_coordinates[i][j].get(1, 0);
				if (Ymin > m_coordinates[i][j].get(1, 0))
					Ymin = m_coordinates[i][j].get(1, 0);
			}

		//прибавл€ем +1 в избежание ошибок из-за округлени€, что позволит не выйти за пределы массива
		Xmax++;
		Xmin++;
		Ymax++;
		Ymin++;

		//ѕереход к новой " анонической" сис-ме коор-т
		int height = (Xmax - Xmin);
		int width = (Ymax - Ymin);

		Vec21d Shift;
		Shift.set(0, 0, width / 2);
		Shift.set(1, 0, height / 2);

		for (int i = 0; i < m_height; i++)
			for (int j = 0; j < m_width; j++)
				m_coordinates[i][j] = m_coordinates[i][j] + Shift;

		//—оздание нового массива пикселей дл€ нового(повернутого) изображени€
		Pixel** new_pixels = new Pixel * [height];
		for (int i = 0; i < height; i++)
			new_pixels[i] = new Pixel[width];

		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				new_pixels[i][j] = { 255,255,255 };

		//
		Vec21d** new_coordinates = new Vec21d * [height];
		for (int i = 0; i < height; i++)
			new_coordinates[i] = new Vec21d[width];

		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++) 
			{
				new_coordinates[i][j].set(0, 0, j);
				new_coordinates[i][j].set(0, 0, i);
			}


		// опирование цвета из старого массива в новый
		for(int i = 0; i < m_height;i++)
			for (int j = 0; j < m_width; j++)
			{
				int x = m_coordinates[i][j].get(0, 0);
				int y = m_coordinates[i][j].get(1,0);
				new_pixels[y][x] = m_pixels[i][j];
			}

		//”даление старого массива пикселей
		for (int i = 0; i < m_height; i++)
			delete[] m_pixels[i];
		delete[] m_pixels;


		for (int i = 0; i < m_height; i++)
			delete[] m_coordinates[i];
		delete[] m_coordinates;

		//ƒелаем новые значени€ основными дл€ изображени€
		m_pixels = new_pixels;
		m_coordinates = new_coordinates;

		m_height = height;
		m_width = width;

	}

	BMP::~BMP()
	{
		for (int i = 0; i < m_height; i++)
			delete[] m_pixels[i];
		delete[] m_pixels;

		for (int i = 0; i < m_height; i++)
			delete[] m_coordinates[i];
		delete[] m_coordinates;
	}
}