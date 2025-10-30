#include <iostream>
using namespace std;


void swap(int &a, int &b){ // fungsi untuk menukar dua elemen
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high){ // fungsi untuk membagi array menjadi dua bagian
    int pivot = arr[low]; // pilih elemen pertama sebagai pivot
    int i = low;
    int j = high;

    while(true){ // loop tak hingga
        while(i <= high && arr [i] <= pivot) // cari elemen yang lebih besar dari pivot
        i++;

        while(j >= low && arr[j] > pivot) // cari elemen yang lebih kecil dari pivot
        j--; 

        if(i > j){ 
            break; // jika i melewati j, keluar dari loop
        }
        swap(arr[i], arr[j]); // tukar elemen yang ditemukan
    }
    swap(arr[low], arr[j]); // tukar pivot dengan elemen pada posisi
    return j;
}


void quickSort(int arr[], int low, int high){ // fungsi utama untuk mengurutkan array menggunakan Quick Sort
    if(low < high){
        int pivotIndex = partition(arr, low, high); // cari indeks pivot setelah partisi

        //panggil fungsi quickSort secara rekursif
        quickSort(arr, low, pivotIndex - 1); // panggil fungsi quickSort secara rekursif
        quickSort(arr, pivotIndex + 1, high); // panggil fungsi quickSort secara rekursif
    }
}


int main() {
    int n;
    cout << "Masukkan jumlah elemen data: "; 
    cin >> n;

    int data[n]; // deklarasi array untuk menyimpan elemen data
    cout << "Masukkan elemen-elemen data: \n"; // loop untuk membaca elemen-elemen data
    for (int i = 0; i < n; i++) { // loop untuk membaca elemen-elemen data
        cin >> data[i]; // baca elemen-elemen data
    }

    quickSort(data, 0, n - 1); // panggil fungsi quickSort untuk mengurutkan array

    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) { // loop untuk mencetak elemen-elemen data yang sudah diurutkan
        cout << data[i] << " "; // cetak elemen-elemen data yang sudah diurutkan
    }
    cout << endl;

    return 0;
}