#include "Forest.hpp"

int main(){
    Forest f;
    f.plantTree(0, 0, "Banyan", {0, 250,20}, "Banyan_texture", 1);
    f.plantTree(10, 10, "Willow", {5, 200, 12}, "Willow_texture", 4);
    f.plantTree(15, 13, "Pine", {3, 220, 35}, "Pine_texture", 5);

    f.draw();

    return 0;
}