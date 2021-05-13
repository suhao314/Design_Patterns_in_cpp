#include "CompoundGraphic.hpp"

/**
 * @brief 扮演 Client 角色
 * 
 * @return int 
 */
int main(){
    CompoundGraphic cg;
    cg.add(new Dot(1, 2));
    cg.add(new Dot(3,4));
    cg.add(new Circle(114, 5, 14));
    cg.add(new Circle(114, 51, 4));
    cg.draw();

    return 0;
}