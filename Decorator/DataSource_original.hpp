/**
 * @file Stream_original.hpp
 * @author your name (you@domain.com)
 * @brief 原始实现
 * @version 0.1
 * @date 2021-05-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*----------------------------------------------------------------------------*/
class DataSource{
    public:
    virtual void writeData(char* data) = 0;
    virtual void readData(char* data) = 0; 
    virtual ~DataSource() {};
};

/*----------------------------------------------------------------------------*/

class FileDataSource : public DataSource{
protected:
    char* fileName_;
public:
    FileDataSource(char* fileName) : fileName_(fileName){}
    virtual void writeData(char* data) override;
    virtual void readData(char* data) override;
};

class NetworkDataSource : public DataSource{

};

class MemoryDataSource : public DataSource{

};
/* 以上部分不存在设计问题 */
/*----------------------------------------------------------------------------*/
/* 关键部分 */
class CryptoFileDataSource : public FileDataSource{

};

class BufferedFileDataSource : public FileDataSource{

};

class CryptoBufferedFileDataSource : public BufferedFileDataSource{

};

/* 针对网络流和内存流的加密缓冲略 */

/*----------------------------------------------------------------------------*/

/**
 * 使用继承实现会使得类的数量急剧扩大, 且存在相当多的代码冗余:
 *  CryptoFileDataSource, CryptoNetworkDataSource, CryptoMemoryDataSource 下的加密业务逻辑代码
 *      同理, 缓冲代码也冗余
 * 
 * 改进: 使用组合而非继承(以 Crypto 为例)
 *  1. 因为 CryptoFileDataSource, CryptoNetworkDataSource, CryptoMemoryDataSource 中只需要调用 DataSource 的接口即可
 *      所以在这些类中放一个基类的指针即可(可以被初始化为不同DataSource类的对象)
 *      三合一变为 CryptoDataSource; 为实现相应接口规范, 此类改为继承 DataSource
 *      至此, 编译时装配(直接 new CryptoBufferedFileDataSource())变为了运行时装配(注意构造器和基类指针)
 *      不追求完美至此即可
 * 
 *  2. 做了第一步之后发现 CryptoDataSource BufferedDataSource 是相似的
 *      可以建立一个新的中间类 DataSourceDecorator:public DataSource
 *      然后
 *      CryptoDataSource : public DataSourceDecorator
 *      
 * 动机:
 * 在某些情况下可能会过度地使用继承来扩展对象功能, 由于继承为类型引入静态的特质, 使得这种扩展方式缺乏灵活性, 并且可能随着子类的增多, 各种子类的组合导致子类数量的膨胀
 * 
 * 要点小结
 * 1. 通过采用组合而非继承的手法, 实现在运行时动态扩展对象功能的能力, 避免继承带来的灵活性差和多子类衍生问题
 * 2. Decorator 类在接口上表现为 is-a 关系, 继承了父类 Component 的接口, 实现上表现出 has-a 关系, 即 Decorator 使用了另外一个 Component 类
 *      辨别 Decorator 设计模式: 同时继承和组合了同一个类
 * 3. Decorator 模式的目的并非解决多子类衍生的多继承问题, 要点在于解决主体类在多个功能上的扩展
 *      CryptoFileDataSource 相当于用 Crypto 装饰 FileDataSource
 */