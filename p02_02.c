//Marissa Victoria Silalahi - 12S25055

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n, i;
    int stok[100];
    char namaKategori[20];
    int targetSisa, totalStok = 0;

    printf("=== Sistem Manajemen Gudang IT Del ===\n");

    // 1. Input Jumlah Data
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &n);

    // 2. Input Deret Stok
    printf("Masukkan %d deret stok barang (pisahkan dengan spasi):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &stok[i]);
    }

    // 3. Input Kategori dalam bentuk Teks
    printf("\nKategori tersedia: Dasi, Gula, Rok, Minyak\n");
    printf("Masukkan Nama Kategori yang ingin dihitung: ");
    scanf("%s", namaKategori);

    // Normalisasi input ke huruf kecil semua supaya tidak error (misal: 'GULA' jadi 'gula')
    for(int j = 0; namaKategori[j]; j++){
        namaKategori[j] = tolower(namaKategori[j]);
    }

    // 4. Menentukan Target Sisa bagi (Modulo) berdasarkan Nama
    if (strcmp(namaKategori, "dasi") == 0) targetSisa = 0;
    else if (strcmp(namaKategori, "gula") == 0) targetSisa = 1;
    else if (strcmp(namaKategori, "rok") == 0) targetSisa = 2;
    else if (strcmp(namaKategori, "minyak") == 0) targetSisa = 3;
    else {
        printf("Kategori tidak dikenal!\n");
        return 0;
    }

    // 5. Proses Penjumlahan
    for (i = 0; i < n; i++) {
        if (i % 4 == targetSisa) {
            totalStok += stok[i];
        }
    }

    // 6. Output
    printf("\nTotal stok untuk kategori '%s' adalah: %d pcs\n", namaKategori, totalStok);

    return 0;
}