#include <iostream>
#include <fstream>
#include "TomaString.h"

using namespace std;

bool getTextFromFile(TomaString &str);
void printIntro();
void createProtocol(TomaString str);
void createResult(TomaString str);

int main() {

    TomaString str, subStr;

    if (getTextFromFile(str)) {
        createProtocol(str);
        printIntro();
        cin >> subStr;

        int i = 0;
        while (str.search(subStr) != -1) {
            str.deleteSubStr(subStr);
            i++;
        }

        if (!i) {
            cout << "Введенная подстрока не найдена, файл с результатом не может быть создан" << endl;
        } else {
            cout << "Количество вхождений подстроки: " << i <<". Новый текст помещен в файл Result.txt" << endl;
            createResult(str);
        }
    }
    return 0;
}

bool getTextFromFile(TomaString &str) {
    ifstream fin("Seashells.txt", ios::in | ios::binary);
    if (!fin) {
        cout << "Ошибка открытия файла";
        return false;
    } else {
        char ch;
        int i = 0;
        while (!fin.eof() && i < N) {
            fin.get(ch);
            if (!fin.eof() && ch != 13) {
                str.append(ch);
                i++;
            }
        }
        fin.close();
        return true;
    }
}

void printIntro() {
    cout << "Добро пожаловать!" << endl;
    cout << "Я программа, которая умеет удалять из текста заданную Вами подстроку" << endl;
    cout << "Вся работа со мной будет происходить через файлы" << endl;
    cout << "Вы уже загрузили в меня файл (иначе вы бы не читали это сообщение)" << endl;
    cout << "Кстати, в корневой папке проекта уже лежит файл с протоколом=)" << endl;
    cout << "Результат моей работы будет лежать там же" << endl;
    cout << endl;
    cout << "Что мы сейчас будет делать : " << endl;
    cout << "Вы введете в меня подстроку (на английском и без пробелов)" << endl;
    cout << "Я удалю из загруженного текста эту подстроку и сформирую файл с результатом" << endl;
    cout << "Погнали! Введите подстроку: " << endl;
}

void createProtocol(TomaString str) {
    ofstream fout("Protocol.txt");
    if (!fout) {
        cout << "Ошибка открытия файла";
    } else {
        fout << str;
        fout.close();
    }
}

void createResult(TomaString str) {
    ofstream fout("Result.txt");
    if (!fout) {
        cout << "Ошибка открытия файла";
    } else {
        fout << str;
        fout.close();
    }
}

