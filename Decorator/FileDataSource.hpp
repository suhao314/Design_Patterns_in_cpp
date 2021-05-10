#pragma once
#include "DataSource.hpp"
#include <stdio.h>


/**
 * @brief 可以实例化为对象, 在应用中作为指针传给具体装饰器类的构造器
 * [ConcreteComponent]
 */
class FileDataSource : public DataSource{
protected:
    char* fileName_;
public:
    FileDataSource(char* fileName) : fileName_(fileName){}
    virtual void writeData(char* data) override;
    virtual void readData(char* data) override;
};

void FileDataSource::writeData(char* data){
    FILE* fp = fopen(fileName_, "w");
    fprintf(fp, data);
    fclose(fp);
}

void FileDataSource::readData(char* data){
    FILE* fp = fopen(fileName_, "r");
    fscanf(fp, "%s", data);
    fclose(fp);
}