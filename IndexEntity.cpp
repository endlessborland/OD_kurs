//
//  IndexEntity.cpp
//  kurs
//
//  Created by Денис Скоробогатов on 03.12.17.
//  Copyright © 2017 Denis Skorobogatov. All rights reserved.
//

#include "IndexEntity.hpp"
#include <iostream>

IndexEntity::IndexEntity()
{
    
}

// utility function, not a class member
bool compare(const KeyValueEntity &a, const KeyValueEntity &b)
{
    if (a.GetKey() < b.GetKey())
        return true;
    else
        return false;
}

// sort elements with std::sort
void IndexEntity::sortElements()
{
    std::sort(this->elements.begin(), this->elements.end(), &compare);
}


// returns the number of elemetns in the index
int IndexEntity::GetSize() const
{
    return (int)this->elements.size();
}

// returns the Key by its id
std::string IndexEntity::GetKeyById(int i) const
{
    return elements[i].GetKey();
}

// prints data to file
// @name - path to file, full file name
void IndexEntity::PrintAllToFile(std::ofstream* ftemp)
{
    sortElements();
    std::vector<int> temp;
    for (int i = 0; i < this->elements.size(); i++)
    {
        *ftemp << "{" <<this->elements[i].GetKey();
        temp = elements[i].GetValues();
        if (temp.size() == 0)
        {
            *ftemp << "}" << std::endl;
            continue;
        }
        *ftemp << ", ";
        for (int j = 0; j < temp.size(); j++)
        {
            *ftemp << temp[j];
            if (j + 1 == temp.size())
                *ftemp << "}";
            else
                *ftemp << ", ";
            
        }
        *ftemp << std::endl;
    }
    ftemp->close();
}

// adds key-value entity to the index
// @name - key of the element
void IndexEntity::AddKeyValueEntity(std::string name)
{
    this->elements.push_back(*new KeyValueEntity(name));
}

// prints all the index data on the console
void IndexEntity::PrintAllToScreen()
{
    sortElements();
    std::vector<int> temp;
    for (int i = 0; i < this->elements.size(); i++)
    {
        std::cout << "{" <<this->elements[i].GetKey();
        temp = elements[i].GetValues();
        if (temp.size() == 0)
        {
            std::cout << "}" << std::endl;
            continue;
        }
        std::cout << ", ";
        for (int j = 0; j < temp.size(); j++)
        {
            std::cout << temp[j];
            if (j + 1 == temp.size())
                std::cout << "}";
            else
                std::cout << ", ";
                
        }
        std::cout << std::endl;
    }
}

// adds value @a to key @name
// throws exception if term isn't found
// uses SearchForKey(std::string)
void IndexEntity::AddValueToKey(std::string name, int a)
{
    KeyValueEntity* temp = this->SearchForKey(name);
    if (temp != NULL)
        temp->AddValue(a);
    else
        throw "No such term in the index";
}

// searches for key @name
// returns pointer to element if is found
// returns NULL if @name key does not exist
KeyValueEntity* IndexEntity::SearchForKey(std::string name)
{
    for (int i = 0; i < this->elements.size(); i++)
    {
        if (this->elements[i].GetKey() == name)
            return &this->elements[i];
    }
    return NULL;
}

// returns a pointer to an element by Id
KeyValueEntity* IndexEntity::GetElementById(int i)
{
    return &this->elements[i];
}
