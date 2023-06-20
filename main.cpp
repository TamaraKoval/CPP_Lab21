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
            cout << "��������� �����ப� �� �������, 䠩� � १���⮬ �� ����� ���� ᮧ���" << endl;
        } else {
            cout << "������⢮ �宦����� �����ப�: " << i <<". ���� ⥪�� ����饭 � 䠩� Result.txt" << endl;
            createResult(str);
        }
    }
    return 0;
}

bool getTextFromFile(TomaString &str) {
    ifstream fin("Seashells.txt", ios::in | ios::binary);
    if (!fin) {
        cout << "�訡�� ������ 䠩��";
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
    cout << "���� ����������!" << endl;
    cout << "� �ணࠬ��, ����� 㬥�� 㤠���� �� ⥪�� �������� ���� �����ப�" << endl;
    cout << "��� ࠡ�� � ���� �㤥� �ந�室��� �१ 䠩��" << endl;
    cout << "�� 㦥 ����㧨�� � ���� 䠩� (���� �� �� �� �⠫� �� ᮮ�饭��)" << endl;
    cout << "����, � ��୥��� ����� �஥�� 㦥 ����� 䠩� � ��⮪����=)" << endl;
    cout << "������� ���� ࠡ��� �㤥� ������ ⠬ ��" << endl;
    cout << endl;
    cout << "�� �� ᥩ�� �㤥� ������ : " << endl;
    cout << "�� ������ � ���� �����ப� (�� ������᪮� � ��� �஡����)" << endl;
    cout << "� 㤠�� �� ����㦥����� ⥪�� ��� �����ப� � ��ନ��� 䠩� � १���⮬" << endl;
    cout << "�������! ������ �����ப�: " << endl;
}

void createProtocol(TomaString str) {
    ofstream fout("Protocol.txt");
    if (!fout) {
        cout << "�訡�� ������ 䠩��";
    } else {
        fout << str;
        fout.close();
    }
}

void createResult(TomaString str) {
    ofstream fout("Result.txt");
    if (!fout) {
        cout << "�訡�� ������ 䠩��";
    } else {
        fout << str;
        fout.close();
    }
}

