#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    int yil;
    int ay;
    int gun;
    int saat;
    int dakika;
    int saniye;
} TarihSaat;

typedef union {
    long int saniye_farki;
} ZamanFarki;

time_t tarihSaatToEpoch(TarihSaat ts) {
    struct tm t;
    t.tm_year = ts.yil - 1900;
    t.tm_mon = ts.ay - 1;
    t.tm_mday = ts.gun;
    t.tm_hour = ts.saat;
    t.tm_min = ts.dakika;
    t.tm_sec = ts.saniye;
    t.tm_isdst = -1;
    return mktime(&t);
}

int main() {
    TarihSaat baslangic, bitis;
    ZamanFarki fark;
    int uzatmaSaniyesi;

    // Kullanici girisleri
    printf("Mac baslangic tarih ve saatini giriniz (Yil Ay Gun Saat Dakika Saniye): ");
    scanf("%d %d %d %d %d %d", &baslangic.yil, &baslangic.ay, &baslangic.gun, &baslangic.saat, &baslangic.dakika, &baslangic.saniye);

    printf("Mac bitis tarih ve saatini giriniz (Yil Ay Gun Saat Dakika Saniye): ");
    scanf("%d %d %d %d %d %d", &bitis.yil, &bitis.ay, &bitis.gun, &bitis.saat, &bitis.dakika, &bitis.saniye);

    printf("Uzatma suresini saniye cinsinden giriniz: ");
    scanf("%d", &uzatmaSaniyesi);

    // Tarihleri epoch zamanina donustur
    time_t epochBaslangic = tarihSaatToEpoch(baslangic);
    time_t epochBitis = tarihSaatToEpoch(bitis);

    // Zaman farkini hesapla
    fark.saniye_farki = labs(epochBitis - epochBaslangic);

    // Toplam sureyi hesapla (normal sure + uzatma)
    long int toplamSaniye = fark.saniye_farki + uzatmaSaniyesi;

    printf("\nToplam mac suresi: %ld saniye\n", toplamSaniye);

    return 0;
}

