#include <iostream>
#include "RoundHole.hpp"
#include "SquarePeg.hpp"
#include "RoundPeg.hpp"
#include "SquarePegAdapter.hpp"


int main(){
    RoundHole* rh = new RoundHole(2);
    RoundPeg* rp = new RoundPeg(2);

    std::cout<<"RoundHole only accepts RoundPeg(s) to check if they fit with each other: "<<std::endl<<std::endl;
    std::cout<<((rh->fits(rp))?"True":"False")<<std::endl<<std::endl;
    std::cout<<"Now we have SquarePeg(s)..."<<std::endl;

    SquarePeg* sp = new SquarePeg(2.828);
    /* 使用适配器对 SquaredPeg 进行包装, 使得 RoundHole 的 fits 方法可以接受其作为参数传入 */
    SquarePegAdapter* spa = new SquarePegAdapter(sp);

    std::cout<<"Wrap the SquarePeg(s) as a derived class of RoundPeg(s), so that we can chek if they fit with each other: "<<std::endl<<std::endl;
    std::cout<<((rh->fits(spa))?"True":"False")<<std::endl<<std::endl;

    delete rh;
    delete rp;
    delete sp;
    delete spa;
    return 0;
}