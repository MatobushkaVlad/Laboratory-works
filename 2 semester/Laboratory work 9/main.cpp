#include <iostream>
#include <fstream>
#include "inc/bmp.hpp"

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

struct Pixel
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
};


int main()
{
	//READING FILE
	std::ifstream in("in.bmp", std::ios::binary); //open file for binary reading (открытие файла для бинарного чтения)

	BMPHEADER bmpheader;
	//Read 14 bytes byte by byte and fill BMPHEADER srtucture (Считать 14 байтов побайтово и заполнить структуру BMPHEADER)
	//reinterpret_cast<char*>(&bmpheader) (представляет/интерпритирует структуру в виде элемента char размером 14 байт)
	in.read(reinterpret_cast<char*>(&bmpheader), sizeof(BMPHEADER));

	BMPINFO bmpinfo;
	in.read(reinterpret_cast<char*>(&bmpinfo), sizeof(BMPINFO));

	Pixel* *pixels = new Pixel* [bmpinfo.Height];
	for (int i = 0; i < bmpinfo.Height; i++)
		pixels[i] = new Pixel [bmpinfo.Width];
	for (int i = 0; i < bmpinfo.Height; i++)
	{
		for (int j = 0; j < bmpinfo.Width; j++)
			in.read(reinterpret_cast<char*>(&pixels[i][j]), sizeof(Pixel));
		if ((3 * bmpinfo.Width) % 4 != 0)
		{
			for (int j = 0; j < 4 - (3 * bmpinfo.Width) % 4; j++)
			{
				char c;
				in.read(&c, 1);
			}
		}
	}

	//Change color
	for (int i = 0; i < bmpinfo.Height; i++)
	{
		for (int j = 0; j < bmpinfo.Width; j++)
			pixels[i][j].b += 100;
	}

	//WRITING FILE
	std::ofstream out("out.bmp", std::ios::binary);

	BMPHEADER bmpheader_new;
	bmpheader_new.Type = bmpheader.Type;
	bmpheader_new.Size = 14 + 40 + 3 * (bmpinfo.Height * bmpinfo.Width);
	if (bmpinfo.Width % 4 != 0)
		bmpheader_new.Size += (4 - (3 * bmpinfo.Width) % 4) * bmpinfo.Height;
	bmpheader_new.OffBits = bmpheader.OffBits;
	bmpheader_new.Reversed1 = bmpheader.Reversed1;
	bmpheader_new.Reversed2 = bmpheader.Reversed2;

	out.write(reinterpret_cast<char*>(&bmpheader_new), sizeof(BMPHEADER));

	BMPINFO bmpinfo_new;
	bmpinfo_new.Size = bmpinfo.Size;
	bmpinfo_new.Width = bmpinfo.Width;
	bmpinfo_new.Height = bmpinfo.Height;
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
			out.write(reinterpret_cast<char*>(&pixels[i][j]), sizeof(Pixel));
		if ((3 * bmpinfo_new.Width) % 4 != 0)
		{
			for (int j = 0; j < 4 - (3 * bmpinfo_new.Width) % 4; j++)
			{
				char c;
				out.write(&c, 1);
			}
		}
	}


	for (int i = 0; i < bmpinfo.Height; i++)
		delete[] pixels[i];
	delete[] pixels;



	return 0;
}