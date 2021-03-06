#include <fstream>
#include "field.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	unsigned short MapSize;
	cin >> MapSize;
	unsigned short* field = new unsigned short[MapSize];
	fstream Map;
	Map.open("Map.dat", ios::out);
	Map << MapSize;
	Map << endl;
	for (unsigned short i=0; i<MapSize; i++)
	{
		field[i]=rand()%2+0;
		Map << field[i] << endl;
	}

	unsigned short ChanceStackSize;
	cin >> ChanceStackSize;
	Map << ChanceStackSize;
	Map << endl;
	unsigned short ChancePos=0;
	for (unsigned short i=0; i<(ChanceStackSize*2); i++)
	{
		unsigned short ChanceType=rand()%3+1;
		if (ChanceType==3)
			ChancePos=0;
		else
			ChancePos=rand()%(MapSize-1)+0;
		Map << ChanceType << endl;
		Map << ChancePos << endl;
	}

	Map.close();
	return 0;
}