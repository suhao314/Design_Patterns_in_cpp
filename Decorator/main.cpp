#include <iostream>
#include "EncryptionDecorator.hpp"
#include "FileDataSource.hpp"


int main(int, char**) {

    char rawData[] = "The quick brown fox jumps over the lazy dog.\n";

    /* 运行时装配 */
    DataSource* source = new FileDataSource("test.txt");
    source = new EncryptionDecorator(source);
    /* 除了加密, 好可以有压缩, 缓冲等多种装饰器: source = new CompressionDecorator(source) */
    source->writeData(rawData);

    char* data = new char[100];
    memset(data, 0, 100*sizeof(char));
    
    source->readData(data);
    std::cout<<data<<std::endl;

    delete data;
    return 0;
}
