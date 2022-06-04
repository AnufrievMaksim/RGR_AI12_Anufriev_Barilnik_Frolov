
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;
int main()
{
    setlocale(LC_ALL, R"(Russian)");
    string  parol = "NSTUAI12";
    string vvod;
    cout << "Введите пароль\n";
    cin >> vvod;
    if (vvod == parol) {
       
    }
    else {
        return 0;
    }
    cout << "Введите тип шифра\n";
    cout << "1 - шифр Цезаря\n";
    cout << "2 - шифр Атбаш\n";
    cout << "3 - шифр с кодовым словом\n";
    int tip = 0;
    cin >> tip;



    if (tip == 1) {
        // цезарь
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        int k;  //k - сдвиг
        char ABC[] = { 'А','Б','В','Г','Д','Е','Ж','З','И',
                    'Й','К','Л','М','Н','О','П','Р','С',
                    'Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ',
                    'Ы','Ь','Э','Ю','Я','_','.',',','0',
                    '1','2','3','4','5','6','7','8','9' };
        char message[80];
        cout << "Введите сообщение, которое будет закодировано:\n" << endl;
        cin >>message;
        cout << "Введите сдвиг:\n" << endl;
        cin >> k;
        cout << endl;
        char* begin = ABC;    //*указатель
        char* end = ABC + sizeof(ABC);  //возращает размер в байтах
        for (int i = 0; message[i]; ++i)
        {
            char* dlina = find(begin, end, message[i]);  //begin первый, end последний, сравниваются с message
            if (dlina != end) message[i] = *(begin + (dlina - begin + k) % sizeof(ABC)); //по формуле шифра цезаря y = x + k%n
        }
        cout << "Полученное закодированное сообщение:\n" << endl;
        cout << message << endl;
        return 0;
    }




    if (tip == 2) {
        //атбаш
       void cipherEncryption();
       void cipherDecryption();
            setlocale(LC_ALL, "Russian");
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
            int choice;
            cout << "1. Шифрование\n2. Дешифрование\nВыбери 1 или 2: ";
            cin >> choice;
            cin.ignore(); //функция, которая считывает символ и игнорирует его

            if (choice == 1) {
                cout << "Шифрование" << endl;
                cipherEncryption();
            }
            else if (choice == 2) {
                cout << "Дешифрование" << endl;
                cipherDecryption();
            }
            else {
                cout << "Выберите 1 или 2" << endl;
            }
            return 0;
    }





    if (tip == 3) {
        //слово
       
        cout << "Отсутствует";

        return 0;
    }
}





void cipherEncryption() {
    setlocale(LC_ALL, "Russian");
    string message;
    cout << "Введите сообщение: ";
    getline(cin, message); //Функция getline предназначена для ввода данных из потока, например, для ввода данных из консольного окна

    for (int i = 0; i < message.length(); i++) {
        message[i] = toupper(message[i]);
    }

    string alpa = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string reverseAlpa = ""; // изменение строкиили полное переворачивание строки означает изменение порядка символов в ней, так что она читается назад.
    for (int i = alpa.length() - 1; i > -1; i--) {
        reverseAlpa += alpa[i];
    }

    string encryText = "";
    for (int i = 0; i < message.length(); i++) {

        for (int j = 0; j < alpa.length(); j++) {
            if (message[i] == alpa[j]) {
                encryText += reverseAlpa[j];
                break;
            }
        }
    }
    cout << encryText;
}

void cipherDecryption() {

    string message;
    cout << "Введите зашифрованное сообщение: ";
    getline(cin, message);

    for (int i = 0; i < message.length(); i++) {
        message[i] = toupper(message[i]);
    }

    string alpa = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string reverseAlpa = "";
    for (int i = alpa.length() - 1; i > -1; i--) {
        reverseAlpa += alpa[i];
    }

    string dencryText = "";
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == 32) {
            dencryText += " ";
        }
        else {
            for (int j = 0; j < reverseAlpa.length(); j++) {
                if (message[i] == reverseAlpa[j]) {
                    dencryText += alpa[j];
                    break;
                }
            }
        }
    }

    cout << "Дешифрованное сообщение: " << dencryText;
}



