# MODUL‑KONTROL‑DIGITAL‑MOTOR‑DC

> Modul kendali digital untuk motor DC — terdiri dari pengukuran tegangan dan arus, kontrol motor via shield, serta antarmuka pengguna menggunakan LCD.

## 📋 Ringkasan

Proyek ini bertujuan menghasilkan **sistem kendali digital** untuk motor DC, dengan fitur‑utama:

* Shield motor untuk pengaturan kecepatan dan arah motor DC.
* Sensor tegangan & arus yang memberikan data real‑time.
* Antarmuka pengguna menggunakan LCD shield untuk memonitor kondisi sistem.
* Encoder untuk membaca posisi atau kecepatan motor.
* Semua komponen digabung dalam arsitektur modular (folder “Encoder”, “LCD_Shield”, “Motor_Shield”, “Volt Current Sensor”) untuk kemudahan integrasi dan pengembangan lebih lanjut.

## 🎯 Tujuan

Modul ini dikembangkan untuk:

* Memberikan solusi kendali motor DC secara digital yang terukur dan dapat di‑monitor.
* Memfasilitasi integrasi sensor dan aktuator dalam sistem otomasi atau robotika.
* Menjadi basis eksperimen atau proyek penelitian di bidang kontrol dan instrumentasi elektronika.

## 🧩 Struktur Proyek

```
/MODUL‑KONTROL‑DIGITAL‑MOTOR‑DC
│  
├─ Encoder/                ← kode dan dokumentasi untuk modul encoder  
├─ LCD_Shield/             ← kode dan file untuk shield tampilan LCD  
├─ Motor_Shield/           ← kode dan dokumentasi untuk pengendali motor DC  
└─ Volt Current Sensor/    ← sensor pengukuran tegangan & arus listrik  
```

## 🔧 Komponen Utama & Spesifikasi

* **Motor Shield**: digunakan untuk mengatur kecepatan dan arah motor DC (PWM, H‑bridge)
* **Sensor Tegangan & Arus**: menyediakan pembacaan real‑time untuk monitoring beban motor
* **Encoder**: memberikan feedback posisi atau kecepatan motor
* **LCD Shield**: antarmuka pengguna untuk menampilkan status modul secara langsung
* **Mikrokontroler**: (misalnya Arduino atau sejenisnya) sebagai otak kendali sistem
* Semua modul digesek secara digital agar kontrol akurat dan dapat dipantau secara real‑time.

## 🚀 Cara Memulai

1. Clone repositori:

   ```bash
   git clone https://github.com/WVamoss/MODUL-KONTROL-DIGITAL-MOTOR-DC.git
   ```
2. Buka folder yang sesuai dengan modul yang akan Anda gunakan (misalnya `Motor_Shield`).
3. Unggah kode ke mikrokontroler Anda sesuai petunjuk di masing‑masing folder.
4. Sambungkan perangkat keras: sensor, motor, shield, mikrokontroler, serta LCD.
5. Jalankan sistem dan pantau output melalui LCD atau serial monitor.

## 📐 Penggunaan & Integrasi

* Setelah langkah instalasi di atas selesai, Anda bisa mengubah parameter seperti kecepatan motor, arah, batas arus/tegangan dalam kode sesuai kebutuhan.
* Data pengukuran arus/tegangan bisa di‐log atau dikirim ke sistem eksternal untuk analisis lebih lanjut.
* Modul ini cocok diintegrasikan ke dalam sistem robotik, conveyor otomatis, atau aplikasi otomasi lainnya.

## ✅ Catatan Important

* Pastikan suplai daya sesuai, dan koneksi H‑bridge motor dilakukan dengan benar untuk menghindari kerusakan.
* Kalibrasi sensor arus & tegangan diperlukan agar pembacaan akurat.
* Perhatikan manajemen termal pada motor dan driver agar tidak overheat saat beban tinggi.
* Disarankan menggunakan ground bersama antara sensor, mikrokontroler dan driver motor demi kestabilan sinyal.
