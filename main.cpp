//
//  main.cpp
//  kurs
//
//  Created by Денис Скоробогатов on 03.12.17.
//  Copyright © 2017 Denis Skorobogatov. All rights reserved.
//

/* «Предметный указатель»
 Предметный указатель – это алфавитный список терминов докумен-
 та с указанием страниц, на которых они упоминаются. Пример элемента
 указателя: {[заголовочный файл], 108, 189, 927}.
 Операции указателя:
 • создание пустого предметного указателя;
 • добавление термина в предметный указатель;
 • редактирование элемента предметного указателя (добавление ссыл-
 ки на страницу для заданного термина);
 • вывод элементов указателя в алфавитном порядке на экран;
 • вывод элементов указателя в алфавитном порядке в текстовый файл;
 • поиск элемента предметного указателя по термину.
 
 В демонстрационной программе предусмотреть ввод списка терми-
 нов с клавиатуры, считывание текста, для которого создается предметный
 указатель, из текстового файла и запись предметного указателя в другой
 текстовый файл перед завершением работы программы. Количество строк
 на странице текста можно задать глобальной константой или вводить с
 клавиатуры. В текстовом файле нет переноса слов.
 */

#include "IndexEntity.hpp"
#include <iostream>
#include <string>

using namespace std;

// lines per page
const int n = 30;

string readLine();

int main(int argc, const char * argv[]) {
    std::ifstream infile;
    std::ofstream ofile;
    string input;
    int i;
    
    cout << "Insert the terms, divide them using the enter key and finish by an empty line" << endl;
    IndexEntity *index = new IndexEntity();
    // scanning all terms
    while(true)
    {
        try {
            input = readLine();
            index->AddKeyValueEntity(input);
            continue;
        } catch (const std::invalid_argument& e) {
            if (index->GetSize() == 0)
            {
                cout << "Enter at least one word" << endl;
                continue;
            }
            break;
        }
    }
    // scanning the file path
    while(true)
    {
        cout << "Insert a path to file" << endl;
        input = readLine();
        infile = std::ifstream(input, std::ifstream::in);
        if (!infile.is_open())
        {
            cout << "Cannot access the file" << endl;
            continue;
        }
        break;
    }
    i = 0;
    // forming an index
    while(std::getline(infile, input))
    {
        i++;
        for (int j = 0; j < index->GetSize(); j++)
        {
            KeyValueEntity* key = index->GetElementById(j);
            vector<int> temp = key->GetValues();
            int size = (int)temp.size();
            if (size > 0)
            {
                if (temp[size-1] == i / n + 1)
                    continue;
            }
            size_t pos = input.find(key->GetKey());
            if (pos != std::string::npos)
                key->AddValue(i/n + 1);
        }
    }
    index->PrintAllToScreen();
    // reading a filepath
    while(true)
    {
        cout << "Insert a path to output file" << endl;
        input = readLine();
        ofile = std::ofstream(input, std::ifstream::out);
        if (!ofile.is_open())
        {
            cout << "Cannot access the file" << endl;
            continue;
        }
        break;
    }
    index->PrintAllToFile(&ofile);
}

// reading a line in string
std::string readLine()
{
    std::string a;
    std::getline(std::cin, a);
    return a;
    
}
