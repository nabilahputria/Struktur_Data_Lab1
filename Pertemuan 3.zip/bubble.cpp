#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n]; // deklarasi array untuk menyimpan elemen data
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) { // loop untuk membaca elemen-elemen data
        cin >> data[i];
    }

    // Algoritma Bubble Sort dari terkecil hingga terbesar
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (data[j] > data[j+1]) {
                // Tukar data[j] dan data[j+1]
                int temp = data[j]; // simpan nilai data[j] sementara
                data[j] = data[j+1]; // pindahkan nilai data[j+1] ke data[j]
                data[j+1] = temp; // pindahkan nilai sementara ke data[j+1]
            }
        }
    }


    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) { // loop untuk mencetak elemen-elemen data yang sudah diurutkan
        cout << data[i] << " "; // cetak elemen-elemen data yang sudah diurutkan
    }
    cout << endl; 

    return 0;
}