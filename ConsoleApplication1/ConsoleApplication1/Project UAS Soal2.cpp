#include <iostream>
#include <vector>

using namespace std;

//mengeluarkan output
void display(vector<string>nama,vector<int>nilai,int panjang) {
    cout << "-----------------------------------------\n";
    cout << "|" << "Nama" << "\t\t|\t" << "   Nilai" << "\t|" <<  '\n';
    cout << "-----------------------------------------\n";
    for (int i = 0; i < panjang; i++)
    {
        if (i != (panjang-1))
        {
            cout << "|" << nama[i] << "\t\t|\t    " << nilai[i] << "\t\t|" <<'\n';
        }
        else
        {
            cout << "|" << nama[i] << "\t|\t    " << nilai[i] << "\t\t|" << '\n';
        }
    }
    cout << "-----------------------------------------\n";
}

//mencari mean
void mean(vector<int>nilai, int panjang) {

    int JumlahNilai = 0;
    double mean;

    for (int i = 0; i < panjang; i++)
    {

        JumlahNilai += nilai[i];

    }
    //menghitung mean
    mean = JumlahNilai / panjang;

    cout << "Mean dari data diatas adalah: " << mean << '\n';
}

//mencari median
double median(vector<int>nilai, int panjang) {

    double Carimedian;

    if (panjang % 2 != 0)
    {

        Carimedian = (panjang + 1) / 2;

    }
    else if(panjang % 2 == 0)
    {
     
        Carimedian = (float(panjang) / 2) + (((float(panjang / 2) + 1) / 2));

    }

    return nilai[Carimedian];
}

//mencari standar deviasi
void StandarDeviasi(vector<int>nilai, int panjang) {

    /*Xi = pow(JumlahNilai, 2) / 7
        STDEV = (jNilaikuadrat - Xi) / (panjang - 1)
        sqrt(STDEV)
    */

    //mencari total nilai data
    int JumlahNilai = 0;
    for (int i = 0; i < panjang; i++)
    {

        JumlahNilai += nilai[i];

    }

    //mencari total nilai data dengan setiap nilai pada indeks dikuadratkan
    int jNilaiKuadrat = 0;
    for (int i = 0; i < panjang; i++)
    {
        jNilaiKuadrat += pow(nilai[i],2);
    }

    double Xi = pow(JumlahNilai, 2) / panjang;
    double STDEV = (jNilaiKuadrat - Xi) / (panjang - 1);
    double HasilSTDEV = sqrt(STDEV);

    cout << "Hasil standar deviasi data diatas adalah: " << HasilSTDEV << "\n";
}

void main()
{
    vector<string>nama;
    vector<int>nilai;

    string tempNama;
    int tempNilai,PanjangData;

    //menginput data
    cout << "Masukan jumlah data: ";
    cin >> PanjangData;

    for (int i = 0; i < PanjangData; i++)
    {
        cout << "Masukan Nama ke " << i + 1 << ": ";
        cin >> tempNama;
        cout << "Masukan Nilai " << tempNama << ": ";
        cin >> tempNilai;

        nama.push_back(tempNama);
        nilai.push_back(tempNilai);
    }
    
    display(nama, nilai, PanjangData);
    mean(nilai, PanjangData);
    double medianData = median(nilai, PanjangData);
    cout << "Median dari data diatas adalah: " << medianData << '\n';
    StandarDeviasi(nilai, PanjangData);


}
