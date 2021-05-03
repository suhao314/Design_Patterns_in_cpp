/**
 * @file EmployeeDAO_AbstractFactory.hpp
 * @author your name (you@domain.com)
 * @brief 数据访问层
 * @version 0.1
 * @date 2021-05-03
 * 
 * @copyright Copyright (c) 2021
 * 
 * 改用抽象工厂方法
 * 变化: 需要支持其他数据库
 * 
 */
#pragma once
#include <vector>

class EmployeeDAO{
public:
    /* 应用抽象工厂模式: 4. 改写构造函数(略) */

    /* 应用抽象工厂模式: 3. 接口工厂加入到成员变量中 */
    IDBFactory* factory;

    /* 应用抽象工厂模式: 5. 对于具体类的 new 改为调用工厂方法 */
    std::vector<EmployeeDO> getEmployees(){
        /* 以下三者具有关联性: connection, command, reader (都得是同一种数据库) */
        // SQLConnection* connection = new SQLConnection("...");
        IDBConnection* connection = factory->createDBConnection();
        // SQLCommand* command = new SQLCommand("...");
        IDBCommand* command = factory->createDBCommand();
        command->commandText("...");
        command->setConnection(connection);
        IDBDataReader* reader = command->executeReader();
        while(reader->read()){
            /* ... */
        }
    }

};

/* [AbstractProductA/B/C] 多种数据库支持的接口定义 */
class IDBConnection{
};
class IDBCommand{
};
class IDBDataReader{
};

/* [AbstractFactory] 应用抽象工厂模式: 1. 由于以上三者必须配套, 放在同一个工厂中 */
class IDBFactory{
public:
    virtual IDBConnection* createDBConnection() = 0;
    virtual IDBCommand* createDBCommand() = 0;
    virtual IDBDataReader* createDataReader() = 0;
};

/* [ProductA1/B1/C1] */
class SQLConnection : public IDBConnection{
};
class SQLCommand : public IDBCommand{
};
class SQLDataReader : public IDBDataReader{
};

/* [ConcreteFactory1] 应用抽象工厂模式: 2. 具体工厂 */
class SQLFactory : public IDBFactory{
    virtual IDBConnection* createDBConnection(){
        return new SQLConnection();
    }
    virtual IDBCommand* createDBCommand(){
        return new SQLCommand();
    }
    virtual IDBDataReader* createDataReader(){
        return new SQLDataReader();
    }
};

/**
 * @brief 总结
 * 特殊化:
 *  如果抽象工厂/具体工厂只负责创建一种接口/类, 退化为普通的工厂方法
 * 动机:
 *  在软件系统中经常面临着"一系列相互依赖的对象"的创建工作, 同时由于需求的变化, 往往存在着更过系列对象的创建工作
 * 模式定义:
 *  提供一个接口, 让该接口负责创建一些列相关或相互依赖的对象, 而无需指定他们具体的类
 * 小结:
 *  1. 如果没有应对"多系列对象构建"的需求变化, 无需使用抽象工厂模式, 普通工厂方法足以胜任
 *  2. "系列对象"指在某一特定系列下的对象之间有相互依赖的关系, 不同系列对象之间则没有相互依赖
 *  3. 抽象工厂模式主要用于应对系列的变化, 缺点在于难以应对"新对象"的需求变动
 * 
 */