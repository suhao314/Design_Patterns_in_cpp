#pragma once
#include "DataSourceDecorator.hpp"
#include <stdio.h>

#define CRYPTION_SHFT 1


/**
 * @brief 具体的装饰器: 完成数据的加密
 * [ConcreteDecorator]
 * 继承自 DataSourceDecorator: 继承到了 DataSource* wrappee;
 */
class EncryptionDecorator : public DataSourceDecorator{
protected:
    void encrypt(char* data);
    void decrypt(char* data);
public:
    EncryptionDecorator(DataSource* s) : DataSourceDecorator(s) {}
    virtual void writeData(char* data) override;
    virtual void readData(char* data) override;
};

void EncryptionDecorator::encrypt(char* data){
    for(char* iter=data; (*iter)!='\0'; iter++)
        (*iter) = (*iter) + CRYPTION_SHFT;
}

void EncryptionDecorator::decrypt(char* data){
    for(char* iter=data; (*iter)!='\0'; iter++)
        (*iter) = (*iter) - CRYPTION_SHFT;
}

void EncryptionDecorator::writeData(char* data){
    encrypt(data);
    wrappee->writeData(data);
}

void EncryptionDecorator::readData(char* data){
    wrappee->readData(data);
    decrypt(data);
}