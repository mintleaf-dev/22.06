// РОБОТА З ФАЙЛАМИ
// ================

// №1

// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// struct Customers{
//     string nameSurname;
//     string phoneNumber;
// };

// void fillStruct(Customers& customer, ofstream& file);
// Customers* readFile(int& size, const string& filename);
// void allCustomers(Customers* customers, int size);
// void specificCustomer(Customers* customers, int size, const string& name);

// int main(){
//     Customers customer;
//     char answer;
//     ofstream file("db.txt", ios::app);
//     if (!file) {
//         cout << "Файл не існує ;)" << endl;
//         return 1;
//     }

//     do{
//         fillStruct(customer, file);
//         cout << "Чи бажаєте ввести ще одного клієнта? (Введіть '-' для завершення): ";
//         cin >> answer;
//         cin.ignore();
//     } while(answer != '-');
//     file.close();

//     string userChoice;
//     do{
//         int size = 0;
//         Customers* customers = readFile(size, "db.txt");

//         int choice;
//         cout << "Введіть 1, щоб відобразити всіх клієнтів, 2, щоб знайти певного клієнта: ";
//         cin >> choice;
//         cin.ignore();

//         if (choice == 1){
//             allCustomers(customers, size);
//         } else if (choice == 2) {
//             string searchName;
//             cout << "Введіть ім'я та прізвище для пошуку: ";
//             getline(cin, searchName);
//             specificCustomer(customers, size, searchName);
//         } else 
//             cout << "Невірний вибір" << endl;

//         cout << "Бажаєте виконати ще дію? (Введіть 'yes', щоб продовжити): ";
//         getline(cin, userChoice);
//         delete[] customers;
//     } while(userChoice == "yes");
//     return 0;
// }

// void fillStruct(Customers& customer, ofstream& file) {
//     cout << "Введіть ім'я та прізвище: ";
//     cin.ignore();
//     getline(cin, customer.nameSurname);

//     cout << "Введіть номер телефону: ";
//     getline(cin, customer.phoneNumber);

//     file << customer.nameSurname << " " << customer.phoneNumber << endl;
// }

// Customers* readFile(int &size, const string &filename) {
//     ifstream file(filename);
//     if (!file) {
//         cout << "Файл не вдалося відкрити" << endl;
//         return nullptr;
//     }

//     string row;
//     size = 0;
//     while (getline(file, row)) {
//         ++size;
//     }
//     file.clear();
//     file.seekg(0, ios::beg);

//     Customers* customers = new Customers[size];

//     for (int i = 0; i < size; ++i) {
//         file >> ws;
//         getline(file, customers[i].nameSurname, ' ');
//         getline(file, customers[i].phoneNumber);
//     }
//     file.close();
//     return customers;
// }

// void allCustomers(Customers* customers, int size) {
//     for (int i = 0; i < size; ++i)
//         cout << "Ім'я: " << customers[i].nameSurname << ", Номер телефону: " << customers[i].phoneNumber << endl;
// }

// void specificCustomer(Customers* customers, int size, const string &name) {
//     for (int i = 0; i < size; ++i) {
//         if (customers[i].nameSurname == name) {
//             cout << "Ім'я: " << customers[i].nameSurname << ", Номер телефону: " << customers[i].phoneNumber << endl;
//             return;
//         }
//     }
//     cout << "Клієнт не знайдений" << endl;
// }

// №2

// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// int main(){
//     string inputFileName = "input.txt";
//     string outputFileName = "output.txt";

//     ifstream inputFile(inputFileName);
//     if (!inputFile.is_open()) {
//         cerr << "Не вдалося відкрити файл для читання: " << inputFileName << endl;
//         return 1;
//     }
//     ofstream outputFile(outputFileName);
//     if (!outputFile.is_open()) {
//         cerr << "Не вдалося відкрити файл для запису: " << outputFileName << endl;
//         return 1;
//     }
//     string row;
//     while (getline(inputFile, row)) 
//         outputFile << row << endl;
//     inputFile.close();
//     outputFile.close();

//     cout << "Рядки успішно переписані з " << inputFileName << " у " << outputFileName << endl;
//     return 0;
// }

// №3

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(){
//     string inputFileName = "input.txt";
//     string outputFileName = "output.txt";

//     ifstream inputFile(inputFileName);
//     if (!inputFile.is_open()){
//         cerr << "Не вдалося відкрити файл для читання: " << inputFileName << endl;
//         return 1;
//     }
//     vector<string> rows;
//     string row;
//     while (getline(inputFile, row)) {
//         rows
//       .push_back(row);
//     }
//     ofstream outputFile(outputFileName);
//     if (!outputFile.is_open()) {
//         cerr << "Не вдалося відкрити файл для запису: " << outputFileName << endl;
//         return 1;
//     }
//     for (auto it = rows
//   .rbegin(); it != rows
//   .rend(); ++it) 
//         outputFile << *it << endl;
//     inputFile.close();
//     outputFile.close();

//     cout << "Рядки успішно переписані у зворотньому порядку з " << inputFileName << " у " << outputFileName << endl;
//     return 0;

// }

// №4

// #include <iostream>
// #include <fstream>
// using namespace std;

// void addLine(fstream&file, const string&rowAdd){
//     string lastLine;
//     streamoff lastLinePos = 0;

//     while (getline(file, lastLine)) {
//         if (lastLine.find_first_not_of(" \t") != string::npos) 
//             lastLinePos = file.tellg();
//     }
//     file.clear();
//     file.seekp(lastLinePos);
//     file << rowAdd << endl;
// }


// int main(){
//     fstream file("file.txt", ios::in | ios::out);

//     if (!file){
//         cerr << "Не вдалося відкрити файл" << endl;
//         return 1;
//     }
//     string rowAdd = "------------";
//     addLine(file, rowAdd);
//     file.close();
//     return 0;
// }