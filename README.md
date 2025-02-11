# Zaman Farkı Hesaplayıcı (Epoch Zamanına Göre)

Bu C programı, kullanıcıdan iki farklı tarih ve saat bilgisi alarak bu tarihler arasındaki zaman farkını **epoch zamanına** (Unix zaman damgasına) göre hesaplar ve sonucu saniye ile dakika cinsinden gösterir. Programda `struct` ve `union` kullanımı örneklenmiştir.

## Epoch Zamanı Nedir?

**Epoch Zamanı** veya **Unix Zamanı**, 1 Ocak 1970 saat 00:00:00 UTC'den itibaren geçen toplam saniye sayısını ifade eder. Bu kavram, Unix ve Unix benzeri işletim sistemlerinde tarih ve saat hesaplamalarında yaygın olarak kullanılır.

## Program Özellikleri
- Kullanıcıdan iki tarih ve saat bilgisi alır.
- Tarih ve saat bilgilerini epoch zamanına dönüştürür.
- İki tarih arasındaki zaman farkını saniye ve dakika cinsinden hesaplar.
- `struct` ile tarih ve saat bilgileri, `union` ile zaman farkı farklı birimlerde saklanır.

## KULLANIM
1. Projeyi klonlayın veya kopyalayın.
2. Terminalde derleme ve çalıştırma için şu komutları kullanın:

   
   gcc zaman_farki.c -o zaman_farki
   ./zaman_farki
   
3.Program sizden iki tarih ve saat bilgisi girmenizi isteyecek. Örneğin:

Birinci tarih ve saati giriniz (Yıl Ay Gün Saat Dakika Saniye): 2025 2 11 12 0 0
İkinci tarih ve saati giriniz (Yıl Ay Gün Saat Dakika Saniye): 2025 2 12 12 0 0


Programın çıktısı şu şekilde olacaktır:

Epoch zaman değerleri:
Birinci tarih: 1731225600 saniye
İkinci tarih: 1731312000 saniye
İki tarih arasındaki fark: 86400 saniye
İki tarih arasındaki fark: 1440.00 dakika


KOD AÇIKLAMASI
TarihSaat isimli struct tipi, kullanıcıdan alınan yıl, ay, gün, saat, dakika ve saniye bilgilerini saklar.
ZamanFarki isimli union tipi, zaman farkını hem saniye hem de dakika olarak saklamak için aynı bellek alanını paylaşır.
tarihSaatToEpoch fonksiyonu, struct tm formatına dönüştürülen tarihi mktime fonksiyonuyla epoch zamanına çevirir.
Zaman farkı hesaplanır ve farklı formatlarda ekrana yazdırılır.



GELİŞTİRME
Bu projeye katkıda bulunmak isterseniz, aşağıdaki adımları takip edebilirsiniz:

1.Bu projeyi forklayın.
2.Yeni bir dal (branch) oluşturun: git checkout -b ozellik-adi
3.Değişikliklerinizi yapın ve commit edin: git commit -m 'Yeni özellik ekle'
4.Dalınıza push edin: git push origin ozellik-adi
5.Bir pull request oluşturun.

