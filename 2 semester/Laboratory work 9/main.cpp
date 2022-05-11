#include <iostream>
#include <fstream>

#pragma pack(1) //disable compiler memory aligment (���������� ������������ ������ ������������)
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
	std::ifstream in("in.bmp", std::ios::binary); //open file for binary reading (�������� ����� ��� ��������� ������)

	BMPHEADER bmpheader;
	//Read 14 bytes byte by byte and fill BMPHEADER srtucture (������� 14 ������ ��������� � ��������� ��������� BMPHEADER)
	//reinterpret_cast<char*>(&bmpheader) (������������/�������������� ��������� � ���� �������� char �������� 14 ����)
	in.read(reinterpret_cast<char*>(&bmpheader), sizeof(BMPHEADER));

	BMPINFO bmpinfo;
	in.read(reinterpret_cast<char*>(&bmpinfo), sizeof(BMPINFO));

	Pixel **pixels = new Pixel *[bmpinfo.Height];
	for (int i = 0; i < bmpinfo.Height; i++)
		pixels[i] = new Pixel[bmpinfo.Width];









	for (int i = 0; i < bmpinfo.Height; i++)
		delete[] pixels[i];
	delete[] pixels;



	return 0;
}