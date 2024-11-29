#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include <iomanip>
#include<cstdlib>
using namespace std;
int co = 0;
int index;
int num = 0, num2 = 0, del[5] = { }, indeex;
string y, s1, s2 = "0", num3;
struct account {
    string id;
    string password;
    int cun;
    string borr[3] = {};
    string que_number;
    string que_ans;
}arracc[1000];
struct book {
    string name;
    string id;
    string edition;
    string writer;
    int counter;
};
struct cat {
    string caty;
    book arrbook[200];
}arrcat[5];
int arr[5];
string hidden_password();
void create();
void heart();
void Display_Book();
void Display_Cat();
void view_my_books();
void Edit_Books();
void student_list();
void admin_list();
void admin();
void student();
void forget(string ids);
void menu();
void idofbook();
void file_reading();
void edit_student();
void file_writing();
void displaycat();
void displaybooks();
void math();
void chemistrey();
void geography();
void physics();
void biology();
void line();
void displaycategoryadd();
void displaycategorydelete();
void Deletebook();
void addbook();
void displaybooksdelete();
void copy();
string hidden_password2();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    line();
    math();
    chemistrey();
    geography();
    biology();
    physics();
    arrcat[0].caty = { "math" };
    arrcat[1].caty = { "chemistry" };
    arrcat[2].caty = { "geography" };
    arrcat[3].caty = { "biology" };
    arrcat[4].caty = { "physics" };
    file_reading();
    idofbook();
    menu();
    copy();
    return 0;
}
void line() {
    ifstream data;
    data.open("num.txt", ios::in);
    for (int i = 0; i < 5; i++) {
        data >> arr[i];
    }
    data.close();
}
void math() {
    ifstream datamath;
    datamath.open("math.txt", ios::in);
    for (int i = 0; i < (arr[0] + del[0]); i++) {
        getline(datamath, arrcat[0].arrbook[i].name);
        getline(datamath, arrcat[0].arrbook[i].id);
        getline(datamath, arrcat[0].arrbook[i].edition);
        getline(datamath, arrcat[0].arrbook[i].writer);
        datamath >> arrcat[0].arrbook[i].counter;
        datamath.ignore();
    }
    datamath.close();
}
void chemistrey() {
    ifstream datachemistry;
    datachemistry.open("chem.txt", ios::in);
    for (int i = 0; i < (arr[1] + del[1]); i++) {
        getline(datachemistry, arrcat[1].arrbook[i].name);
        getline(datachemistry, arrcat[1].arrbook[i].id);
        getline(datachemistry, arrcat[1].arrbook[i].edition);
        getline(datachemistry, arrcat[1].arrbook[i].writer);
        datachemistry >> arrcat[1].arrbook[i].counter;
        datachemistry.ignore();
    }
    datachemistry.close();
}
void geography() {
    ifstream datageography;
    datageography.open("geo.txt", ios::in);
    for (int i = 0; i < arr[2]; i++) {
        getline(datageography, arrcat[2].arrbook[i].name);
        getline(datageography, arrcat[2].arrbook[i].id);
        getline(datageography, arrcat[2].arrbook[i].edition);
        getline(datageography, arrcat[2].arrbook[i].writer);
        datageography >> arrcat[2].arrbook[i].counter;
        datageography.ignore();
    }
    datageography.close();
}
void biology() {
    ifstream databiology;
    databiology.open("Bio.txt", ios::in);
    for (int i = 0; i < (arr[3] + del[3]); i++) {
        getline(databiology, arrcat[3].arrbook[i].name);
        getline(databiology, arrcat[3].arrbook[i].id);
        getline(databiology, arrcat[3].arrbook[i].edition);
        getline(databiology, arrcat[3].arrbook[i].writer);
        databiology >> arrcat[3].arrbook[i].counter;
        databiology.ignore();
    }
    databiology.close();
}
void physics() {
    ifstream dataphysics;
    dataphysics.open("physics.txt", ios::in);
    for (int i = 0; i < arr[4] + del[4]; i++) {
        getline(dataphysics, arrcat[4].arrbook[i].name);
        getline(dataphysics, arrcat[4].arrbook[i].id);
        getline(dataphysics, arrcat[4].arrbook[i].edition);
        getline(dataphysics, arrcat[4].arrbook[i].writer);
        dataphysics >> arrcat[4].arrbook[i].counter;
        dataphysics.ignore();
    }
    dataphysics.close();
}
void displaycat() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    cout << "CHOOSE YOUR DESIRED CATEGORY:)  \n";
    cout << "----------------------------------\n";
    while (true) {
        for (int i = 0; i < 5; i++) {
            cout << "\t" << i + 1 << ") " << arrcat[i].caty << endl;
        }
        cout << "\t6) BACK\n";
        cin >> s1;
        if (s1 == "1" || s1 == "2" || s1 == "3" || s1 == "4" || s1 == "5") {
            num = stoi(s1);
            displaybooks();
            break;
        }
        else if (s1 == "6") {
            student_list();
            break;
        }
        else {
            cout << "INVALID CHOICE\n";;
            continue;
        }
    }
}
void displaybooks() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 6);                                                       //a is num of cat
    int i, n, test = 0, test1 = 0;
    while (true) {
        n = 1;
        cout << "---------------------------------------------------------------------------------------------------------------\n";
        cout << left << setw(52) << "NAME" << left << setw(8) << "ID" << left << setw(10) << "EDITION" << left << setw(30) << "WRITER" << left << setw(8) << "COPIES" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------\n";
        for (i = 0; i < arr[num - 1]; i++) {
            if (arrcat[num - 1].arrbook[i].counter >= 0) {
                cout << n << "-" << left << setw(50) << arrcat[num - 1].arrbook[i].name
                    << left << setw(8) << arrcat[num - 1].arrbook[i].id
                    << left << setw(10) << arrcat[num - 1].arrbook[i].edition
                    << left << setw(30) << arrcat[num - 1].arrbook[i].writer
                    << left << setw(8) << arrcat[num - 1].arrbook[i].counter
                    << endl;
                cout << "---------------------------------------------------------------------------------------------------------------\n";
                n++;
            }
        }
        cout << n << ": BACK\n";
        cin >> s2;
        bool check = true;
        for (char c : s2) {
            if (!isdigit(c)) {
                check = false;
                break;
            }
        }
        if (check) {
            num2 = stoi(s2);
            if (num2 < n) {                                                     //chose book
                if (y == "1") {
                    if (s2 == "6") {
                        displaycat();
                        break;
                    }
                    else {
                        cout << "INVALID CHOICE\n";
                        continue;
                    }
                }
                else if (y == "2") {
                    idofbook();
                    copy();
                    while (true) {
                        cout << "\t1) BORROW.\n";
                        cout << "\t2) BACK.\n";
                        cin >> num3;
                        if (num3 == "1") {
                            if (arrcat[num - 1].arrbook[num2 - 1].counter > 0 && arracc[index].cun < 3) {
                                if (arracc[index].borr[0] == "0") {
                                    arrcat[num - 1].arrbook[num2 - 1].counter--;
                                    arracc[index].cun++;
                                    arracc[index].borr[0] = arrcat[num - 1].arrbook[num2 - 1].id;
                                    copy();
                                    file_writing();
                                    cout << "\t---------------------------------------------\n";
                                    cout << "\t|YOU HAVE BORROWED THIS BOOK SUCCESSFULLY:) |\n";
                                    cout << "\t---------------------------------------------\n";
                                    displaycat();
                                    break;
                                }
                                else if (arracc[index].borr[1] == "0") {
                                    arrcat[num - 1].arrbook[num2 - 1].counter--;
                                    arracc[index].cun++;
                                    arracc[index].borr[1] = arrcat[num - 1].arrbook[num2 - 1].id;
                                    copy();
                                    file_writing();
                                    cout << "\t---------------------------------------------\n";
                                    cout << "\t|YOU HAVE BORROWED THIS BOOK SUCCESSFULLY:) |\n";
                                    cout << "\t---------------------------------------------\n";
                                    displaycat();
                                    break;
                                }
                                else if (arracc[index].borr[2] == "0") {
                                    arrcat[num - 1].arrbook[num2 - 1].counter--;
                                    arracc[index].cun++;
                                    arracc[index].borr[2] = arrcat[num - 1].arrbook[num2 - 1].id;
                                    copy();
                                    file_writing();
                                    cout << "\t---------------------------------------------\n";
                                    cout << "\t|YOU HAVE BORROWED THIS BOOK SUCCESSFULLY:) |\n";
                                    cout << "\t---------------------------------------------\n";
                                    displaycat();
                                    break;
                                }
                            }
                            else if (arracc[index].cun == 3) {
                                cout << "\t---------------------------------------------\n";
                                cout << "\t|YOU HAVE EXCEEDED YOUR LIMIT IN BORROWING:(|\n";
                                cout << "\t---------------------------------------------\n";
                                student_list();
                                break;
                            }
                            else {
                                cout << "\t----------------------------------------------------------------------\n";
                                cout << "\t|THIS BOOK IS NOT AVALIABLE NOW PLEASE REBORROW IT IN ANOTHER TIME:( |\n";
                                cout << "\t----------------------------------------------------------------------\n";
                                displaybooks();
                                break;
                            }
                        }
                        else if (num3 == "2") {
                            test = 1;
                            break;
                        }
                        else {
                            cout << "INVALID CHOICE\n";
                            continue;
                        }
                    }
                    if (test == 1) {
                        continue;
                    }
                    else {
                        break;
                    }

                }
                else if (y == "3") {
                    while (true) {
                        cout << "\t1) RETURN.\n";
                        cout << "\t2) BACK.\n";
                        cin >> num3;
                        if (num3 == "1") {
                            if (arrcat[num - 1].arrbook[num2 - 1].counter < 3 && arracc[index].cun != 0) {
                                if (arracc[index].borr[0] == arrcat[num - 1].arrbook[num2 - 1].id) {
                                    arracc[index].borr[0] = "0";
                                    (arrcat[num - 1].arrbook[num2 - 1].counter)++;
                                    arracc[index].cun--;
                                    cout << "\t--------------------------------------------\n";
                                    cout << "\t|YOU HAVE RETURNED THIS BOOK SUCCESSFULLY  |\n";
                                    cout << "\t--------------------------------------------\n";
                                    copy();
                                    file_writing();
                                    displaybooks();

                                }
                                else if (arracc[index].borr[1] == arrcat[num - 1].arrbook[num2 - 1].id) {
                                    arracc[index].borr[1] = "0";
                                    (arrcat[num - 1].arrbook[num2 - 1].counter)++;
                                    arracc[index].cun--;
                                    cout << "\t--------------------------------------------\n";
                                    cout << "\t|YOU HAVE RETURNED THIS BOOK SUCCESSFULLY  |\n";
                                    cout << "\t--------------------------------------------\n";
                                    copy();
                                    file_writing();
                                    displaybooks();

                                }
                                else if (arracc[index].borr[2] == arrcat[num - 1].arrbook[num2 - 1].id) {
                                    arracc[index].borr[2] = "0";
                                    (arrcat[num - 1].arrbook[num2 - 1].counter)++;
                                    arracc[index].cun--;
                                    cout << "\t--------------------------------------------\n";
                                    cout << "\t|YOU HAVE RETURNED THIS BOOK SUCCESSFULLY  |\n";
                                    cout << "\t--------------------------------------------\n";
                                    copy();
                                    file_writing();
                                    displaybooks();

                                }
                                else {
                                    cout << "\tTHE BOOK IS NOT WITH YOU\n";
                                    cout << "\t----------------------------\n";
                                    displaybooks();
                                }
                                break;
                            }
                            else if (arracc[index].cun == 0) {
                                cout << "\t--------------------------------------\n";
                                cout << "\t|YOU HAVE NOT BORROWED ANY BOOKS YET  |\n";
                                cout << "\t--------------------------------------\n";
                                test1 = 1;
                                break;
                            }
                            else {
                                cout << "\t-----------------------------------\n";
                                cout << "\t|THE BOOKS ARE ALREADY EXISTED    |\n";
                                cout << "\t-----------------------------------\n";
                                test1 = 1;
                                break;
                            }
                        }
                        else if (num3 == "2") {
                            displaycat();
                            break;
                        }
                        else {
                            cout << "INVALID CHOICE\n";
                            continue;
                        }

                    }
                    if (test1 == 1) {
                        continue;
                    }
                    else {
                        break;
                    }
                }

                break;
            }
            else if (num2 == n) {                                                        //back
                displaycat();
                break;
            }
        }
        else {
            cout << "INVALID CHOICE\n";
            continue;
        }

    }


}
void displaycategoryadd() {
    int i;
    while (true) {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 14);
        cout << "-----------------------------------------\n";
        cout << "| ENTER THE CATEGORY OF THE ADDED BOOK :|" << endl;
        cout << "-----------------------------------------\n";
        for (i = 0; i < 5; i++) {
            cout << "\t" << i + 1 << ") " << arrcat[i].caty << endl;
        }
        cout << "\t" << i + 1 << ") BACK" << endl;
        cin >> s1;
        if (s1 == "1" || s1 == "2" || s1 == "3" || s1 == "4" || s1 == "5") {
            num = stoi(s1);
            addbook();
            break;
        }
        else if (s1 == "6") {
            admin_list();
            break;
        }
        else {
            cout << "INVALID CHOICE " << endl;
            continue;
        }
    }
}
void addbook() {
    bool check = 1;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 8);
    string choice = "n";
    cout << "\tPLEASE FILL THE INFORMATION ABOUT THE BOOK:) :\n";
    cout << "\t--------------------------------------------------\n";
    cout << " ENTER THE BOOK NAME :";
    cin.ignore();
    getline(cin, arrcat[num - 1].arrbook[arr[num - 1]].name);
    while (true) {
        check = 1;
        cout << " ENTER THE BOOK ID :";
        getline(cin, arrcat[num - 1].arrbook[arr[num - 1]].id);
        for (int j = 0; j < 5; j++) {
            for (int h = 0; h < arr[j]; h++) {
                if (arrcat[num - 1].arrbook[arr[num - 1]].id == arrcat[j].arrbook[h].id) {
                    cout << "THIS ID IS ALREADY EXIST PLEASE ENTER ANOTHER ONE \n";
                    cout << "---------------------------------------------------------\n";
                    check = 0;
                }
            }
        }
        if (check == 0) {
            continue;
        }
        else break;
    }
    cout << " ENTER THE BOOK EDITION :";
    getline(cin, arrcat[num - 1].arrbook[arr[num - 1]].edition);
    cout << " ENTER THE BOOK WRITER :";
    getline(cin, arrcat[num - 1].arrbook[arr[num - 1]].writer);
    arrcat[num - 1].arrbook[arr[num - 1]].counter = 3;
    while (true) {
        cout << " ARE YOU SURE YOU WANT TO ADD THIS BOOK ?(y/n)" << endl;
        cin >> choice;
        if (choice == "y" || choice == "Y") {
            arr[num - 1]++;
            copy();
            cout << "\t-------------------------------------------------\n";
            cout << "\t|    THE BOOK HAS BEEN ADDED SUCCESSFULLY :)    |\n";
            cout << "\t-------------------------------------------------\n";
            admin_list();
            break;
        }
        else if (choice == "n" || choice == "N") {
            displaycategoryadd();
            break;
        }
        else {
            cout << " INVALID CHOICE " << endl;
            continue;
        }
    }
}
void copy() {
    ofstream data;
    data.open("num.txt");
    data.clear();
    for (int i = 0; i < 5; i++) {
        data << arr[i] << endl;
    }
    data.close();
    ofstream data1;
    data1.open("b.txt", ios::in);
    data1.clear();
    for (int i = 0; i < co; i++) {
        for (int l = 0; l < 3; l++) {
            data1 << arracc[i].borr[l] << endl;
        }
    }
    data1.close();
    ofstream datamath;
    datamath.open("math.txt");
    datamath.clear();
    for (int i = 0; i < (arr[0] + del[0]); i++) {
        if (arrcat[0].arrbook[i].counter == -1) {
            continue;
        }
        datamath << arrcat[0].arrbook[i].name << endl;
        datamath << arrcat[0].arrbook[i].id << endl;
        datamath << arrcat[0].arrbook[i].edition << endl;
        datamath << arrcat[0].arrbook[i].writer << endl;
        datamath << arrcat[0].arrbook[i].counter << endl;
    }
    datamath.close();


    ofstream datachemistry;
    datachemistry.open("chem.txt");
    datachemistry.clear();
    for (int i = 0; i < (arr[1] + del[1]); i++) {
        if (arrcat[1].arrbook[i].counter == -1) {
            continue;
        }

        datachemistry << arrcat[1].arrbook[i].name << endl;
        datachemistry << arrcat[1].arrbook[i].id << endl;
        datachemistry << arrcat[1].arrbook[i].edition << endl;
        datachemistry << arrcat[1].arrbook[i].writer << endl;
        datachemistry << arrcat[1].arrbook[i].counter << endl;
    }
    datachemistry.close();


    ofstream datageography;
    datageography.open("geo.txt");
    datageography.clear();
    for (int i = 0; i < (arr[2] + del[2]); i++) {
        if (arrcat[2].arrbook[i].counter == -1) {
            continue;
        }

        datageography << arrcat[2].arrbook[i].name << endl;
        datageography << arrcat[2].arrbook[i].id << endl;
        datageography << arrcat[2].arrbook[i].edition << endl;
        datageography << arrcat[2].arrbook[i].writer << endl;
        datageography << arrcat[2].arrbook[i].counter << endl;
    }
    datageography.close();

    ofstream databiology;
    databiology.open("Bio.txt");
    databiology.clear();
    for (int i = 0; i < (arr[3] + del[3]); i++) {
        if (arrcat[3].arrbook[i].counter == -1) {
            continue;
        }

        databiology << arrcat[3].arrbook[i].name << endl;
        databiology << arrcat[3].arrbook[i].id << endl;
        databiology << arrcat[3].arrbook[i].edition << endl;
        databiology << arrcat[3].arrbook[i].writer << endl;
        databiology << arrcat[3].arrbook[i].counter << endl;
    }
    databiology.close();
    ofstream dataphysics;
    dataphysics.open("physics.txt");
    dataphysics.clear();
    for (int i = 0; i < (arr[4] + del[4]); i++) {
        if (arrcat[4].arrbook[i].counter == -1) {
            continue;
        }

        dataphysics << arrcat[4].arrbook[i].name << endl;
        dataphysics << arrcat[4].arrbook[i].id << endl;
        dataphysics << arrcat[4].arrbook[i].edition << endl;
        dataphysics << arrcat[4].arrbook[i].writer << endl;
        dataphysics << arrcat[4].arrbook[i].counter << endl;
    }
    dataphysics.close();

}
void menu() {
    while (true) {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 3);
        string m;
        cout << "\t\t\t================================================\n";
        cout << "\t\t\t||       WELCOME TO OUR LIBRARY SYSTEM :)     || \n";
        cout << "\t\t\t||--------------------------------------------||\n";
        cout << "\t\t\t||         1-CREATE AN ACCOUNT.               ||\n";
        cout << "\t\t\t||         2-SIGN IN AS A STUDENT.            ||\n";
        cout << "\t\t\t||         3-SIGN IN AS AN ADMIN.             ||\n";
        cout << "\t\t\t||         4-FORGET YOUR PASSWORD?            ||\n";
        cout << "\t\t\t||         5-EXIT FROM SYSTEM.                ||\n";
        cout << "\t\t\t================================================\n";
        cout << "\t\t\t  PLEASE CHOOSE YOUR OPTION:) :";
        cin >> m;
        if (m == "1") {
            create();
        }
        else if (m == "2") {
            student();
            break;
        }
        else if (m == "3") {
            admin();
            break;
        }
        else if (m == "4") {
            string q;
            while (true) {
                cout << "\t1-ENTER YOUR ID\n";
                cout << "\t2-BACK\n";
                cin >> q;
                if (q == "1") {
                    break;
                }
                else if (q == "2") {
                    menu();
                    break;
                }
                else {
                    cout << "INVALID CHOICE\n";
                    continue;
                }
            }
            string idd;
            cout << "ID: ";
            cin >> idd;
            forget(idd);
            break;
        }
        else if (m == "5") {
            cout << endl << endl;
            cout << "\t\t\t\t  #######  ##    ##   ######   ####    ##  ##   ##    ##    ##     ##      ##    ##\n";
            cout << "\t\t\t\t    ##     ##    ##  ##    ##  ## ##   ##  ##  ##      ##  ##    ##  ##    ##    ##\n";
            cout << "\t\t\t\t    ##     ########  ########  ##  ##  ##  ## ##         ##     ##    ##   ##    ##\n";
            cout << "\t\t\t\t    ##     ##    ##  ##    ##  ##   ## ##  ##  ##        ##      ##  ##     ##  ##\n";
            cout << "\t\t\t\t    ##     ##    ##  ##    ##  ##    ####  ##   ##       ##        ##         ##\n\n";
            heart();
            cout << "\t\t\t\tFOR USING OUR LIBRARY SYSTEM :)\n";
            cout << "\t\t\t--------------------------------------------------------------------------------------\n";
            exit(0);
            break;
        }
        else
        {
            cout << "INVALID CHOICE :(\n";
            continue;
        }
    }
}
void student() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 11);
    string ids, q;
    while (true) {
        cout << "\t1-ENTER YOUR ID\n";
        cout << "\t2-BACK\n";
        cin >> q;
        if (q == "1") {
            break;
        }
        else if (q == "2") {
            menu();
            break;
        }
        else {
            cout << "INVALID CHOICE\n";
            continue;
        }
    }
    cout << "ID:";
    cin >> ids;
    string pass_s = hidden_password();
    bool ok = false;
    for (int i = 0; i < co; i++) {
        if (arracc[i].id == ids && arracc[i].password == pass_s) {
            index = i;
            ok = true;
            break;
        }
    }
    if (ok) {
        cout << "\t------------------------------------\n";
        cout << "\t|YOU HAVE LOGGED IN SUCCESSFULLY:) |\n";
        cout << "\t------------------------------------\n";
        student_list();

    }
    else {
        bool okk = true;
        while (okk) {
            cout << "YOUR ID OR PASSWORD IS WRONG :(\n";
            while (true) {
                cout << "\t1-ENTER YOUR ID\n";
                cout << "\t2-BACK\n";
                cin >> q;
                if (q == "1") {
                    break;
                }
                else if (q == "2") {
                    menu();
                    break;
                }
                else {
                    cout << "INVALID CHOICE\n";
                    continue;
                }
            }
            cin >> ids;
            string pass_s = hidden_password();
            for (int h = 0; h < co; h++) {
                if (arracc[h].id == ids && arracc[h].password == pass_s) {
                    cout << "\t------------------------------------\n";
                    cout << "\t|YOU HAVE LOGGED IN SUCCESSFULLY:) |\n";
                    cout << "\t------------------------------------\n";
                    index = h;
                    student_list();
                    okk = false;
                    break;
                }
            }
        }
    }
}
void student_list() {
    while (true) {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 7);
        cout << "\t\t----------------------\t\t\n";
        cout << "\t\t|CHOOSE YOUR OPTION :|\t\t\n";
        cout << "\t\t|--------------------|\t\t\n";
        cout << "\t\t|1-VIEW.             |\n";
        cout << "\t\t|2-BORROW.           |\n";
        cout << "\t\t|3-RETURN.           |\n";
        cout << "\t\t|4-EDIT.             |\n";
        cout << "\t\t|5-VIEW MY BOOKS.    |\n";
        cout << "\t\t|6-LOG OUT.          |\n";
        cout << "\t\t----------------------\t\t\n";
        cout << "\t\tYOUR CHOICE:) :";
        cin >> y;
        bool test = 1;
        if (y == "1" || y == "2" || y == "3") {
            displaycat();
            break;
        }
        else if (y == "4") {
            edit_student();
            break;
        }
        else if (y == "5") {
            view_my_books();
            break;
        }
        else if (y == "6") {
            cout << "DO YOU WANT TO LOG OUT (n/y)?\n";
            char n;
            while (true) {
                cin >> n;
                if (n == 'n' || n == 'N') {
                    break;
                }
                else if (n == 'y' || n == 'Y') {
                    test = 0;
                    break;
                }
                else {
                    cout << "INVALID CHOICE :(\n";
                    continue;
                }
            }
            if (test == 1) {
                continue;
            }
            else {
                menu();
                break;
            }
        }
        else {
            cout << "INVALID CHOICE :(\n";
            continue;
        }
    }
}
string hidden_password() {
    while (true) {
        cout << "PASSWORD (atleast 8 char): ";
        string password = "";
        char ch;
        while (true) {
            ch = _getch();
            if (ch == '\r') {
                break;
            }
            if (ch == '\b') {
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                }
            }
            else {
                password.push_back(ch);
                cout << "*";
            }
        }
        cout << endl;
        if (password.size() >= 8) {
            return password;
            break;
        }
        else
        {
            cout << "YOUR PASSWORD IS LESS THAN 8 CHARECTERS\n";
            cout << "------------------------------------------\n";
            continue;
        }
    }
}
void create() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 11);
    string ids, q;
    bool test = 1;
    while (true) {
        cout << "\t1-ENTER YOUR ID\n";
        cout << "\t2-BACK\n";
        cin >> q;
        if (q == "1") {
            break;
        }
        else if (q == "2") {
            menu();
            break;
        }
        else {
            cout << "INVALID CHOICE\n";
            continue;
        }
    }
    cout << "ID: ";
    cin >> ids;
    for (int i = 0; i < co; i++) {
        if (ids == arracc[i].id) {
            bool exist = 1;
            while (exist) {
                cout << "ALREADY EXIST :( \n";
                cout << "PLEASE ENTER ANOTHER ID : ";
                cin >> ids;
                for (int h = 0; h < co; h++) {
                    if (ids == arracc[h].id)
                        break;
                    else exist = 0;
                }
            }
        }
    }
    arracc[co].id = ids;
    string passwords = hidden_password();
    string ques;
    while (true) {
        string w;
        cout << "\t\t\t--------------------------------------\t\t\n";
        cout << "\t\t\t|       CHOOSE SECURITY QUESTION :   |\t\t\n";
        cout << "\t\t\t|------------------------------------|\t\t\n";
        cout << "\t\t\t|1- WHAT CITY WERE YOU BORN IN?      |\n";
        cout << "\t\t\t|2- WHAT IS YOUR HOBBY?              |\n";
        cout << "\t\t\t|3- WHAT IS YOUR NICKNAME?           |\n";
        cout << "\t\t\t|4- WHAT IS YOUR FAVORITE FOOD?      |\n";
        cout << "\t\t\t|5- WHO IS YOUR SUPER HERO?          |\n";
        cout << "\t\t\t|6- BACK                             |\n";
        cout << "\t\t\t--------------------------------------\t\t\n";
        cout << "\t\t YOUR CHOICE:) : ";
        bool test4 = 0;
        cin >> ques;
        if (ques == "6") {
            create();
            break;
        }
        while (true) {
            cout << "\t1-ENTER YOUR ANSWER\n";
            cout << "\t2-BACK\n";
            cin >> w;
            if (w == "1") {
                break;
            }
            else if (w == "2") {
                test4 = 1;
                break;
            }
            else {
                cout << "INVALID CHOICE\n";
                continue;
            }
        }
        if (test4 == 1) {
            continue;
        }
        else {
            break;
        }
    }
    cout << "ANSWER: ";
    string ans;
    cin.ignore();
    getline(cin, ans);
    arracc[co].que_number = ques;
    arracc[co].que_ans = ans;
    cout << "\t----------------------------------\n";
    cout << "\t| ACCOUNT CREATED SUCCESSFULLY:) |\n";
    cout << "\t----------------------------------\n";
    arracc[co].password = passwords;
    co++;
    ofstream id, password, cun, data1, que;
    cun.open("cun.txt", ios::app);
    data1.open("b.txt", ios::app);
    id.open("id.txt", ios::app);
    que.open("qus.txt", ios::app);
    password.open("pass.txt", ios::app);
    id << ids << endl;
    password << passwords << endl;
    data1 << 0 << endl << 0 << endl << 0 << endl;
    cun << 0 << endl;
    que << ques << endl << ans << endl;
    cun.close();
    id.close();
    data1.close();
    password.close();
    que.close();
}
void admin_list() {
    while (true) {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 7);
        string f;
        cout << "\t\t---------------------------\t\t\n";
        cout << "\t\t|  CHOOSE YOUR OPTION :   |\t\t\n";
        cout << "\t\t|-------------------------|\t\t\n";
        cout << "\t\t|1-EDIT ANY INFORMATION.  |\n";
        cout << "\t\t|2-DELETE ANY INFORMATION.|\n";
        cout << "\t\t|3_ADD ANY INFORMATION.   |\n";
        cout << "\t\t|4-LOG OUT.               |\n";
        cout << "\t\t---------------------------\t\t\n";
        cout << "\t\tYOUR CHOICE:) :";
        cin >> f;
        bool test = 1;
        if (f != "1" && f != "2" && f != "3" && f != "4") {
            cout << "INVALID CHOICE :(\n";
            continue;
        }
        else if (f == "1") {
            Display_Cat();
            break;
        }
        else if (f == "2") {
            displaycategorydelete();
            break;
        }
        else if (f == "3") {
            displaycategoryadd();
            break;
        }
        else if (f == "4") {
            cout << "DO YOU WANT TO LOG OUT (n/y)?\n";
            char z;
            while (true) {
                cin >> z;
                if (z == 'n' || z == 'N') {
                    break;
                }
                else if (z == 'y' || z == 'Y') {
                    test = 0;
                    break;
                }
                else {
                    cout << "INVALID CHOICE :(\n";
                    continue;
                }
            }
            if (test == 1) {
                continue;
            }
            else {
                menu();
                break;
            }
        }
    }
}
void admin() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 11);
    string ida, q;
    while (true) {
        cout << "\t1-ENTER YOUR ID\n";
        cout << "\t2-BACK\n";
        cin >> q;
        if (q == "1") {
            break;
        }
        else if (q == "2") {
            menu();
            break;
        }
        else {
            cout << "INVALID CHOICE\n";
            continue;
        }
    }
    cout << "ID : ";
    cin >> ida;
    string passa = hidden_password();
    if (passa == ida && ida == "admin12345") {
        cout << "\t------------------------------------\n";
        cout << "\t|YOU HAVE LOGGED IN SUCCESSFULLY:) |\n";
        cout << "\t------------------------------------\n";
        admin_list();

    }
    else {
        while (true) {
            cout << "YOUR ID OR PASSWORD IS WRONG :(\n";
            cout << "ENTER YOUR ID AGAIN PLEASE : ";
            cin >> ida;
            string passa = hidden_password();
            if (ida == passa && ida == "admin12345") {
                cout << "\t------------------------------------\n";
                cout << "\t|YOU HAVE LOGGED IN SUCCESSFULLY:) |\n";
                cout << "\t------------------------------------\n";
                admin_list();
                break;
            }
        }
    }
}
void file_reading() {
    ifstream id, cun, que;
    cun.open("cun.txt");
    id.open("id.txt");
    que.open("qus.txt");
    int l = 0;
    string line;
    while (getline(id, line)) {
        arracc[l].id = line;
        l++;
    }
    ifstream password;
    password.open("pass.txt");
    while (getline(password, line)) {
        arracc[co].password = line;
        co++;
    }
    for (int i = 0; i < co; i++) {
        cun >> arracc[i].cun;
    }
    for (int i = 0; i < co; i++) {
        que >> arracc[i].que_number;
        que.ignore();
        getline(que, arracc[i].que_ans);
    }
    que.close();
    cun.close();
    id.close();
    password.close();
}
void edit_student() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 11);
    string v;
    while (true) {
        cout << "\t-------------------------\n";
        cout << "\t| CHOOSE YOUR OPTION :  |\n";
        cout << "\t|-----------------------|\n";
        cout << "\t|1-EDIT YOUR ID.        |\n";
        cout << "\t|2-EDIT YOUR PASSWORD.  |\n";
        cout << "\t|3-BACK.                |\n";
        cout << "\t-------------------------\n";
        cin >> v;
        if (v == "1") {
            while (true) {
                cout << "ENTER YOUR CURRENT ID : ";
                string pid;
                cin >> pid;
                if (pid == arracc[index].id) {
                    cout << "ENTER YOUR NEW ID : ";
                    string nid;
                    cin >> nid;
                    for (int i = 0; i < co; i++) {
                        if (nid == arracc[i].id) {
                            bool exist = 1;
                            while (exist) {
                                cout << "ALREADY EXIST :(\n";
                                cout << "PLEASE ENTER ANOTHER ID : ";
                                cin >> nid;
                                for (int h = 0; h < co; h++) {
                                    if (nid == arracc[h].id) {
                                        exist = 1;
                                        break;
                                    }
                                    else exist = 0;
                                }
                            }
                        }
                    }
                    arracc[index].id = nid;
                    file_writing();
                    cout << "\t------------------------------------------\n";
                    cout << "\t|YOU HAVE CHANGED YOUR ID SUCCESSFULLY :)|\n";
                    cout << "\t------------------------------------------\n";
                    student_list();
                    break;
                }
                else {
                    cout << " YOUR ID IS WRONG :( \n";
                    continue;
                }
            }
            break;
        }
        else if (v == "2") {
            while (true)
            {
                cout << "ENTER YOUR CURRENT PASSWORD : ";
                string pPASS = hidden_password();
                if (pPASS == arracc[index].password) {
                    string npass = hidden_password2();
                    arracc[index].password = npass;
                    file_writing();
                    cout << "\t------------------------------------------------\n";
                    cout << "\t|YOU HAVE CHANGED YOUR PASSWORD SUCCESSFULLY :)|\n";
                    cout << "\t-----------------------------------------------\n";
                    student_list();
                    break;
                }
                else {
                    cout << "PASSWORD IS WRONG :( \n";
                    continue;
                }
            }
            break;
        }
        else if (v == "3") {
            student_list();
            break;
        }
        else {
            cout << "INVALID CHOICE :(\n";
        }
    }
}
void file_writing() {
    ofstream id, password, cun;
    cun.open("cun.txt");
    id.open("id.txt");
    password.open("pass.txt");
    id.clear();
    password.clear();
    for (int i = 0; i < co; i++) {
        id << arracc[i].id << endl;
        password << arracc[i].password << endl;
        cun << arracc[i].cun << endl;
    }
    cun.close();
    id.close();
    password.close();
}
void displaycategorydelete() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 4);
    int i;
    while (true) {
        cout << "-----------------------------------------------\n";
        cout << "|ENTER THE CATEGORY YOU WANT TO DELETE FROM :|\n";
        cout << "-----------------------------------------------\n";
        for (i = 0; i < 5; i++) {
            cout << "\t" << i + 1 << ") " << arrcat[i].caty << endl;
        }
        cout << "\t" << i + 1 << ") BACK" << endl;
        cin >> s1;
        if (s1 == "1" || s1 == "2" || s1 == "3" || s1 == "4" || s1 == "5") {
            num = stoi(s1);
            displaybooksdelete();
            break;
        }
        else if (s1 == "6") {
            admin_list();
            break;
        }
        else {
            cout << " INVALID CHOCE " << endl;
            continue;

        }
    }
}
void displaybooksdelete() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    string choice = "n";
    while (true) {
        int i, n = 1;
        for (i = 0; i < arr[num - 1]; i++) {
            cout << n << ":" << arrcat[num - 1].arrbook[i].name << endl;
            n++;

        }
        cout << n << ": BACK\n";
        cin >> s2;
        bool check = true;
        for (char c : s2) {
            if (!isdigit(c)) {
                check = false;
                break;
            }
        }
        if (check) {
            num2 = stoi(s2);
            if (num2 < n) {
                if (arrcat[num - 1].arrbook[num2 - 1].counter < 3) {
                    cout << "YOU CANT DELETE IT NOW AS ITS COPIES ARE BORROWED\n";
                    cout << "-------------------------------------------------------\n";
                    continue;
                }
                else {
                    break;
                }
            }
            else if (num2 == n) {
                displaycategorydelete();
                break;
            }
        }
        else {
            cout << "INVALID CHOICE\n";
            continue;
        }
    }
    while (true) {
        cout << " ARE YOU SURE YOU WANT TO DELETE THIS BOOK ?(y/n)" << endl;
        cin >> choice;
        if (choice == "y" || choice == "Y") {
            Deletebook();
            cout << "\t----------------------------------------------\n";
            cout << "\t|   THE BOOK HAS BEEN DELETED SUCCESSFULLY   |\n";
            cout << "\t----------------------------------------------\n";
            copy();
            admin_list();
            break;
        }
        else if (choice == "n" || choice == "N") {
            displaycategorydelete();
            break;
        }
        else {
            cout << "INVALID CHOICE\n " << endl;
            continue;
        }
    }

}
void Deletebook() {
    arrcat[num - 1].arrbook[num2 - 1].counter = -1;
    arr[num - 1]--;                                                                // num of copies
    del[num - 1]++;
    copy();
    line();
    math();
    chemistrey();
    geography();
    biology();
    physics();
}
void Display_Book() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    while (true) {
        int i, n = 1;
        for (i = 0; i < arr[num - 1]; i++) {
            cout << n << ":" << arrcat[num - 1].arrbook[i].name << endl;
            n++;
        }
        cout << n << ": BACK\n";
        cin >> s2;
        bool check = true;
        for (char c : s2) {
            if (!isdigit(c)) {
                check = false;
                break;
            }
        }
        if (check) {
            num2 = stoi(s2);
            if (num2 < n) {
                if (arrcat[num - 1].arrbook[num2 - 1].counter < 3) {
                    cout << "YOU CANT EDIT IT NOW AS ITS COPIES ARE BORROWED\n";
                    cout << "---------------------------------------------------\n";
                    continue;
                }
                else {
                    Edit_Books();
                    break;
                }
            }

            else if (num2 == n) {
                Display_Cat();
                break;
            }
        }
        else {
            cout << "INVALID CHOICE\n";
            continue;
        }
    }
}
void Display_Cat() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 13);
    int i;
    while (true) {
        cout << "-------------------------------------------------------\n";
        cout << "|ENTER THE CATEGORY OF THE BOOK YOU WANT TO EDIT IN :|\n";
        cout << "-------------------------------------------------------\n";
        for (i = 0; i < 5; i++) {
            cout << "\t" << i + 1 << ") " << arrcat[i].caty << endl;
        }
        cout << "\t" << i + 1 << ") BACK" << endl;
        cin >> s1;
        if (s1 == "1" || s1 == "2" || s1 == "3" || s1 == "4" || s1 == "5") {
            num = stoi(s1);
            Display_Book();
            break;
        }
        else if (s1 == "6") {
            admin_list();
            break;
        }
        else {
            cout << "INVALID CHOICE" << endl;
            continue;
        }
    }
}
void Edit_Books() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 12);
    string X, r, m;
    bool test = 1;
    while (true) {
        cout << "------------------------------------\n";
        cout << "|      CHOOSE YOUR OPTION:         |\n";
        cout << "|----------------------------------|\n";
        cout << "|    1-EDIT BOOK'S NAME.           |\n";
        cout << "|    2-EDIT BOOK'S ID.             |\n";
        cout << "|    3-EDIT BOOK'S WRITER NAME.    |\n";
        cout << "|    4-EDIT BOOK'S EDITION.        |\n";
        cout << "|    5-BACK.                       |\n";
        cout << "------------------------------------\n";
        cout << "\tYOUR CHOICE:) : ";
        cin >> X;
        if (X == "1") {
            cout << "ENTER THE BOOK'S NAME : ";
            cin.ignore();
            getline(cin, r);
            while (true) {
                cout << "ARE YOU SURE YOU WANT TO EDIT IT ?(y/n)\n";
                cin >> m;
                if (m == "y" || m == "Y") {
                    arrcat[num - 1].arrbook[num2 - 1].name = r;
                    copy();
                    cout << "\t-----------------------------------------\n";
                    cout << "\t|THE BOOK HAS BEEN EDITED SUCCESSFULLY:)|\n";
                    cout << "\t-----------------------------------------\n";
                    admin_list();
                    break;
                }
                if (m == "n" || m == "N") {
                    test = 0;
                    break;
                }
                else {
                    cout << "INVALID CHOICE\n";
                    continue;
                }
            }
            if (test == 1) {
                break;
            }
            else {
                continue;
            }
        }
        else if (X == "2") {
            cout << "ENTER THE BOOK'S ID : ";
            cin.ignore();
            getline(cin, r);
            while (true) {
                cout << "ARE YOU SURE YOU WANT TO EDIT IT ?(y/n)\n";
                cin >> m;
                if (m == "y" || m == "Y") {
                    arrcat[num - 1].arrbook[num2 - 1].id = r;
                    copy();
                    cout << "\t-----------------------------------------\n";
                    cout << "\t|THE BOOK HAS BEEN EDITED SUCCESSFULLY:)|\n";
                    cout << "\t-----------------------------------------\n";
                    admin_list();
                    break;
                }
                if (m == "n" || m == "N") {
                    test = 0;
                    break;
                }
                else {
                    cout << "INVALID CHOICE\n";
                    continue;
                }
            }
            if (test == 1) {
                break;
            }
            else {
                continue;
            }
        }
        else if (X == "3") {
            cout << "ENTER THE BOOK'S WRITER NAME : ";
            cin.ignore();
            getline(cin, r);
            while (true) {
                cout << "ARE YOU SURE YOU WANT TO EDIT IT ?(y/n)\n";
                cin >> m;
                if (m == "y" || m == "Y") {
                    arrcat[num - 1].arrbook[num2 - 1].writer = r;
                    copy();
                    cout << "\t-----------------------------------------\n";
                    cout << "\t|THE BOOK HAS BEEN EDITED SUCCESSFULLY:)|\n";
                    cout << "\t-----------------------------------------\n";
                    admin_list();
                    break;
                }
                if (m == "n" || m == "N") {
                    test = 0;
                    break;
                }
                else {
                    cout << "INVALID CHOICE\n";
                    continue;
                }
            }
            if (test == 1) {
                break;
            }
            else {
                continue;
            }
        }
        else if (X == "4") {
            cout << "ENTER THE BOOK'S EDITION : ";
            cin.ignore();
            getline(cin, r);
            while (true) {
                cout << "ARE YOU SURE YOU WANT TO EDIT IT ?(y/n)\n";
                cin >> m;
                if (m == "y" || m == "Y") {
                    arrcat[num - 1].arrbook[num2 - 1].edition = r;
                    copy();
                    cout << "\t-----------------------------------------\n";
                    cout << "\t|THE BOOK HAS BEEN EDITED SUCCESSFULLY:)|\n";
                    cout << "\t-----------------------------------------\n";
                    admin_list();
                    break;
                }
                if (m == "n" || m == "N") {
                    test = 0;
                    break;
                }
                else {
                    cout << "INVALID CHOICE\n";
                    continue;
                }
            }
            if (test == 1) {
                break;
            }
            else {
                continue;
            }
        }
        else if (X == "5") {
            admin_list();
            break;
        }
        else {
            cout << "INVALID CHOICE\n";
            continue;
        }
    }
}
void idofbook() {
    ifstream data1;
    data1.open("b.txt", ios::in);
    for (int i = 0; i < co; i++) {
        for (int l = 0; l < 3; l++) {
            getline(data1, arracc[i].borr[l]);
        }

    }
    data1.close();
}
void heart() {
    int size = 10, h, b;
    for (h = size / 2; h <= size; h = h + 2) {
        cout << "\t\t\t\t\t\t\t\t";
        for (b = 1; b < size - h; b = b + 2)
            cout << " ";
        for (b = 1; b <= h; b++)
            cout << "#";
        for (b = 1; b <= size - h; b++)
            cout << " ";
        for (b = 1; b <= h - 1; b++)
            cout << "#";
        cout << endl;
    }for (h = size; h >= 0; h--) {
        cout << "\t\t\t\t\t\t\t\t";
        for (b = h; b < size; b++)
            cout << " ";
        for (b = 1; b <= ((h * 2) - 1); b++)
            cout << "#";
        cout << endl;
    }
}
void view_my_books()
{
    int n = 1;
    if (arracc[index].cun == 0) {
        bool back = 0;
        cout << "\t-------------------------------------------\n";
        cout << "\t|    YOU HAVE NOT BORROW ANY BOOKS YET    |\n";
        cout << "\t-------------------------------------------\n";
    }
    else
    {
        cout << "---------------------------------------------------------------------------------------------------------------\n";
        cout << left << setw(52) << "NAME" << left << setw(20) << "CATEGORY" << left << setw(8) << "ID" << left << setw(10) << "EDITION" << left << setw(30) << "WRITER" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------\n";

        for (int i = 0; i < 3; i++) {
            bool a = 0;
            for (int j = 0; j < 5; j++) {
                if (a == 1)
                    break;
                for (int k = 0; k < arr[j]; k++) {
                    if (arracc[index].borr[i] == arrcat[j].arrbook[k].id) {
                        cout << n << "-" << left << setw(50) << arrcat[j].arrbook[k].name
                            << left << setw(20) << arrcat[j].caty
                            << left << setw(8) << arrcat[j].arrbook[k].id
                            << left << setw(10) << arrcat[j].arrbook[k].edition
                            << left << setw(30) << arrcat[j].arrbook[k].writer
                            << endl;
                        cout << "---------------------------------------------------------------------------------------------------------------\n";
                        n++;
                        a = 1;
                        break;
                    }
                }
            }
        }

    }
    cout << n << "-BACK\n";
    while (true) {
        int t;
        string s3;
        cin >> s3;
        bool check = true;
        for (char c : s3) {
            if (!isdigit(c)) {
                check = false;
                break;
            }

        }
        if (check) {
            t = stoi(s3);
            if (t == n) {
                student_list();
                break;
            }
            else
            {
                cout << "INVALID CHOICE\n";
                continue;
            }
        }
        else
        {
            cout << "INVALID CHOICE\n";
            continue;
        }

    }
}
int indexx(string id) {
    for (int i = 0; i < co; i++) {
        if (arracc[i].id == id) {
            indeex = i;
            break;
        }
    }
    return indeex;
}
void forget(string ids) {
    bool exist = 0;
    for (int i = 0; i < co; i++) {
        if (ids == arracc[i].id) {
            exist = 1;
            break;
        }
    }
    if (exist == 0) {
        bool exist2 = 0;
        while (true) {
            cout << "THIS ID IS WRONG OR IS NOT EXIST \n";
            cout << "ENTER ANOTHR  ID :";
            string id, w;
            cin >> id;
            for (int i = 0; i < co; i++) {
                if (id == arracc[i].id) {
                    exist2 = 1;
                    int in = indexx(id);
                    while (true) {
                        cout << "\t\t\t--------------------------------------\t\t\n";
                        cout << "\t\t\t|   CHOOSE YOUR SECURITY QUESTION :  |\t\t\n";
                        cout << "\t\t\t|------------------------------------|\t\t\n";
                        cout << "\t\t\t|1- WHAT CITY WERE YOU BORN IN?      |\n";
                        cout << "\t\t\t|2- WHAT IS YOUR HOBBY?              |\n";
                        cout << "\t\t\t|3- WHAT IS YOUR NICKNAME?           |\n";
                        cout << "\t\t\t|4- WHAT IS YOUR FAVORITE FOOD?      |\n";
                        cout << "\t\t\t|5- WHO IS YOUR SUPER HERO?          |\n";
                        cout << "\t\t\t|6- BACK                             |\n";
                        cout << "\t\t\t--------------------------------------\t\t\n";
                        cout << "\t\tYOUR QUESTION : ";
                        string ques;
                        bool test4 = 0;
                        cin >> ques;
                        if (ques == "6") {
                            menu();
                            break;
                        }
                        else if (ques != "1" && ques != "2" && ques != "3" && ques != "4" && ques != "5" && ques != "6") {
                            cout << "INVALID CHOICE\n";
                            continue;
                        }
                        while (true) {
                            cout << "\t1-ENTER YOUR ANSWER\n";
                            cout << "\t2-BACK\n";
                            cin >> w;
                            if (w == "1") {
                                break;
                            }
                            else if (w == "2") {
                                test4 = 1;
                                break;
                            }
                            else {
                                cout << "INVALID CHOICE\n";
                                continue;
                            }
                        }
                        if (test4 == 1) {
                            continue;
                        }
                        cout << "ANSWER: ";
                        string ans;
                        cin.ignore();
                        getline(cin, ans);
                        if (arracc[in].que_number == ques && arracc[in].que_ans == ans) {
                            string npas = hidden_password2();
                            arracc[in].password = npas;
                            file_writing();
                            menu();
                            break;
                        }
                        else
                        {
                            cout << "\tYOU HAVE PICKED WRONG QUESTION OR YOUR ANSWER IS WRONG :( \n ";
                            cout << "\tPLEASE RECHOOSE IT:)\n";
                            cout << "\t------------------------------------------------------------\n";
                            continue;
                        }
                    }
                    break;
                }
            }
            if (exist2)
                break;
        }
    }
    else {
        int in = indexx(ids);
        while (true) {
            cout << "\t\t\t--------------------------------------\t\t\n";
            cout << "\t\t\t|   CHOOSE YOUR SECURITY QUESTION :  |\t\t\n";
            cout << "\t\t\t|------------------------------------|\t\t\n";
            cout << "\t\t\t|1- WHAT CITY WERE YOU BORN IN?      |\n";
            cout << "\t\t\t|2- WHAT IS YOUR HOBBY?              |\n";
            cout << "\t\t\t|3- WHAT IS YOUR NICKNAME?           |\n";
            cout << "\t\t\t|4- WHAT IS YOUR FAVORITE FOOD?      |\n";
            cout << "\t\t\t|5- WHO IS YOUR SUPER HERO?          |\n";
            cout << "\t\t\t|6- BACK                             |\n";
            cout << "\t\t\t--------------------------------------\t\t\n";
            bool test4 = 0;
            cout << "\t\tYOUR QUESTION : ";
            string ques, w;
            cin >> ques;
            if (ques == "6") {
                menu();
                break;
            }
            else if (ques != "1" && ques != "2" && ques != "3" && ques != "4" && ques != "5" && ques != "6") {
                cout << "INVALID CHOICE\n";
                continue;
            }
            while (true) {
                cout << "\t1-ENTER YOUR ANSWER\n";
                cout << "\t2-BACK\n";
                cin >> w;
                if (w == "1") {
                    break;
                }
                else if (w == "2") {
                    test4 = 1;
                    break;
                }
                else {
                    cout << "INVALID CHOICE\n";
                    continue;
                }
            }
            if (test4 == 1) {
                continue;
            }
            cout << "ANSWER: ";
            string ans;
            cin.ignore();
            getline(cin, ans);
            if (arracc[in].que_number == ques && arracc[in].que_ans == ans) {
                string npas;
                npas = hidden_password2();
                arracc[in].password = npas;
                file_writing();
                menu();
                break;
            }
            else
            {
                cout << "\tYOU HAVE PICKED WRONG QUESTION OR YOUR ANSWER IS WRONG :( \n ";
                cout << "\tPLEASE RECHOOSE IT:)\n";
                cout << "\t------------------------------------------------------------\n";
                continue;
            }
        }

    }
}
string hidden_password2() {
    while (true) {
        cout << "NEW PASSWORD (atleast 8 char): ";
        string password = "";
        char ch;
        while (true) {
            ch = _getch();
            if (ch == '\r') {
                break;
            }
            if (ch == '\b') {
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                }
            }
            else {
                password.push_back(ch);
                cout << "*";
            }
        }
        cout << endl;
        if (password.size() >= 8) {
            return password;
            break;
        }
        else
        {
            cout << "YOUR PASSWORD IS LESS THAN 8 CHARECTERS\n";
            cout << "------------------------------------------\n";
            continue;
        }
    }
}