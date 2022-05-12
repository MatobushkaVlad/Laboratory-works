#pragma once
#include <iostream>
#include <fstream>

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

		BMP::BMP()
		{

		}

		//READING FILE
		void Read()
		{
			std::ifstream in("in.bmp", std::ios::binary);

			BMPHEADER bmpheader;

			//Read 14 bytes byte by byte and fill BMPHEADER srtucture (Считать 14 байтов побайтово и заполнить структуру BMPHEADER)
			//reinterpret_cast<char*>(&bmpheader) (представляет/интерпритирует структуру в виде элемента char размером 14 байт)
			in.read(reinterpret_cast<char*>(&bmpheader), sizeof(BMPHEADER));

			BMPINFO bmpinfo;

			in.read(reinterpret_cast<char*>(&bmpinfo), sizeof(BMPINFO));
			
			m_height = bmpinfo.Height;
			m_width = bmpinfo.Width;
			m_pixels = new Pixel * [m_height];

			for (int i = 0; i < m_height; i++)
				m_pixels[i] = new Pixel[m_width];
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

		//WRITING FILE
		void Write()
		{
			std::ofstream out("out.bmp", std::ios::binary);

			BMPHEADER bmpheader_new;


			//WRITING FILE
			std::ofstream out("out.bmp", std::ios::binary);

			BMPHEADER bmpheader_new;
			bmpheader_new.Type = bmpheader.Type;
			bmpheader_new.Size = 14 + 40 + 3 * (m_height * m_width);
			if (m_width % 4 != 0)
				bmpheader_new.Size += (4 - (3 * m_width) % 4) * m_height;
			bmpheader_new.OffBits = bmpheader.OffBits;
			bmpheader_new.Reversed1 = bmpheader.Reversed1;
			bmpheader_new.Reversed2 = bmpheader.Reversed2;

			out.write(reinterpret_cast<char*>(&bmpheader_new), sizeof(BMPHEADER));

			BMPINFO bmpinfo_new;
			bmpinfo_new.Size = bmpinfo.Size;
			bmpinfo_new.Width = m_width;
			bmpinfo_new.Height = m_height;
			bmpinfo_new.Planes = bmpinfo.Planes;
			bmpinfo_new.BitCount = bmpinfo.BitCount;
			bmpinfo_new.Compression = bmpinfo.Compression;
			bmpinfo_new.SizeImage = bmpinfo.SizeImage;
			bmpinfo_new.XPelsPerMeter = bmpinfo.XPelsPerMeter;
			bmpinfo_new.YPelsPerMeter = bmpinfo.YPelsPerMeter;
			bmpinfo_new.ClrUsed = bmpinfo.ClrUsed;
			bmpinfo_new.ClrImportant = bmpinfo.ClrImportant;

			out.write(reinterpret_cast<char*>(&bmpinfo_new), sizeof(BMPINFO));

			for (int i = 0; i < bmpinfo_new.Height; i++)
			{
				for (int j = 0; j < bmpinfo_new.Width; j++)
					out.write(reinterpret_cast<char*>(&m_pixels[i][j]), sizeof(Pixel));
				if ((3 * bmpinfo_new.Width) % 4 != 0)
				{
					for (int j = 0; j < 4 - (3 * bmpinfo_new.Width) % 4; j++)
					{
						char c;
						out.write(&c, 1);
					}
				}
			}
		}
		
		~BMP()
		{
			for (int i = 0; i < m_height; i++)
				delete[] m_pixels[i];
			delete[] m_pixels;
		}
	private:

		int m_height;
		int m_width;
		Pixel** m_pixels = nullptr;

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