#include <iostream>
#include <fstream>

using namespace std;



int main(){
    string file_name = ""; // имя файла
    string code_string = ""; // строка кода            

    long long int input_command = 0; // ввод номера команды
    long long int compare_command = 0; // команда для сравнения из кода языка

    cout << "Hello from ricon!" << endl; // ввод имени файла
    cout << "Input file name: ";
    cin >> file_name;

    ifstream fin(file_name); // организуем считывание из файла кода
    ofstream fout; // поток для записи в файл с++
    fout.open("code.cpp"); // выходой файл      
    
    getline(fin, code_string); // берем строку из файла кода     

    if (code_string == "#start"){ // определяем есть ли флаг начала кода
        while (code_string != "#end"){
            getline(fin, code_string);                        
            if (code_string == "out"){ // вывод без переноса строки в консоль
                getline(fin, code_string);
                cout <<  code_string;
            }
            else if (code_string == "outl"){ // вывод с переносом строки в консоль
                getline(fin, code_string);
                cout << code_string << endl;
            }
            else if (code_string == "in"){ // ввод команды
                cin >> input_command;
            }
            else if (code_string == "#if_command"){ // определение начала сравнения команды введенной из консоли с командой, предложенной из кода программы
                getline(fin, code_string); // берем команду из кода программы
                compare_command = stoi(code_string);
                if (input_command == compare_command){
                    getline(fin, code_string);                        
                if (code_string == "out"){ // вывод без переноса строки в консоль
                    getline(fin, code_string);
                    cout <<  code_string;
                }
                else if (code_string == "outl"){ // вывод с переносом строки в консоль
                    getline(fin, code_string);
                    cout << code_string << endl;
                }
                else if (code_string == "in"){ // ввод команды
                    cin >> input_command;
                }
                else if (code_string == "end_command"){
                    continue;   
                }
            }

            }            
        }
    }
    
    fin.close();
    fout.close(); 
    return 0;
}