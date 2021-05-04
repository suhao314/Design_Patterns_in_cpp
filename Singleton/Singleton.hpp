/**
 * @file Singleton.hpp
 * @author your name (you@domain.com)
 * @brief 单例
 * @version 0.1
 * @date 2021-05-04
 * 
 * @copyright Copyright (c) 2021
 * 
 * 动机:
 *  (类设计者)保证一个类只有一个实例(一般在堆上)
 * 
 * 本质:
 *  隐藏构造函数并实现一个静态的构建方法即可
 * 
 * 实现步骤:
 *  1. 将默认构造函数设为私有, 防止其他对象使用单例类的 new 运算符
 *  2. 新建一个静态构建方法作为构造函数
 *      该函数会 “偷偷” 调用私有构造函数来创建对象, 并将其保存在一个静态成员变量中
 *      此后所有对于该函数的调用都将返回这一缓存对象
 * 
 */

#pragma once

// #define LOCK 1
// #define THREAD
// #define DOUBLE_IF 1
#define BEST


#include <mutex>
#include <thread>
#include <atomic>
#include <string>

class Singleton{
protected:
    /* 也可以设置为 private */
    std::string value_;

    /* 全局仅有的一个实例的指针(指向自己) */
    static Singleton* singleton_;

    #ifdef BEST
    /* 最优实现: 使用原子类型 */
    static std::atomic<Singleton*> singleton;
    #endif

    /* 线程安全所需的信号量(临界区: getInstance) */
    static std::mutex mutex_;

    /* 将构造函数放在 private 或 protected 中: 防止客户代码直接 new 一个实例 */
    Singleton(const std::string& value) : value_(value){}

public:

    /* 也不允许复制构造函数(初始化语句/形实结合/返回对象)和赋值语句 */
    Singleton(Singleton& other) = delete;
    void operator=(const Singleton& ) = delete;

    /* 访问控制: 声明为静态方法(类的方法), 它会检查实例的存在性, 若不存在会调用构造函数生成一个 */
    static Singleton* getInstance(const std::string& value);

    void someBusinessLogic(){}

    std::string value() const {return value_;}
};





/*------------------------------------------- 单线程环境下的实现 -------------------------------------------*/
#ifdef THREAD

/* 全局变量在类体外初始化, 且不加 static 关键字 */
Singleton* Singleton::singleton_= nullptr;

/**
 * @brief 
 * @details 静态方法应在类外部定义, 线程不安全的实现
 * @param value 
 * @return Singleton* 
 */
Singleton* Singleton::getInstance(const std::string& value){
    if(singleton_==nullptr)
        singleton_ = new Singleton(value);
    return singleton_;
}
#endif

/*------------------------------------------- 线程安全的实现(加锁) -------------------------------------------*/
#ifdef LOCK

/* 全局变量在类体外初始化, 且不加 static 关键字 */
Singleton* Singleton::singleton_= nullptr;
std::mutex Singleton::mutex_;

/**
 * @brief 
 * @details 性能问题: 已经创建之后就没有必要再加锁(可以随意读取)
 * @param value 
 * @return Singleton* 
 */
Singleton* Singleton::getInstance(const std::string& value){
    /* 临界区保护: lock_guard 构造时lock, 析构时unlock */
    std::lock_guard<std::mutex> lock(mutex_);
    if(singleton_==nullptr)
        singleton_ = new Singleton(value);
    return singleton_;
}
#endif



/*------------------------------------------- 线程(伪)安全的实现(双检查锁) -------------------------------------------*/
#ifdef DOUBLE_IF

/* 全局变量在类体外初始化, 且不加 static 关键字 */
Singleton* Singleton::singleton_= nullptr;
std::mutex Singleton::mutex_;

/**
 * @brief 
 * @details 由于内存读写 reorder 导致线程不安全
 * @param value 
 * @return Singleton* 
 */
Singleton* Singleton::getInstance(const std::string& value){
    if(singleton_==nullptr){                                                /* 解决读取性能问题 */
        /* 只有空指针时才加锁,  第二次判断确保只有一个线程能够执行 new */
        std::lock_guard<std::mutex> lock(mutex_);
        if(singleton_==nullptr){                                            /* 确保只有一个线程能够执行 new */
            singleton_ = new Singleton(value);
        }
    }
    return singleton_;
}
/**
 * @brief reorder
 * new 的过程
 * 1. 分配内存空间
 * 2. 调用构造器
 * 3. 指针赋值给变量
 * 以上三步可能的执行顺序:
 * 1 -> 2 -> 3
 * 1 -> 3 -> 2
 * 执行完步骤3之后指针非空, 此时若再有一个线程进入第一个 if 会得到一个无法使用的对象的指针(此时构造器还没有被调用完成)
 * 
 */

#endif
/*------------------------------------------- 线程安全的实现(正确且高性能的实现) -------------------------------------------*/
#ifdef BEST

/* 全局变量在类体外初始化, 且不加 static 关键字 */
std::atomic<Singleton*> Singleton::singleton{nullptr};
std::mutex Singleton::mutex_;

/**
 * @brief 双检查锁的改进
 * 
 * @param value 
 * @return Singleton* 
 */
Singleton* Singleton::getInstance(const std::string& value){
    Singleton* tmp = singleton.load(std::memory_order_relaxed);                 
    std::atomic_thread_fence(std::memory_order_acquire);                        /* 获取内存 fence */
    if(nullptr==tmp){
        std::lock_guard<std::mutex> lock(mutex_);
        tmp = singleton.load(std::memory_order_relaxed);
        if(nullptr==tmp){
            tmp = new Singleton(value);
            std::atomic_thread_fence(std::memory_order_release);                /* 释放内存 fence */
            singleton.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}


#endif
