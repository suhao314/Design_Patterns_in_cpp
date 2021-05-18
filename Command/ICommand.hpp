#pragma once

/**
 * @brief Command 类的接口定义: 定义 execute 接口
 * [Command Interface]
 */
class ICommand{
public:
    virtual ~ICommand() {}
    virtual void execute() const = 0;
};