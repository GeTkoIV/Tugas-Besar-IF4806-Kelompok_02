#include "mll.h"

void adminPage(ListDeveloper &L);
void userPage(ListDeveloper &L);

bool loginAdmin(string username, string password) {
    if (username == "admin" && password == "123") {
        return true;
    }
    return false;
}

int main() {

    ListDeveloper L;
    createListDeveloper(L);

    int role = -1;

    while (role != 0) {

        cout << endl <<"===== MENU UTAMA ====="<<endl;
        cout << "1. Admin (Login)"<<endl;
        cout << "2. User"<<endl;
        cout << "0. Keluar"<<endl;
        cout << "Pilih: ";
        cin >> role;

        if (role == 1) {
            string user, pass;
            cout << "Username: ";
            cin >> user;
            cout << "Password: ";
            cin >> pass;
            if (loginAdmin(user, pass)) {
                cout << "Login admin berhasil"<<endl;
                adminPage(L);
            } else {
            cout << "Login admin gagal"<<endl;
            }
        } else if (role == 2) {
            userPage(L);
        }
    }

    return 0;
}
