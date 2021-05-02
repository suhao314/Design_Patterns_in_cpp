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
    std::vector<EmployeeDO> getEmployees();

    /* 应用工厂模式: 3. 接口工厂加入到成员变量中 */
    IDBConnectionFactory* dbConnectionFactory;
    IDBCommandFactory* dbCommandFactory;
    IDBDataReaderFactory* dbDataReaderFactory;

    /* 以下三行具有关联性: 都得是 SQL 数据库 */
    // SQLConnection* connection = new SQLConnection("...");
    SQLConnection* connection = dbConnectionFactory->createDBConnection();
    // SQLCommand* command = new SQLCommand("...");
    SQLCommand* command = dbCommandFactory->createDBCommand();
    command->setConnection("...")
    SQLDataReader* reader = command->executeReader();
    
    while(reader->read()){
            /* ... */
    }
};

/* 增加其他数据库支持第一步: 定义接口(基类) */
class IDBConnection{
};
class IDBCommand{
};
class IDBDataReader{
};

/* 增加其他数据库支持第二步: 继承基类 */
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
