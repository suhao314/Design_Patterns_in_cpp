#pragma once
#include "Circle.hpp"
#include "IGraphic.hpp"
#include <vector>


/**
 * @brief CompoundGraphic 类
 * 此类无需了解子项目所属的具体类, 只用过通用组件接口与子项目交互
 * 容器收到请求后会将工作分配给子项目, 处理中间结果并返回给客户
 * [Composite/Container]: 包含叶节点或其他容器等子项目的单位
 */
class CompoundGraphic : public IGraphic{
protected:
    std::vector<IGraphic*> list;
public:
    void add(IGraphic* g){
        list.push_back(g);
    }
    virtual void move(int x, int y) override {
        for(auto& e : list)
            e->move(x, y);
    }
    virtual void draw() override {
        for(auto& e : list)
            e->draw();
    }
    virtual ~CompoundGraphic(){
        for(auto e : list)
            delete e;
    }
};