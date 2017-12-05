//
//  KeyValueEntity.cpp
//  kurs
//
//  Created by Денис Скоробогатов on 03.12.17.
//  Copyright © 2017 Denis Skorobogatov. All rights reserved.
//

#include "KeyValueEntity.hpp"
#include <iostream>

KeyValueEntity::KeyValueEntity(std::string name)
{
    if (name.length() == 0)
        throw std::invalid_argument("Name cannot be empty");
    this->key = name;

}

void KeyValueEntity::AddValue(int a)
{
    this->values.push_back(a);
}

std::string KeyValueEntity::GetKey() const
{
    return this->key;
}

std::vector<int> KeyValueEntity::GetValues() const
{
    return this->values;
}
