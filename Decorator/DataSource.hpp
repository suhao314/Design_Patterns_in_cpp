#pragma once
#include <string.h>


/**
 * @brief 作为接口使用
 * [Component]
 */
class DataSource{
public:
    virtual void writeData(char* data) = 0;
    virtual void readData(char* data) = 0; 
    virtual ~DataSource() {};
};