#include "House.hpp"

int main(){
    /* Client Code */
    HouseStoneBuilder* hsb = new HouseStoneBuilder();
    HouseDirector* hd = new HouseDirector(hsb);
    hd->Construct();
    return 0;
}