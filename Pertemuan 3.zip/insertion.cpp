// Program Insertion Sort
#include <iostream> 
using namespace std;
int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n]; // deklarasi array untuk menyimpan elemen data
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) { // loop untuk membaca elemen-elemen data
        cin >> data[i]; // loop untuk membaca elemen-elemen data
    }

    // Insertion Sort dari terkecil hingga terbesar
    for (int i = 1; i < n; i++) { // mulai dari elemen kedua
        int key = data[i]; // elemen yang akan disisipkan
        int j = i - 1; // indeks elemen sebelumnya
        
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j]; // geser elemen ke kanan
            j--; // pindah ke elemen sebelumnya
        }
        data[j + 1] = key; // sisipkan elemen pada posisi yang benar
    }

    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) { // loop untuk mencetak elemen-elemen data yang sudah diurutkan
        cout << data[i] << " "; // cetak elemen-elemen data yang sudah diurutkan
    }
    
    cout << endl;
    return 0;
}