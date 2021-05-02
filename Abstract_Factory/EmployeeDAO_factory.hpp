/**
 * @file EmployeeDAO.hpp
 * @author your name (you@domain.com)
 * @brief 数据访问层
 * @version 0.1
 * @date 2021-05-02
 * 
 * @copyright Copyright (c) 2021
 * 
 * 改用工厂方法(仅解决了一部分问题)
 * 变化: 需要支持其他数据库
 * 
 */
#pragma once
#include <vector>

class EmployeeDAO{
public:
    /* 应用工厂模式: 4. 改写构造函数(略) */
    /* 工厂模式未能解决的问题: 传递的工厂参数应对应于同一个数据库 */

    /* 应用工厂模式: 3. 接口工厂加入到成员变量中 */
    IDBConnectionFactory* dbConnectionFactory;
    IDBCommandFactory* dbCommandFactory;
    IDBDataReaderFactory* dbDataReaderFactory;

    /* 应用工厂模式: 5. 对于具体类的 new 改为调用工厂方法 */
    std::vector<EmployeeDO> getEmployees(){
        /* 以下三者具有关联性: connection, command, reader (都得是同一种数据库) */
        // SQLConnection* connection = new SQLConnection("...");
        IDBConnection* connection = dbConnectionFactory->createDBConnection();
        // SQLCommand* command = new SQLCommand("...");
        IDBCommand* command = dbCommandFactory->createDBCommand();
        command->commandText("...");
        command->setConnection(connection);
        IDBDataReader* reader = command->executeReader();
        while(reader->read()){
            /* ... */
        }
    }

};

/* 增加其他数据库支持第一步: 定义接口(作为基类, 规定必须实现的纯虚方法) */
class IDBConnection{
};
class IDBCommand{
};
class IDBDataReader{
};

/* 增加其他数据库支持第二步: 改为继承基类 */
class SQLConnection : public IDBConnection{
};
class SQLCommand : public IDBCommand{
};
class SQLDataReader : public IDBDataReader{
};
/* 其他数据库的子类(略) */


/* 应用工厂模式: 1. 接口的工厂 */
class IDBConnectionFactory{
public:
    virtual IDBConnection* createDBConnection() = 0;
};
class IDBCommandFactory{
    virtual IDBCommand* createDBCommand() = 0;
};
class IDBDataReaderFactory{
    virtual IDBDataReader* createDBDataReader() = 0;
};

/* 应用工厂模式: 2. 具体类的工厂(继承自接口工厂) */
class SQLConnectionFactory : public IDBConnectionFactory{
    virtual IDBConnection* createSQLConnection(){
        return new SQLConnection();
    }
};
class SQLCommandFactory : public IDBCommandFactory{
    virtual IDBCommand* createSQLCommand(){
        return new SQLCommand();
    }
};
class SQLDataReaderFactory : public IDBDataReaderFactory{
    virtual IDBDataReader* createSQLDataReader(){
        return new SQLDataReader();
    }
};
