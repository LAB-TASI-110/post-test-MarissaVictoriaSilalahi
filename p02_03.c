//Marissa Victoria Silalahi - 12S25055

#include <stdio.h>
#include <string.h>

struct Pesanan {
    char namaMenu[30];
    int jumlah;
    long subTotal;
};

int main() {
    char namaPelanggan[50];
    int jumlahJenis;
    long totalBayar = 0;

    printf("=== Sistem Kafetaria IT Del ===\n");
    printf("Nama Pelanggan: ");
    // Menggunakan fgets lebih aman daripada gets
    fgets(namaPelanggan, sizeof(namaPelanggan), stdin);
    namaPelanggan[strcspn(namaPelanggan, "\n")] = 0; // Menghapus enter di akhir teks

    printf("Berapa jenis menu yang dipesan? ");
    scanf("%d", &jumlahJenis);
    getchar(); // Membersihkan sisa enter setelah scanf

    struct Pesanan listPesanan[jumlahJenis];

    for (int i = 0; i < jumlahJenis; i++) {
        printf("\nData Pesanan ke-%d\n", i + 1);
        printf("Nama Menu  : ");
        fgets(listPesanan[i].namaMenu, sizeof(listPesanan[i].namaMenu), stdin);
        listPesanan[i].namaMenu[strcspn(listPesanan[i].namaMenu, "\n")] = 0;
        
        printf("Harga Satuan: ");
        long hargaSatuan;
        scanf("%ld", &hargaSatuan);
        
        printf("Jumlah Beli : ");
        scanf("%d", &listPesanan[i].jumlah);
        getchar(); // Membersihkan sisa enter untuk loop berikutnya

        listPesanan[i].subTotal = hargaSatuan * listPesanan[i].jumlah;
        totalBayar += listPesanan[i].subTotal;
    }

    // Cetak Struk (sama seperti sebelumnya)
    printf("\n========================================\n");
    printf("          STRUK KAFETARIA IT DEL        \n");
    printf("========================================\n");
    printf("Pelanggan: %s\n", namaPelanggan);
    printf("----------------------------------------\n");
    printf("%-15s %-5s %-15s\n", "Menu", "Qty", "Subtotal");
    for (int i = 0; i < jumlahJenis; i++) {
        printf("%-15s %-5d Rp %-15ld\n", listPesanan[i].namaMenu, listPesanan[i].jumlah, listPesanan[i].subTotal);
    }
    printf("----------------------------------------\n");
    printf("TOTAL BAYAR: Rp %ld\n", totalBayar);
    printf("========================================\n");

    return 0;
}