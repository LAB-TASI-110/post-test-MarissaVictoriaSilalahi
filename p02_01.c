//Marissa Victoria Silalahi - 12S25055

#include <stdio.h>
#include <string.h>

int main() {
    char kota[10];
    int beratButet, beratUcok, totalBerat;
    long hargaPerKg, totalOngkos;
    float diskon = 0;

    // Judul Program
    printf("=== Sistem Input Del-Express ===\n");

    // Input Kota Tujuan (MDN, JKT, BLG, END)
    printf("Masukkan Kode Kota: ");
    scanf("%s", kota);

    // Input Berat Paket Butet
    printf("Masukkan Berat Paket Butet (kg): ");
    scanf("%d", &beratButet);

    // Aturan: Berat paket Ucok selalu lebih berat 2kg dari Butet (berdasarkan gambar timbangan)
    beratUcok = beratButet + 2;
    totalBerat = beratButet + beratUcok;

    // Logika Penentuan Harga per Kg berdasarkan Kota
    if (strcmp(kota, "MDN") == 0) {
        hargaPerKg = 15000;
    } else if (strcmp(kota, "JKT") == 0) {
        hargaPerKg = 25000;
    } else if (strcmp(kota, "BLG") == 0) {
        hargaPerKg = 5000;
    } else if (strcmp(kota, "END") == 0) {
        hargaPerKg = 50000;
    } else {
        printf("Kode kota tidak terdaftar!\n");
        return 0;
    }

    // Hitung Ongkos Dasar
    totalOngkos = totalBerat * hargaPerKg;

    // Logika Promo berdasarkan Total Berat
    char infoPromo[50] = "Tidak ada promo";
    if (totalBerat > 15) {
        diskon = 0.15 * totalOngkos;
        strcpy(infoPromo, "Promo Diskon 15% Terdeteksi!");
    } else if (totalBerat > 10) {
        diskon = 0.10 * totalOngkos;
        strcpy(infoPromo, "Promo Diskon 10% Terdeteksi!");
    }

    // Hitung Total Akhir
    long totalAkhir = totalOngkos - (long)diskon;

    // Output Struk Pembayaran
    printf("\n====================================\n");
    printf("          STRUK PEMBAYARAN          \n");
    printf("====================================\n");
    printf("Kota Tujuan          : %s\n", kota);
    printf("Berat Paket Butet    : %d kg\n", beratButet);
    printf("Berat Paket Ucok     : %d kg\n", beratUcok);
    printf("Total Berat          : %d kg\n", totalBerat);
    printf("Total Ongkos Kirim   : Rp %ld\n", totalAkhir);
    printf("Informasi Promo      : %s\n", infoPromo);
    printf("====================================\n");

    return 0;
}