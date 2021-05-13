#pragma once
#include "TreeType.hpp"
#include "TreeTypeFactory.hpp"
#include "Tree.hpp"

class Forest{
protected:
    TreeTypeFactory* tf;
    std::vector<Tree*> trees;
public:
    void plantTree(int x, int y, std::string name, std::vector<int> color, std::string texture, int n=1);
    void draw();
};

void Forest::plantTree(int x, int y, std::string name, std::vector<int> color, std::string texture, int n){
    TreeType* treeType = nullptr;
    for(int i=0; i<n; i++){
        if(i==0) treeType = tf->getTreeType(name, color, texture);
        Tree* tree = new Tree(x, y, treeType);
        trees.push_back(tree);
    }
}

void Forest::draw(){
    std::cout<<"Drawing Forest..."<<std::endl;
    for(auto const& e : trees)
        e->draw();
    std::cout<<"--------------------"<<std::endl;
}