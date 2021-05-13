#pragma once
#include "TreeType.hpp"
#include <vector>

class TreeTypeFactory {
protected:
    static std::vector<TreeType*> treeTypes;
public:
    TreeType* getTreeType(std::string const& name, std::vector<int> color, std::string texture);
};

TreeType* TreeTypeFactory::getTreeType(std::string const& name, std::vector<int> color, std::string texture){
    TreeType* found = nullptr;
    for(auto const& tt : treeTypes)
        if(name==tt->getName()){
            found = tt;
            break;
        }
    
    if(!found){
        treeTypes.push_back(found = new TreeType(name, color, texture));
    }
    return found;
};

std::vector<TreeType*> TreeTypeFactory::treeTypes;