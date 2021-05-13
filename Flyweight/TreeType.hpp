#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

class TreeType{
protected:
    std::string name_;
    std::vector<int> color_;
    std::string texture_;
public:
    TreeType(std::string const& name, std::vector<int> color, std::string texture):name_(name), color_(color), texture_(texture){}
    void draw(int x, int y);
    virtual ~TreeType(){}

    std::string& getName(){return name_;}
    std::vector<int>& getColor(){return color_;}
    std::string& getTexture(){return texture_;}
};

void TreeType::draw(int x, int y){
    char temp[1024];
    sprintf(temp, "%s @ <%d, %d>, <%dR, %dG, %dB>, texture= %s\n", name_.c_str(), x, y, color_[0], color_[1], color_[2], texture_.c_str());
    std::cout<<temp;
}
