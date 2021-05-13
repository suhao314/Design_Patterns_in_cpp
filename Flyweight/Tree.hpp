#pragma once
#include "TreeTypeFactory.hpp"

class Tree{
protected:
    int x_;
    int y_;
    TreeType* tt_;
public:
    Tree(int x, int y, TreeType* tt) : x_(x), y_(y), tt_(tt){}
    void draw();
};

void Tree::draw(){
    tt_->draw(x_, y_);
}