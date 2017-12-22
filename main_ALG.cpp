#include <fstream>
#include <iostream>
#include "ThreadPool.h"
#include <vector>

using namespace std;

int main()
{
	srand(time(0));

	unsigned short points = 0;
	unsigned short n;
	
	fstream Map;
	Map.open("Map.dat", ios::in);
	if(!Map) return 1; // Если ошибка открытия файла, то завершаем программу
	Map >> n;
	unsigned short* field = new unsigned short[n];
	unsigned short CurPos;
	for (CurPos=0; CurPos<n; CurPos++)	// CurPos является индексом для экономии памяти, чтобы не выделять память для доп переменной 
	{
		Map >> field[CurPos];
		cout << field[CurPos];
	}
	stack<unsigned short> sChance;
	unsigned short ChanceStackSize;
	Map >> ChanceStackSize;
	for (auto i = 0; i<ChanceStackSize; i++)	
	{
		Map >> sChance.push();
		cout << field[CurPos];
	}
	cout << "\n\n";
	Map.close();
	//pool.runAsync(&)
	ThreadPool pool;
	//unsigned short d;
	//unsigned int* r = new unsigned int[];
	vector<unsigned int> r;
	r[0] = pool.runAsync<unsigned int>(&try,3,  0,0,field, sChance);
	r[1] = pool.runAsync<unsigned int>(&try,4,  0,0,field, sChance);
	r[2] = pool.runAsync<unsigned int>(&try,5,  0,0,field, sChance);
	r[3] = pool.runAsync<unsigned int>(&try,6,  0,0,field, sChance);
	r[4] = pool.runAsync<unsigned int>(&try,7,  0,0,field, sChance);
	r[5] = pool.runAsync<unsigned int>(&try,8,  0,0,field, sChance);
	r[6] = pool.runAsync<unsigned int>(&try,9,  0,0,field, sChance);
	r[7] = pool.runAsync<unsigned int>(&try,10, 0,0,field, sChance);
	r[8] = pool.runAsync<unsigned int>(&try,11, 0,0,field, sChance);

	unsigned int max = r[0];
	for (unsigned short i=1; i<9; i++)
	{
		if (max < r[i])
		{
			max = r[i];
		}
	}

	delete pool;
 	ThreadPool pool;

 	//unsigned int* r = new unsigned int[9];
 	vector<vector<unsigned int>> r1; // Проверить корректность объявления двумерного вектора
	/*for (unsigned short d2 = 0; d2<9; d2++)
		r[d2+9]=pool.runAsync<unsigned int>(&try1,2,   d2+3,0,	 field, sChance);
	for (unsigned short d2 = 0; d2<9; d2++)
		r[d2+18]=pool.runAsync<unsigned int>(&try1,4,  d2+3,r[1]%n, field, sChance);
	for (unsigned short d2 = 0; d2<9; d2++)
		r[d2+27]=pool.runAsync<unsigned int>(&try1,6,  d2+3,r[3]%n, field, sChance);
	for (unsigned short d2 = 0; d2<9; d2++)
		r[d2+27]=pool.runAsync<unsigned int>(&try1,8,  d2+3,r[5]%n, field, sChance);
	for (unsigned short d2 = 0; d2<9; d2++)
		r[d2+36]=pool.runAsync<unsigned int>(&try1,10, d2+3,r[7]%n,field, sChance);
 	for (unsigned short d2=0; d2<9; d++)
 		r[d2+45]=pool.runAsync<unsigned int>(&try1,12, d2+3,0,   field, sChance);
*/
 	for (unsigned short d1=2; d2<14; d2+=2)
 	{
 		for (unsigned short d2 = 0; d2<9; d2++)
 		{
 			if (d1 == 4 || d1 == 6 || d1 == 8 || d1 == 10)
			r1[d1][d2]=pool.runAsync<unsigned int>(&try1,d1, d2+3,0, field, r[d1-3]%n, sChance);
			else 
			r1[d1][d2]=pool.runAsync<unsigned int>(&try1,d1, d2+3,0, field, 0, sChance);
 	}

 	/*for (unsigned short i=9; i<55; i++)
 	{
 		if (max < r[i])
 		{
 			max=r[i];
 		}
	}*/


 	delete pool;
 	ThreadPool pool;
 	
 	vector<vector<unsigned int>> r2; // Проверить корректность объявления двумерного вектора

 	for (unsigned short d3 = 2; d3<13; d3++)
 	{
 		for (unsigned short d2 = 2; d2<14; d2+=2)
 		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2]=pool.runAsync<unsigned int>(&try2,2, d2,d3, 0, r1[2][d2]%n, field, sChance);
			else
				r2[d3][d2]=pool.runAsync<unsigned int>(&try2,2, d2,d3, 0, 0, field, sChance);
 		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2+12]=pool.runAsync<unsigned int>(&try2,4, d2,d3, 0, r1[4][d2]%n, field, sChance);
			else
				r2[d3][d2+12]=pool.runAsync<unsigned int>(&try2,4, d2,d3, 0, 0, field, sChance);
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2+24]=pool.runAsync<unsigned int>(&try2,6, d2,d3, 0, r1[6][d2]%n, field, sChance);
			else
				r2[d3][d2+24]=pool.runAsync<unsigned int>(&try2,6, d2,d3, 0, 0, field, sChance);
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2+36]=pool.runAsync<unsigned int>(&try2,8, d2,d3, 0, r1[8][d2]%n, field, sChance);
			else
				r2[d3][d2+36]=pool.runAsync<unsigned int>(&try2,8, d2,d3, 0, 0, field, sChance);
		}
		for (unsigned short d2 = 2; d2<14; d2+=2)
		{
			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2+48]=pool.runAsync<unsigned int>(&try2,10, d2,d3, 0, r1[10][d2]%n, field, sChance);
			else
				r2[d3][d2+48]=pool.runAsync<unsigned int>(&try2,10, d2,d3, 0, 0, field, sChance);
		}
 		for (unsigned short d2 = 2; d2<14; d2+=2)
 		{
 			if (d2 == 4 || d2 == 6 || d2 == 8 || d2 == 10)
				r2[d3][d2+60]=pool.runAsync<unsigned int>(&try2,12, d2,d3, 0, r1[12][d2]%n, field, sChance);
			else
				r2[d3][d2+60]=pool.runAsync<unsigned int>(&try2,12, d2,d3, 0, 0, field, sChance);
 		}
 	}



	
	
	//system("pause"); // for widows-family OSs
	getchar(); // выступает в роли аналога "system("pause");"
	return 0;
}