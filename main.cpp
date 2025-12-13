#include "mll.h"

void adminPage(ListDeveloper &L);
void userPage(ListDeveloper &L);

bool loginAdmin() {
    string username, password;

    cout << "\n===== LOGIN ADMIN =====\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "12345") {
        cout << "Login berhasil!\n";
        return true;
    } else {
        cout << "Login gagal! Username atau password salah.\n";
        return false;
    }
}

int main() {

    ListDeveloper L;
    createListDeveloper(L);

    int role = -1;

    while (role != 0) {

        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Admin (Login)\n";
        cout << "2. User\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> role;

        if (role == 1) {

            bool auth = loginAdmin();

            if (auth == true) {
                adminPage(L);
            }

        } else if (role == 2) {

            userPage(L);

        }
    }

    return 0;
}
