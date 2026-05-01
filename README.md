# Sistem Penelusuran Jaringan - BFS dengan Queue

Program C++ untuk menelusuri jaringan komputer menggunakan algoritma **BFS (Breadth First Search)** dan struktur data **Queue (FIFO)**.

> Program berbasis teks (CLI), tidak memiliki tampilan grafis.

---

## Topologi Jaringan

[Server]
/
[Router-A] [Router-B]
/ \
[PC-1] [PC-2]---[Laptop]


---

## Fitur

| Menu | Fungsi |
|------|--------|
| 1 | Telusuri dari Server |
| 2 | Telusuri dari Router-B |
| 3 | Tampilkan tabel koneksi |
| 4 | Keluar |

---

## Cara Menjalankan

```bash
g++ bfs_jaringan.cpp -o bfs_jaringan
./bfs_jaringan

---

## Struktur File
---
text
├── bfs_jaringan.cpp           # Kode sumber
├── README.md                  # Dokumentasi
└── studi_kasus_bfs_queue.docx # Studi kasus
