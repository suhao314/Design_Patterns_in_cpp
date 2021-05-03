#include "Printer.hpp"

int main(){
    Printer* p = new Printer();
    p->copy();
    delete p;
    return 0;
}