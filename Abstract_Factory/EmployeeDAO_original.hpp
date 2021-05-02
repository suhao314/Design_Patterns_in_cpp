/**
 * @file EmployeeDAO.hpp
 * @author your name (you@domain.com)
 * @brief 数据访问层
 * @version 0.1
 * @date 2021-05-02
 * 
 * @copyright Copyright (c) 2021
 * 
 * 原始实现 
 * 变化: 需要支持其他数据库
 * 
 */
#pragma once
#include <vector>

class EmployeeDAO{
public:

    std::vector<EmployeeDO> getEmployees(){
        /* 以下三者具有关联性: connection, command, reader (都得是同一种数据库) */
        sqlConnection = new sqlConnection("...");
        sqlCommand = new sqlCommand("...");
        command->commandText("...");
        command->setConnection(connection);
        sqlDataReader = sqlCommand->executeReader();
        while(reader->read){
            /* ... */
        }
    }

};

/* 原始实现: 仅支持 SQL 数据库 */
class SQLConnection{
};
class SQLCommand{
};
class SQLDataReader{
};