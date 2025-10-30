#include <iostream>  
#include <vector>   
using namespace std; 

void merge(vector<int>& arr, int left, int mid, int right) { // fungsi untuk menggabungkan dua subarray yang sudah diurutkan
    int n1 = mid - left + 1; // ukuran subarray kiri
    int n2 = right - mid; // ukuran subarray kanan     

    vector<int> L(n1), R(n2); // buat array sementara untuk menyimpan elemen subarray

    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i];     
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; 


    int i = 0; // indeks awal subarray kiri    
    int j = 0; // indeks awal subarray kiri dan kanan
    int k = left; // indeks awal subarray gabungan


    while (i < n1 && j < n2) { // gabungkan elemen dari kedua subarray
        if (L[i] <= R[j]) {  // bandingkan elemen dari L dan R
            arr[k] = L[i]; // salin elemen dari L ke arr   
            i++;           
        } else {               
            arr[k] = R[j]; // salin elemen dari R ke arr    
            j++; // pindah ke elemen berikutnya di R               
        }
        k++; // pindah ke posisi berikutnya di arr                 
    }

    while (i < n1) {   
        arr[k] = L[i]; // salin elemen yang tersisa dari subarray kiri, jika ada
        i++;           
        k++;          
    }

    while (j < n2) {   // salin elemen yang tersisa dari subarray kanan, jika ada
        arr[k] = R[j]; // untuk elemen yang tersisa di R
        j++; // pindah ke elemen berikutnya di R           
        k++; //          
    }
}

void mergeSort(vector<int>& arr, int left, int right) {      
   
    if (left >= right) // basis rekursif: jika array hanya memiliki satu elemen atau kosong    
        return; // tidak perlu diurutkan       
    int mid = left + (right - left) / 2; // cari titik tengah array

    mergeSort(arr, left, mid); // panggil fungsi mergeSort secara rekursif untuk subarray kiri        
    mergeSort(arr, mid + 1, right); // panggil fungsi mergeSort secara rekursif untuk subarray kanan    
   
    merge(arr, left, mid, right); // gabungkan dua subarray yang sudah diurutkan    
}


void printArray(const vector<int>& arr) { // fungsi untuk mencetak elemen-elemen array  
    for (int i = 0; i < arr.size(); i++) {  // loop untuk mencetak elemen-elemen array
        cout << arr[i] << " "; // cetak elemen ke-i dari array             
    }
    cout << endl; // pindah ke baris baru setelah mencetak semua elemen array                           
}

int main() {            
    int n;              
    cout << "Masukkan jumlah elemen data: ";       
    cin >> n; // baca jumlah elemen data                                     
    
    vector<int> data(n);                            
    cout << "Masukkan elemen-elemen data: ";       
    for (int i = 0; i < n; i++) {                   
        cin >> data[i]; // baca elemen-elemen data                            
    }
   
    cout << "Array sebelum diurutkan: ";            
    printArray(data); // cetak array sebelum diurutkan                             
    mergeSort(data, 0, n - 1); // panggil fungsi mergeSort untuk mengurutkan array                     
    cout << "Array setelah diurutkan: ";             
    printArray(data); // cetak array setelah diurutkan                              
   
    return 0;                                       

}