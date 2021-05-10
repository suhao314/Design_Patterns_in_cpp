#include <iostream>
#include "EncryptionDecorator.hpp"
#include "FileDataSource.hpp"


int main(int, char**) {
    DataSource* source = new FileDataSource("test.txt");
    source = new EncryptionDecorator(source);
    source->writeData("The quick brown fox jumps over the lazy dog.\n");

    char* data = new char[100];
    memset(data, 0, 100*sizeof(char));
    
    source->readData(data);
    std::cout<<data<<std::endl;

    return 0;
}
