//
//  IndexEntity.hpp
//  kurs
//
//  Created by Денис Скоробогатов on 03.12.17.
//  Copyright © 2017 Denis Skorobogatov. All rights reserved.
//

#ifndef IndexEntity_hpp
#define IndexEntity_hpp

#include <vector>
#include <fstream>
#include "KeyValueEntity.hpp"

class IndexEntity
{
public:
    IndexEntity();
    void AddKeyValueEntity(std::string);
    void AddValueToKey(std::string, int);
    void PrintAllToScreen();
    void PrintAllToFile(std::ofstream*);
    KeyValueEntity* SearchForKey(std::string);
    int GetSize() const;
    std::string GetKeyById(int) const;
    KeyValueEntity* GetElementById(int);
private:
    std::vector<KeyValueEntity> elements;
    void sortElements();
    std::ofstream prepareFileToWrite(std::string);
    // bool compare(const KeyValueEntity &, const KeyValueEntity &);
};

#endif /* IndexEntity_hpp */
