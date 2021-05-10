#pragma once
#include "DataSource.hpp"
/**
 * @brief 装饰器基类: 被具体的装饰器所继承
 * [BaseDecorator]
 */
class DataSourceDecorator : public DataSource{
protected:
    /* 类的组合: 包含一个父类的指针(可初始化为 FileDataSource 类对象的指针) */
    DataSource* wrappee;
public:
    DataSourceDecorator(DataSource* s) : wrappee(s){}
    virtual void writeData(char* data) {wrappee->writeData(data);}
    virtual void readData(char* data) {return wrappee->readData(data);}
    virtual ~DataSourceDecorator() {delete wrappee;}
};


