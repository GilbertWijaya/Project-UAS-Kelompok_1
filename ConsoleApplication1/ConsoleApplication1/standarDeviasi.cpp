#include <vector>
#include <iostream>

using namespace std;

void main() {

	vector<int>data{ 92,65,74,80,80,70,78 };
	int panjang = data.size();
	
	double JumlahData = 0;

	//jumlah data
	for (int i = 0; i < panjang; i++)
	{

		JumlahData += data[i];

	}
	
	//jumlah data dikuadratkan
	double jDataKuadrat = 0;
	for (int i = 0; i < panjang; i++)
	{

		jDataKuadrat += pow(data[i], 2);

	}
	/*
	Xi = pow(jumlahData,2) / 7
	STDEV = (jDatakuarat - Xi ) / 6 
	sqrt(STDEV)
	*/

	double Xi = pow(JumlahData, 2) / panjang;
	//cout << Xi;

	double STDEV = (jDataKuadrat - Xi) / (panjang - 1);
	double akar = sqrt(STDEV);

	cout << akar;
	
}
