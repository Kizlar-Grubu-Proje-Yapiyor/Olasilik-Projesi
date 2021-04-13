# MAT0293 Olasılık ve İstatistik Projesi

## Proje Grubu

* [Ali Cüneyt Çağlar](https://github.com/CuneytCaglar)
* [Ali Furkan Demir](https://github.com/AliFurkanDemir)
* [Ceyhun Şen](https://github.com/ceyhunsen)
* [Halil Karataş](https://github.com/hll-krts)
* [İbrahim Yahya Aydınlı](https://github.com/ibrahimyahyaaydinli)


## Kurulum

Programın Linux üzerinde çalışması tavsiye edilir!

### Debian Tabanlı Dağıtımlar (Ubuntu, Debian, Pop!_OS, Linux Mint...)

```bash
sudo apt-get install -y gcc make whiptail git
git clone https://github.com/Kizlar-Grubu-Proje-Yapiyor/Olasilik-Projesi.git
cd Olasilik-Projesi
make build
```

### Red Hat Tabanlı Dağıtımlar (Fedora, Cent OS, RHEL...)

```bash
sudo dnf install -y gcc make newt
git clone https://github.com/Kizlar-Grubu-Proje-Yapiyor/Olasilik-Projesi.git
cd Olasilik-Projesi
make build
```

### Windows

**UYARI!**  
Windows'da stabil bir çalışma zamanı garanti değildir!  
`gcc` derleyicisinin yüklü olması gerekmektedir!  
Repo'yu kopyaladıktan sonra o dizinde bir `cmd` açıp aşağıdaki komutu giriniz:

```cmd
gcc src/* -I include -o olasilik
```


## Kullanım

Genel kullanım:

```bash
./olasilik --[SECENEK] [DEGER(LER)]
```

Bütün seçenekleri görmek veya yardım almak için:

```bash
./olasilik --yardim
```

Aritmetik ortalama örnek kullanım:

```bash
# Sayılar argüman olarak verilmek istenirse:
./olasilik --aritmetik-ortalama 12 13 800 58624
# Çıktı olarak `14862.250000` yazar

# Sayılar dosyadan okunmak istenirse:
./olasilik --dosya girdi.txt --aritmetik-ortalama
# `girdi.txt` dosyasındaki sayıların aritmetik ortalamasını yazar
```

Diğer formüller için `--yardım` bayrağı için bilgi alabilirsiniz.  

Ayrıca `whiptail` tabanlı önyüzü de kullanabilirsiniz:

```bash
./olasilik-gui
```


### Kullanılabilir Formüller

1. Aritmetik Ortalama


## Lisans

[GNU General Public License v3.0](LICENSE)  

**Lütfen kodu lisansa uygun kullanın!**
