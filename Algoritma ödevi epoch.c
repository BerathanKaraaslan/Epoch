#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Tarih ve saat bilgisini tutan yapi
typedef struct {
    int yil;
    int ay;
    int gun;
    int saat;
    int dakika;
    int saniye;
} TarihSaat;

// Zaman farkini saniye cinsinden göstermek icin union
typedef union {
    long int saniye_farki;
    double dakika_farki;
} ZamanFarki;

time_t tarihSaatToEpoch(TarihSaat ts) {
    struct tm t;
    t.tm_year = ts.yil - 1900;  // struct tm'de yil, 1900 yilindan baslar
    t.tm_mon = ts.ay - 1;       // struct tm'de ay, 0 ile baslar (Ocak = 0)
    t.tm_mday = ts.gun;
    t.tm_hour = ts.saat;
    t.tm_min = ts.dakika;
    t.tm_sec = ts.saniye;
    t.tm_isdst = -1;            // Yaz saati uygulamasini otomatik belirle

    return mktime(&t);
}

int main() {
    TarihSaat t1, t2;
    ZamanFarki fark;

    // Kullanicidan ilk tarihi al
    printf("Birinci tarih ve saati giriniz (Yil Ay Gun Saat Dakika Saniye): ");
    scanf("%d %d %d %d %d %d", &t1.yil, &t1.ay, &t1.gun, &t1.saat, &t1.dakika, &t1.saniye);

    // Kullanicidan ikinci tarihi al
    printf("Ikinci tarih ve saati giriniz (Yil Ay Gun Saat Dakika Saniye): ");
    scanf("%d %d %d %d %d %d", &t2.yil, &t2.ay, &t2.gun, &t2.saat, &t2.dakika, &t2.saniye);

    // Tarihleri epoch zamanina dönüþtür
    time_t epoch1 = tarihSaatToEpoch(t1);
    time_t epoch2 = tarihSaatToEpoch(t2);

    // Zaman farkini hesapla
    fark.saniye_farki = labs(epoch2 - epoch1);

    // Sonuclari ekrana yazdir
    printf("\nEpoch zaman degerleri:\n");
    printf("Birinci tarih: %ld saniye\n", epoch1);
    printf("Ikinci tarih: %ld saniye\n", epoch2);
    printf("Iki tarih arasindaki fark: %ld saniye\n", fark.saniye_farki);

    // Zaman farkýný dakika cinsinden de göster
    fark.dakika_farki = fark.saniye_farki / 60.0;
    printf("Iki tarih arasindaki fark: %.2f dakika\n", fark.dakika_farki);

    return 0;
}
