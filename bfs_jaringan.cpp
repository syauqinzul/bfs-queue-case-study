#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Jumlah simpul dalam graf
const int MAXNODE = 6;

// Nama kota/simpul
string namaKota[MAXNODE] = {"A", "B", "C", "D", "E", "F"};

// Matriks adjacency graf (0 = tidak terhubung, 1 = terhubung)
int graf[MAXNODE][MAXNODE] = {
    // A  B  C  D  E  F
    {  0, 1, 1, 0, 0, 0 }, // A
    {  1, 0, 0, 1, 1, 0 }, // B
    {  1, 0, 0, 0, 0, 1 }, // C
    {  0, 1, 0, 0, 0, 0 }, // D
    {  0, 1, 0, 0, 0, 1 }, // E
    {  0, 0, 1, 0, 1, 0 }  // F
};

void BFS(int mulai) {  // Fungsi BFS menerima parameter indeks simpul awal
    bool dikunjungi[MAXNODE] = {false};
    queue<int> antrian;

    // Tandai simpul awal dan masukkan ke antrian
    dikunjungi[mulai] = true;
    antrian.push(mulai);

    cout << "Urutan BFS dari simpul " << namaKota[mulai] << ":" << endl; // Tampilkan info simpul awal penelusuran

    while (!antrian.empty()) {   // Ulangi selama Queue masih ada isinya
        int simpul = antrian.front();  // Ambil simpul paling depan Queue (FIFO)
        antrian.pop();                 // Hapus simpul terdepan dari Queue

        cout << namaKota[simpul] << " ";   // Cetak nama kota yang sedang dikunjungi

        // Kunjungi semua tetangga yang belum dikunjungi
        for (int i = 0; i < MAXNODE; i++) {
            if (graf[simpul][i] == 1 && !dikunjungi[i]) {
                dikunjungi[i] = true;
                antrian.push(i);
            }
        }
    }
    cout << endl;  // Pindah baris setelah semua simpul dicetak
}

// FUNGSI MAIN
int main() {
    int pilihan;  // Variabel untuk menyimpan pilihan menu dari pengguna

    do {
        // Tampilkan menu utama program
        cout << "\n=== PROGRAM BFS MENGGUNAKAN QUEUE ===" << endl;
        cout << "Graf Kota yang tersedia: A, B, C, D, E, F" << endl;
        cout << "1. Jalankan BFS dari simpul A" << endl;
        cout << "2. Jalankan BFS dari simpul C" << endl;
        cout << "3. Tampilkan matriks adjacency" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;  // Baca input pilihan dari pengguna

        switch (pilihan) {  // Percabangan berdasarkan nilai pilihan
            case 1:
                BFS(0); // Mulai dari A (indeks 0)
                break;
            case 2:
                BFS(2); // Mulai dari C (indeks 2)
                break;
            case 3:
                cout << "\nMatriks Adjacency:" << endl;
                cout << "   A B C D E F" << endl;
                for (int i = 0; i < MAXNODE; i++) {
                    cout << namaKota[i] << ": ";
                    for (int j = 0; j < MAXNODE; j++) {
                        cout << graf[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
        }
    } while (pilihan != 4);

    return 0; // Program selesai dengan status sukses
}