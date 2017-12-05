//
//  KeyValueEntity.hpp
//  kurs
//
//  Created by Денис Скоробогатов on 03.12.17.
//  Copyright © 2017 Denis Skorobogatov. All rights reserved.
//

#ifndef KeyValueEntity_hpp
#define KeyValueEntity_hpp

#include <vector>
#include <string>

class KeyValueEntity
{
public:
    KeyValueEntity(std::string);
    void AddValue(int);
    std::string GetKey() const;
    std::vector<int> GetValues() const;
private:
    std::string key;
    std::vector<int> values;
};

#endif /* KeyValueEntity_hpp */
