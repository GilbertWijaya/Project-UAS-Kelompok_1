#include <iostream>
using namespace std;

void tampil(int tampilMx[][3], int baris, int kolom) {


	for (int i = 0; i < baris; i++)
	{
		cout << "[";
		for (int j = 0; j < kolom; j++)
		{

			cout << " " << tampilMx[i][j] << " ";

		}
		cout << "]" << endl;
	}

}

int Determinan(int MatrixDet[][3]) {
	int det;
	det =
		(MatrixDet[0][0] * MatrixDet[1][1] * MatrixDet[2][2])
		+ (MatrixDet[0][1] * MatrixDet[1][2] * MatrixDet[2][0])
		+ (MatrixDet[0][2] * MatrixDet[1][0] * MatrixDet[2][1])
		- (MatrixDet[0][2] * MatrixDet[1][1] * MatrixDet[2][0])
		- (MatrixDet[0][0] * MatrixDet[1][2] * MatrixDet[2][1])
		- (MatrixDet[0][1] * MatrixDet[1][0] * MatrixDet[2][2]);
	return det;

}

void tampilKov(float tampilMx[][3], int baris, int kolom) {


	for (int i = 0; i < baris; i++)
	{
		cout << "[";
		for (int j = 0; j < kolom; j++)
		{

			cout << " " << tampilMx[i][j] << " ";

		}
		cout << "]" << endl;
	}

}

void tampilAdj(float kovalen[][3], float adjoin[][3], int baris, int kolom) {


	for (int i = 0; i < baris; i++)
	{
		cout << "[";
		for (int j = 0; j < kolom; j++)
		{

			adjoin[i][j] = kovalen[j][i];
			cout << adjoin[i][j] << " ";

		}
		cout << "]" << endl;
	}

}

void tampilInv(float det, int baris, int kolom, float adjoin[][3], float invers[3][3]) {

	for (int i = 0; i < baris; i++)
	{
		cout << "[";
		for (int j = 0; j < kolom; j++)
		{

			if (det != 0)
			{

				invers[i][j] = (1 / det) * adjoin[i][j];
				cout << invers[i][j] << " ";

			}

		}
		cout << "]" << endl;
	}

}


void main() {


	int Matrix[3][3];
	float det, kovalen[3][3], adjoin[3][3], invers[3][3];
	int baris = 3;
	int kolom = 3;

	for (int i = 0; i < baris; i++)
	{

		for (int j = 0; j < kolom; j++)
		{

			cout << "masukan nilai pada indeks [" << i << "][" << j << "]: ";
			cin >> Matrix[i][j];

		}

	}
	cout << "===================================" << endl;
	tampil(Matrix, baris, kolom);

	det = Determinan(Matrix);
	cout << "Determinannya adalah: " << det << '\n';
	
	//mencari kovalen
	cout << "kovalen matriks adalah : " << endl;
	kovalen[0][0] = (Matrix[1][1] * Matrix[2][2]) - (Matrix[1][2] * Matrix[2][1]);
	kovalen[0][1] = ((Matrix[1][0] * Matrix[2][2]) - (Matrix[1][2] * Matrix[2][0])) * -1;
	kovalen[0][2] = (Matrix[1][0] * Matrix[2][1]) - (Matrix[1][1] * Matrix[2][0]);
	kovalen[1][0] = ((Matrix[0][1] * Matrix[2][2]) - (Matrix[0][2] * Matrix[2][1])) * -1;
	kovalen[1][1] = (Matrix[0][0] * Matrix[2][2]) - (Matrix[0][2] * Matrix[2][0]);
	kovalen[1][2] = ((Matrix[0][0] * Matrix[2][1]) - (Matrix[0][1] * Matrix[2][0])) * -1;
	kovalen[2][0] = (Matrix[0][1] * Matrix[1][2]) - (Matrix[0][2] * Matrix[1][1]);
	kovalen[2][1] = ((Matrix[0][0] * Matrix[1][2]) - (Matrix[0][2] * Matrix[1][0])) * -1;
	kovalen[2][2] = (Matrix[0][0] * Matrix[1][1]) - (Matrix[1][0] * Matrix[0][1]);
	tampilKov(kovalen, baris, kolom);

	cout << "===================================" << endl;
	cout << "adjoin matriks adalah : " << endl;
	tampilAdj(kovalen, adjoin, baris, kolom);
	cout << "===================================" << endl;
	cout << "invers matriks adalah : " << endl;
	tampilInv(det, baris, kolom, adjoin, invers);
	cout << "===================================" << endl;


}