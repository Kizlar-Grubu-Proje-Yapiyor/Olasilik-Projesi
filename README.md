# MAT0293 Olasılık ve İstatistik Projesi

## Hızlı Erişim

1. [Proje Grubu](#proje-grubu)
1. [Kurulum](#kurulum)
1. [Kullanım](#kullanım)
1. [Kullanılabilir Formüller](#kullanılabilir-formüller)
1. [Lisans](#lisans)

---

## Proje Grubu

* [Ali Cüneyt Çağlar](https://github.com/CuneytCaglar)
* [Ali Furkan Demir](https://github.com/AliFurkanDemir)
* [Ceyhun Şen](https://github.com/ceyhunsen)
* [Halil Karataş](https://github.com/hll-krts)
* [İbrahim Yahya Aydınlı](https://github.com/ibrahimyahyaaydinli)


## Kurulum

Programın Linux üzerinde çalışması tavsiye edilir.

### Debian Tabanlı Linux Dağıtımları (Ubuntu, Debian, Pop!_OS, Linux Mint...)

```bash
sudo apt-get install -y gcc make whiptail git
git clone https://github.com/Kizlar-Grubu-Proje-Yapiyor/Olasilik-Projesi.git
cd Olasilik-Projesi
make build
```

### Red Hat Tabanlı Linux Dağıtımları (Fedora, Cent OS, RHEL...)

```bash
sudo dnf install -y gcc make newt
git clone https://github.com/Kizlar-Grubu-Proje-Yapiyor/Olasilik-Projesi.git
cd Olasilik-Projesi
make build
```

### Windows

**UYARI!**  
Windows'da stabil bir çalışma zamanı garanti değildir!  
`gcc` derleyicisinin kullanılması zorunludur!  
Repo'yu indirdiğiniz dizinde bir `cmd` açıp aşağıdaki komutu giriniz:

```cmd
gcc src/* -I include -lm -o olasilik
```

### Mac OS X

Sisteminizde `make`, `gcc`, ve `git` yüklü ise:

```bash
git clone https://github.com/Kizlar-Grubu-Proje-Yapiyor/Olasilik-Projesi.git
cd Olasilik-Projesi
make build
```

Eğer `make` ve `git` yüklü değil fakat `gcc` yüklü ise repoyu indirdiğiniz konumda:

```bash
gcc src/* -I include -lm -o olasilik
```

komutlarını çalıştırarak kurulumu gerçekleştirebilirsiniz. **Fakat bu yazılım Mac OS X'de test edilmemiştir!** 

## Kullanım

Genel kullanım:

```bash
./olasilik --[SECENEK] [DEGER(LER)]
```

Bütün seçenekleri görmek veya yardım almak için:

```bash
./olasilik --yardim
```

Aritmetik ortalama için örnek kullanım:

```bash
# Sayılar argüman olarak verilmek istenirse:
./olasilik --aritmetik-ortalama 12 13 800 58624
# Çıktı olarak `14862.250000` yazar

# Sayılar dosyadan okunmak istenirse:
./olasilik --dosya girdi.txt --aritmetik-ortalama
# `girdi.txt` dosyasındaki sayıların aritmetik ortalamasını yazar
```

Diğer formüller için `--yardim` bayrağı ile bilgi alabilirsiniz.  

Ayrıca `whiptail` tabanlı önyüzü de kullanabilirsiniz:

```bash
./olasilik-gui
```


### Kullanılabilir Formüller

1. Aritmetik Ortalama


## Lisans

[GNU General Public License v3.0](LICENSE)  

**Lütfen kodu lisansa uygun kullanın!**
