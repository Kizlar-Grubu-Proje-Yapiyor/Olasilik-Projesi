# MAT0293 Olasılık ve İstatistik Projesi

## Hızlı Erişim

1. [Proje Açıklaması](#proje-açıklaması)
2. [Proje Grubu](#proje-grubu)
3. [Kullanılabilir Formüller](#kullanılabilir-formüller)
4. [Kurulum](#kurulum)
	1. [Linux](#linux)
	2. [Windows](#windows)
	3. [Mac OS X](#mac-os-x)
1. [Kullanım](#kullanım)
1. [Lisans](#lisans)

---


## Proje Açıklaması

Bu proje: komut satırı tabanlı, matematiksel formülleri hesaplayabilecek ve diğer olasılık ve istatistik projelerinize entegre edebileceğiniz harici bir programdır. Proje `C` dili ile yazılıp, [GNU getopt](https://www.gnu.org/software/libc/manual/html_node/Getopt.html) kütüphanesi kullanılmıştır.  
Bu proje MAT0293 Olasılık ve İstatistik dersi için hazırlanmıştır.


## Proje Grubu

* [Ali Cüneyt Çağlar](https://github.com/CuneytCaglar)
* [Ali Furkan Demir](https://github.com/AliFurkanDemir)
* [Ceyhun Şen](https://github.com/ceyhunsen)
* [Halil Karataş](https://github.com/hll-krts)
* [İbrahim Yahya Aydınlı](https://github.com/ibrahimyahyaaydinli)


### Kullanılabilir Formüller

1. Aritmetik Ortalama
2. Harmonik Ortalama
3. Geometrik Ortalama
4. Medyan
5. Mod
6. Ortalama Sapma
7. Standart Sapma
8. Varyans


## Kurulum

**Derleyici olarak `gcc` kullanılması zorunludur!**  
Eğer sisteminizde derleyici yok veya hazır çalıştırılabilir dosyayı istiyorsanız [relases](https://github.com/Kizlar-Grubu-Proje-Yapiyor/Olasilik-Projesi/releases) sayfasından sisteminize uygun dosyayı indirip kurabilirsiniz.

### Linux

### Debian Tabanlı Linux Dağıtımları (Ubuntu, Debian, Pop!_OS, Linux Mint...)

```bash
sudo apt-get install -y gcc make whiptail git
git clone https://github.com/Kizlar-Grubu-Proje-Yapiyor/Olasilik-Projesi.git
cd Olasilik-Projesi
make build
```

### Red Hat Tabanlı Linux Dağıtımları (Fedora Linux, Cent OS, RHEL...)

```bash
sudo dnf install -y gcc make newt git
git clone https://github.com/Kizlar-Grubu-Proje-Yapiyor/Olasilik-Projesi.git
cd Olasilik-Projesi
make build
```

### Windows

Repo'yu indirdiğiniz dizinde `cmd` veya `powershell` açıp aşağıdaki komutu giriniz:

```powershell
gcc src/* -I include -lm -O3 -o olasilik
```

### Mac OS X

Sisteminizde `make`, `gcc`, ve `git` yüklü ise:

```bash
git clone https://github.com/Kizlar-Grubu-Proje-Yapiyor/Olasilik-Projesi.git
cd Olasilik-Projesi
make build
```

Eğer `make` ve `git` yüklü değil fakat `gcc` yüklü ise repo'yu indirdiğiniz dizinde:

```bash
gcc src/* -I include -lm -O3 -o olasilik
```

Kodun Mac OS X'de test edilmesinde ve çalıştırılabilir dosyanın oluşturulmasında destek oldukları için Kağan Kağanoğlu ve Ekrem Bal'a teşekkür ederiz.


## Kullanım

Genel kullanım:

```bash
./olasilik --[SECENEK] [DEGER(LER)]
```

Aritmetik ortalama için örnek kullanım:

```bash
# Sayılar argüman olarak verilmek istenirse:
./olasilik --aritmetik-ortalama 12 13 800 58624
# Çıktı olarak `14862.250000` yazar

# Sayılar dosyadan okunmak istenirse:
./olasilik --dosya girdi.txt --aritmetik-ortalama
# `girdi.txt` dosyasındaki sayıların aritmetik ortalamasını yazar

# Sayılar stdin'den okunmak istenirse
./olasilik --interaktif --aritmetik-ortalama
# stdin'den okunan sayıların aritmetik ortalamasını yazar
```

Bütün seçenekleri görmek veya yardım almak için `--yardim` bayrağını kullanabilirsiniz:

```bash
./olasilik --yardim
```

Ayrıca sisteminizde `bash` ve `whiptail` yüklü ise önyüzü de kullanabilirsiniz:

```bash
./olasilik-gui
```

![whiptail](images/whiptail.png)

## Lisans

[GNU General Public License v3.0](LICENSE)  

**Lütfen kodu lisansa uygun kullanın!**
