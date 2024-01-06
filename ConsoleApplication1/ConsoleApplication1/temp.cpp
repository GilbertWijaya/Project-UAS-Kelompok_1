for (int i = 0; i < data; i++)
{
    cout << "Masukan Nama ke " << i + 1 << ": ";
    cin >> tempNama;
    cout << "Masukan Nilai " << tempNama << ": ";
    cin >> tempNilai;

    nama.push_back(tempNama);
    nilai.push_back(tempNilai);
}


//menampilkan hasil vector
int jumlahNilai{};
cout << "Nama\t\t|\t\tNilai\n";
for (int i = 0; i < nama.size(); i++)
{
    cout << nama[i] << "\t\t\t\t" << nilai[i] << '\n';
    jumlahNilai += nilai[i];

}

cout << '\n';

//mencari mean
cout << "nilai mean-nya adalah: \n\n";
mean = jumlahNilai / data;
cout << "hasil mean adalah: " << mean << '\n';

//median
//untuk data ganjil => Me = (n + 1) /2; v
//untuk data genap => Me =  Me= [(n ÷ 2) + (n ÷ 2) + 1] ÷ 2.
double median;

median = (data + 1) / 2;
cout << "nilai mediannya ada diindeks ke: " << median << '\n';
cout << "indeks ke: " << median << " = " << nilai[median] << '\n';

//standar deviasi

double jDataKuadrat = 0;
for (int i = 0; i < nilai.size(); i++)
{

    jDataKuadrat += pow(nilai[i], 2);

}
/*
Xi = pow(jumlahData,2) / 7
STDEV = (jDatakuarat - Xi ) / 6
sqrt(STDEV)
*/

double Xi = pow(jumlahNilai, 2) / data;
//cout << Xi;

double STDEV = (jDataKuadrat - Xi) / (data - 1);
double akar = sqrt(STDEV);

cout << akar;

8.62168