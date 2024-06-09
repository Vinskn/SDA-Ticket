#include <fstream>  // Untuk operasi file seperti membaca dan menulis ke file
#include <iostream> // Untuk operasi input dan output dasar, seperti cout dan cin
#include <queue>    // Untuk menggunakan container queue dari STL
#include <sstream>  // Untuk memanipulasi string dengan stringstream
#include <string>   // Untuk operasi string
#include <vector>   // Untuk menggunakan container vector dari STL

using namespace std;

// Struct untuk merepresentasikan pengguna
struct User {
  string nama;
  string username;
  string password;
  bool isAdmin;
};

// Fungsi untuk memuat data pengguna dari file
vector<User> loadData() {
  vector<User> users;
  ifstream file("data.txt");
  string line;

  while (getline(file, line)) {
    stringstream ss(line);
    User user;
    string isAdminStr;

    getline(ss, user.nama, ',');
    getline(ss, user.username, ',');
    getline(ss, user.password, ',');
    getline(ss, isAdminStr, ',');

    // Mengkonversi string isAdminStr menjadi boolean
    user.isAdmin = (isAdminStr == "1");

    users.push_back(user);
  }

  file.close();
  return users;
}

// Fungsi untuk menyimpan data pengguna ke file
void saveData(const vector<User> &users) {
  ofstream file("data.txt");

  for (const auto &user : users) {
    file << user.nama << "," << user.username << "," << user.password << ","
         << (user.isAdmin ? "1" : "0") << "\n";
  }

  file.close();
}

// Fungsi untuk registrasi pengguna baru
void registerUser(vector<User> &users) {
  User user;
  cout << "Masukkan nama: ";
  cin >> user.nama;
  cout << "Masukkan username: ";
  cin >> user.username;
  cout << "Masukkan password: ";
  cin >> user.password;

  user.isAdmin = (user.username.find("kelompok2") != string::npos);

  users.push_back(user);
  saveData(users);

  cout << "registrasi berhasil." << endl;
}

// Fungsi untuk login pengguna
bool loginUser(const vector<User> &users, User &loggedInUser) {
  string username, password;
  cout << "Masukkan username: ";
  cin >> username;
  cout << "Masukkan password: ";
  cin >> password;

  for (const auto &user : users) {
    if (user.username == username && user.password == password) {
      loggedInUser = user;
      if (user.isAdmin) {
        cout << "Selamat datang Admin " << user.nama << endl;
      } else {
        cout << "Selamat datang " << user.nama << endl;
      }
      return true;
    }
  }

  cout << "Username atau password tidak valid." << endl;
  return false;
}


int main() {
  vector<User> users = loadData();
  User loggedInUser;
  int choice;
  bool loggedIn = false;

  while (true) {
    if (!loggedIn) {
      cout << "\n1. Register\n2. Login\n3. Keluar\nPilih opsi: ";
      cin >> choice;
      switch (choice) {
      case 1:
        registerUser(users);
        break;
      case 2:
        if (loginUser(users, loggedInUser)) {
          loggedIn = true;
        }
        break;
      case 3:
        cout << "Keluar...\n";
        return 0;
      default:
        cout << "Pilihan tidak valid. Silakan coba lagi.\n" << endl;
      }
    }
  }
  return 0;
}