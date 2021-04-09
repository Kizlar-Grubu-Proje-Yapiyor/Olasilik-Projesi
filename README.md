# MAT0293 Olasılık ve İstatistik Projesi

## Proje Grubu

* [Ali Cüneyt Çağlar](https://github.com/CuneytCaglar)
* [Ali Furkan Demir](https://github.com/AliFurkanDemir)
* [Ceyhun Şen](https://github.com/ceyhunsen)
* [Halil Karataş](https://github.com/hll-krts)
* [İbrahim Yahya Aydınlı](https://github.com/ibrahimyahyaaydinli)


## Derleme

Gereksinimler:

* gcc (zorunlu)
* make (isteğe bağlı)
* whiptail (önyüz için zorunlu)
* bash (önyüz için zorunlu)

```bash
git clone https://github.com/Kizlar-Grubu-Proje-Yapiyor/Olasilik-Projesi.git
cd Olasilik-Projesi
make build
```

Make olmadan derlemek için (önerilmez, desteklenmiyor):

```bash
gcc main.c yardim.c aritmetikortalama.c -I include -o olasilik
```

**Windows'ta çalışabilir fakat desteklenmemektedir!**


## Kullanım

Genel kullanım:

```bash
./olasilik --[SECENEK] [DEGER]
```

Bütün seçenekleri görmek veya yardım almak için:

```bash
./olasilik --yardim
```

Ayrıca `whiptail` tabanlı önyüzü de kullanabilirsiniz

```bash
./olasilik-gui
``` 

## Lisans

[GNU General Public License v3.0](LICENSE)  

**Lütfen kodu lisansa uygun kullanın!**
