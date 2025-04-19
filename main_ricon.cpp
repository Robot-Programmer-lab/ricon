#include <iostream>
#include <fstream>
#include "formator.h"

using namespace std;

int main(){
    string file_name = ""; // имя файла
    string code_string = ""; // строка кода        

    cout << "Hello from ricon!" << endl; // ввод имени файла
    cout << "Input file name: ";
    cin >> file_name;

    ifstream fin(file_name); // организуем считывание из файла кода
    ofstream fout; // поток для записи в файл с++
    fout.open("code.cpp"); // выходой файл      
    
    getline(fin, code_string); // берем строку из файла кода

    if (code_string == "#start"){ // определяем есть ли флаг начала кода
        while (code_string != "#end"){        
            getline(fin, code_string); // берем строку из файла кода    
            formator(code_string);            
        }
    }
    
    fin.close();
    fout.close(); 
    return 0;
}