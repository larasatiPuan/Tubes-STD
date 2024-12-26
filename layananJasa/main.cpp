#include <iostream>
#include "layananJasa.h"
#include "utils.h"

using namespace std;

// Start Menu

void loginMenu()
{
  cout << endl;
  cout << "====================SELAMAT DATANG DI FIX & FLICK====================" << endl;
  cout << "Main Menu:" << endl;
  cout << "1. Login Admin" << endl;
  cout << "2. Login Pengguna" << endl;
  cout << "3. Register Pengguna" << endl;
  cout << "q. Exit" << endl;
  cout << "=====================================================================" << endl;
  cout << "Pilih opsi: ";
}

void adminMenu()
{
  cout << endl;
  cout << "=====================================================================" << endl;
  cout << "Menu Admin:" << endl;
  cout << "1. Tambah Layanan Baru" << endl;
  cout << "2. Tambah Pekerja Baru" << endl;
  cout << "3. Hapus Pekerja" << endl;
  cout << "4. Edit Data Pekerja" << endl;
  cout << "q. Back" << endl;
  cout << "=====================================================================" << endl;
  cout << "Pilih opsi: ";
}

void userMenu()
{
  cout << endl;
  cout << "=====================================================================" << endl;
  cout << "Menu Pengguna:" << endl;
  cout << "1. Pesan Layanan" << endl;
  cout << "2. Lihat Semua Layanan" << endl;
  cout << "3. Lihat Semua Pekerja" << endl;
  cout << "4. Lihat Semua Pekerja dari Layanan" << endl;
  cout << "5. Lihat Semua Layanan dari Pekerja" << endl;
  cout << "6. Lihat Jumlah Pekerja tanpa Layanan" << endl;
  cout << "q. Back" << endl;
  cout << "=====================================================================" << endl;
  cout << "Pilih opsi: ";
}

// End Menu

// Start Admin Menu Section

void addLayanan(ListLayanan &LLayanan)
{
  InfotypeLayanan layanan;

  cout << endl;
  cout << "Tambah Layanan" << endl;

  cout << "Masukkan Jenis: ";
  cin >> layanan.jenis;

  AdrLayanan PLayananFound = findElmLayanan(LLayanan, layanan.jenis);

  if (PLayananFound != nullptr)
  {
    cout << "Layanan dengan jenis tersebut sudah ada !" << endl;
    return;
  }

  cout << "Masukkan Jam: ";
  cin >> layanan.jam;

  cout << "Masukkan Harga: ";
  cin >> layanan.harga;

  cout << "Masukkan Diskon: ";
  cin >> layanan.diskonLayanan;

  layanan.jumlahPekerja = 0;

  AdrLayanan PLayanan;
  createElmLayanan(PLayanan, layanan);
  insertElmLayanan(LLayanan, PLayanan);
  cout << endl;

  showAllListLayanan(LLayanan);

  cout << "Layanan berhasil ditambahkan" << endl;
}

void addPekerja(ListLayanan &LLayanan, ListPekerja &LPekerja)
{
  InfotypePekerja pekerja;

  cout << endl;
  cout << "Tambah Pekerja" << endl;

  cout << "Masukkan Nama: ";
  cin >> pekerja.nama;

  AdrPekerja PPekerjaFound = findElmPekerja(LPekerja, pekerja.nama);

  if (PPekerjaFound != nullptr)
  {
    cout << "Pekerja dengan nama tersebut sudah ada !" << endl;
    return;
  }

  cout << "Masukkan Gender: ";
  cin >> pekerja.gender;

  cout << "Masukkan Rating: ";
  cin >> pekerja.rating;

  pekerja.jumlahLayanan = 0;

  AdrPekerja PPekerja;
  createElmPekerja(PPekerja, pekerja);
  insertElmPekerja(LPekerja, PPekerja);

  cout << endl;
  cout << "Pekerja berhasil ditambahkan" << endl;

  string choice;
  do
  {
    cout << endl;
    showAllListLayanan(LLayanan);
    cout << "Masukkan jenis layanan yang ingin dikerjakan (0 untuk selesai): ";
    cin >> choice;

    if (choice != "0")
    {

      AdrLayanan PLayananFound = findElmLayanan(LLayanan, choice);

      if (PLayananFound == nullptr)
      {
        cout << "Layanan dengan jenis tersebut tidak ditemukan !" << endl;
      }
      else if (findRelationByNamaPekerja(PLayananFound, pekerja.nama) != nullptr)
      {
        cout << "Pekerja sudah termasuk ke layanan tersebut !" << endl;
      }
      else
      {
        AdrRelation PRelation;
        createElmRelation(PRelation, PPekerja);
        insertElmRelation(PLayananFound, PRelation);

        cout << "Pekerja berhasil ditambahkan ke Layanan" << endl;
      }
    }
  } while (choice != "0");
}

void deletePekerja(ListLayanan &LLayanan, ListPekerja &LPekerja)
{
  string namaPekerja;

  cout << endl;
  cout << "Hapus Pekerja" << endl;

  cout << "Masukkan Nama: ";
  cin >> namaPekerja;

  AdrPekerja PPekerjaFound = findElmPekerja(LPekerja, namaPekerja);

  if (PPekerjaFound == nullptr)
  {
    cout << "Pekerja dengan nama tersebut tidak ditemukan !" << endl;
    return;
  }

  deleteElmPekerja(LLayanan, LPekerja, namaPekerja, PPekerjaFound);

  cout << "Pekerja berhasil dihapus" << endl;
}

void editPekerja(ListLayanan &LLayanan, ListPekerja &LPekerja)
{
  string namaPekerja;

  cout << endl;
  cout << "Edit Pekerja" << endl;

  cout << "Masukkan Nama: ";
  cin >> namaPekerja;

  AdrPekerja PPekerja = findElmPekerja(LPekerja, namaPekerja);

  if (PPekerja == nullptr)
  {
    cout << "Pekerja dengan nama tersebut tidak ditemukan !" << endl;
    return;
  }

  cout << "Data Awal Pekerja" << endl;
  cout << "Nama: " << PPekerja->info.nama << endl;
  cout << "Gender: " << PPekerja->info.gender << endl;
  cout << "Jumlah Layanan: " << PPekerja->info.jumlahLayanan << endl;
  cout << "Rating: " << PPekerja->info.rating << endl;
  cout << endl;

  InfotypePekerja pekerja;

  cout << "Masukkan Nama (0 jika tidak berubah): ";
  cin >> pekerja.nama;

  if (pekerja.nama == "0")
  {
    pekerja.nama = namaPekerja;
  }

  if (pekerja.nama != namaPekerja)
  {
    AdrPekerja PPekerjaFound = findElmPekerja(LPekerja, pekerja.nama);

    if (PPekerjaFound != nullptr)
    {
      cout << "Pekerja dengan nama tersebut sudah ada !" << endl;
      return;
    }
  }

  cout << "Masukkan Gender (0 jika tidak berubah): ";
  cin >> pekerja.gender;

  if (pekerja.gender == "0")
  {
    pekerja.gender = PPekerja->info.gender;
  }

  cout << "Masukkan Rating (0 jika tidak berubah): ";
  cin >> pekerja.rating;

  if (pekerja.rating == 0)
  {
    pekerja.rating = PPekerja->info.rating;
  }

  pekerja.jumlahLayanan = PPekerja->info.jumlahLayanan;

  editElmPekerja(PPekerja, pekerja);

  cout << "Data Pekerja berhasil diubah" << endl;

  showAllRelationByNamaPekerja(LLayanan, LPekerja, pekerja.nama);

  string confirm;

  do
  {
    cout << "Apakah ingin mengubah layanan pekerja ?" << endl;
    cout << "(y/n): ";
    cin >> confirm;
    if (confirm != "y" && confirm != "n")
    {
      cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
    }
  } while (confirm != "y" && confirm != "n");

  if (confirm == "y")
  {
    deleteAllElemRelationByNamaPekerja(LLayanan, LPekerja, pekerja.nama);
    cout << "Layanan pekerja berhasil dihapus" << endl;
    string choice;
    do
    {
      showAllListLayanan(LLayanan);
      cout << "Masukkan jenis layanan yang ingin dikerjakan (0 untuk selesai): " << endl;
      cin >> choice;

      if (choice != "0")
      {
        AdrLayanan PLayananFound = findElmLayanan(LLayanan, choice);
        if (PLayananFound == nullptr)
        {
          cout << "Layanan dengan jenis tersebut tidak ditemukan !" << endl;
        }
        else if (findRelationByNamaPekerja(PLayananFound, pekerja.nama) != nullptr)
        {
          cout << "Pekerja sudah termasuk ke layanan tersebut !" << endl;
        }
        else
        {
          AdrRelation PRelation;
          createElmRelation(PRelation, PPekerja);
          insertElmRelation(PLayananFound, PRelation);

          cout << "Pekerja berhasil ditambahkan ke Layanan" << endl;
        }
      }
    } while (choice != "0");
  }
}

// End Admin Menu Section

// Start User Menu Section

void pesanLayanan(ListLayanan LLayanan, ListPekerja LPekerja)
{
  string namaPekerja, jenisLayanan;

  cout << endl;
  cout << "Pesan Layanan" << endl;

  showAllListLayanan(LLayanan);

  cout << "Masukkan Jenis Layanan: ";
  cin >> jenisLayanan;

  AdrLayanan PLayanan = findElmLayanan(LLayanan, jenisLayanan);

  if (PLayanan == nullptr)
  {
    cout << "Layanan dengan jenis tersebut tidak ditemukan !" << endl;
    return;
  }

  showAllRelationByNamaLayanan(LLayanan, jenisLayanan);

  cout << "Masukkan Nama Pekerja: ";
  cin >> namaPekerja;

  AdrPekerja PPekerja = findElmPekerja(LPekerja, namaPekerja);

  if (PPekerja == nullptr)
  {
    cout << "Pekerja dengan nama tersebut tidak ditemukan !" << endl;
    return;
  }

  AdrRelation PRelation = findRelationByNamaPekerja(PLayanan, namaPekerja);

  if (PRelation == nullptr)
  {
    cout << "Pekerja tidak ditemukan di layanan tersebut !" << endl;
    return;
  }

  cout << endl;

  cout << "Data Layanan" << endl;
  cout << "Jenis: " << PLayanan->info.jenis << endl;
  cout << "Jam: " << PLayanan->info.jam << endl;
  cout << "Harga: " << PLayanan->info.harga << endl;
  cout << "Diskon: " << PLayanan->info.diskonLayanan << endl;
  cout << endl;

  cout << "Data Pekerja" << endl;
  cout << "Nama: " << PPekerja->info.nama << endl;
  cout << "Gender: " << PPekerja->info.gender << endl;
  cout << "Rating: " << PPekerja->info.rating << endl;
  cout << endl;

  string confirm;

  do
  {
    cout << "Konfirmasi Pesan Layanan ?" << endl;
    cout << "(y/n): ";
    cin >> confirm;
    if (confirm != "y" && confirm != "n")
    {
      cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
    }
  } while (confirm != "y" && confirm != "n");

  cout << "Pekerja berhasil dipesan" << endl;
}

void showPekerjaByLayanan(ListLayanan LLayanan)
{
  string jenisLayanan;

  cout << endl;
  cout << "Lihat Semua Pekerja dari Layanan" << endl;
  cout << endl;

  showAllListLayanan(LLayanan);

  cout << "Masukkan Jenis: ";
  cin >> jenisLayanan;

  AdrLayanan PLayanan = findElmLayanan(LLayanan, jenisLayanan);

  if (PLayanan == nullptr)
  {
    cout << "Layanan dengan jenis tersebut tidak ditemukan !" << endl;
    return;
  }

  showAllRelationByNamaLayanan(LLayanan, jenisLayanan);

  cout << "Jumlah Pekerja: " << countAllRelationByNamaLayanan(LLayanan, jenisLayanan) << endl;
}

void showLayananByPekerja(ListLayanan LLayanan, ListPekerja LPekerja)
{
  string namaPekerja;

  cout << endl;
  cout << "Lihat Semua Layanan dari Pekerja" << endl;
  cout << endl;

  showAllListPekerja(LPekerja);

  cout << "Masukkan Nama: ";
  cin >> namaPekerja;

  AdrPekerja PPekerja = findElmPekerja(LPekerja, namaPekerja);

  if (PPekerja == nullptr)
  {
    cout << "Pekerja dengan nama tersebut tidak ditemukan !" << endl;
    return;
  }

  showAllRelationByNamaPekerja(LLayanan, LPekerja, namaPekerja);

  cout << "Jumlah Layanan: " << countAllRelationByNamaPekerja(LLayanan, LPekerja, namaPekerja) << endl;
}

// End User Menu Section

// Start Login Menu Handler

void adminHandler(ListLayanan &LLayanan, ListPekerja &LPekerja)
{
  char choice;
  do
  {
    adminMenu();
    cin >> choice;
    switch (choice)
    {
    case '1':
      addLayanan(LLayanan);
      break;
    case '2':
      addPekerja(LLayanan, LPekerja);
      break;
    case '3':
      deletePekerja(LLayanan, LPekerja);
      break;
    case '4':
      editPekerja(LLayanan, LPekerja);
      break;
    case 'q':
      break;
    default:
      cout << "Opsi tidak valid. Silahkan coba lagi." << endl;
    }
  } while (choice != 'q');
}

void userHandler(ListLayanan &LLayanan, ListPekerja &LPekerja)
{
  char choice;
  do
  {
    userMenu();
    cin >> choice;
    switch (choice)
    {
    case '1':
      pesanLayanan(LLayanan, LPekerja);
      break;
    case '2':
      showAllListLayanan(LLayanan);
      cout << "Jumlah Layanan: " << countAllLayanan(LLayanan) << endl;
      break;
    case '3':
      showAllListPekerja(LPekerja);
      cout << "Jumlah Pekerja: " << countAllPekerja(LPekerja) << endl;
      break;
    case '4':
      showPekerjaByLayanan(LLayanan);
      break;
    case '5':
      showLayananByPekerja(LLayanan, LPekerja);
      break;
    case '6':
      cout << "Jumlah Pekerja tanpa Layanan: " << countPekerjaTanpaLayanan(LLayanan, LPekerja) << endl;
      break;
    case 'q':
      break;
    default:
      cout << "Opsi tidak valid. Silahkan coba lagi." << endl;
    }
  } while (choice != 'q');
}

// End Login Menu Handler

// Start Login Menu Section

void loginAdmin(ListAkun &LAkun, ListLayanan &LLayanan, ListPekerja &LPekerja)
{
  InfotypeAkun akun;

  cout << endl;
  cout << "Login Admin" << endl;

  cout << "Username: ";
  cin >> akun.username;

  cout << "Password: ";
  cin >> akun.password;

  AdrAkun PAkunFound = findElmAkun(LAkun, akun.username);

  if (PAkunFound == nullptr || akun.password != PAkunFound->info.password)
  {
    cout << "Username atau Password salah !" << endl;
    return;
  }

  if (PAkunFound->info.role != "admin")
  {
    cout << "Akun bukan admin !" << endl;
    return;
  }

  adminHandler(LLayanan, LPekerja);
}

void loginUser(ListAkun &LAkun, ListLayanan &LLayanan, ListPekerja &LPekerja)
{
  InfotypeAkun akun;

  cout << endl;
  cout << "Login Pengguna" << endl;

  cout << "Username: ";
  cin >> akun.username;

  cout << "Password: ";
  cin >> akun.password;

  AdrAkun PAkunFound = findElmAkun(LAkun, akun.username);

  if (PAkunFound == nullptr || akun.password != PAkunFound->info.password)
  {
    cout << "Username atau Password salah !" << endl;
    return;
  }

  userHandler(LLayanan, LPekerja);
}

void registerUser(ListAkun &LAkun)
{
  InfotypeAkun akun;

  cout << endl;
  cout << "Register Akun" << endl;

  cout << "Masukkan Username: ";
  cin >> akun.username;

  AdrAkun PAkunFound = findElmAkun(LAkun, akun.username);

  if (PAkunFound != nullptr)
  {
    cout << "Username sudah digunakan !" << endl;
    return;
  }

  cout << "Masukkan Password: ";
  cin >> akun.password;

  akun.role = "user";

  AdrAkun PAkun;
  createElmAkun(PAkun, akun);
  insertElmAkun(LAkun, PAkun);

  cout << "Akun berhasil dibuat" << endl;
}

// End Login Menu Section

int main()
{
  ListAkun listAkun;
  ListLayanan listLayanan;
  ListPekerja listPekerja;
  createListAkun(listAkun);
  createListLayanan(listLayanan);
  createListPekerja(listPekerja);

  // Default Admin
  InfotypeAkun infoAdmin = {"admin", "123", "admin"};
  AdrAkun PAdmin;
  createElmAkun(PAdmin, infoAdmin);
  insertElmAkun(listAkun, PAdmin);

  char choice;
  do
  {
    loginMenu();
    cin >> choice;
    switch (choice)
    {
    case '1':
      loginAdmin(listAkun, listLayanan, listPekerja);
      break;
    case '2':
      loginUser(listAkun, listLayanan, listPekerja);
      break;
    case '3':
      registerUser(listAkun);
      break;
    case 'q':
      cout << "Exiting...\n";
      break;
    default:
      cout << "Opsi tidak valid. Silahkan coba lagi." << endl;
    }
  } while (choice != 'q');

  return 0;
}
