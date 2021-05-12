/**
 * @file FrameWorkLib.hpp
 * @author your name (you@domain.com)
 * @brief 复杂第三方视频转换框架中的一些类
 * @version 0.1
 * @date 2021-05-12
 * 
 * @copyright Copyright (c) 2021
 * 
 * 假设我们并不能对其进行修改和简化
 * 复杂类库/框架
 * 
 */

#include <string>
#include <iostream>

class VideoFile{
public:
    VideoFile(std::string const& s){
        std::cout<<"VideoFile constructor invoked"<<std::endl;
    }
};

/**
 * @brief 编码器的接口定义及其工厂
 * 
 */
class ICodec{
public:
    virtual void codec() = 0;
    virtual ~ICodec(){std::cout<<"ICodec destructor invoked"<<std::endl;}
};
class ICodecFactory{
public:
    virtual ICodec* createCodec() = 0;
    virtual ~ICodecFactory(){std::cout<<"ICodecFactory destructor invoked"<<std::endl;}
};

/**
 * @brief Ogg 编码器及其工厂
 * 
 */
class OggCompressionCodec : public ICodec{
public:
    void codec(){std::cout<<"Ogg codec"<<std::endl;}
    OggCompressionCodec(){
        std::cout<<"OggCompressionCodec constructor invoked"<<std::endl;
    }
};
class OggCompressionCodecFactory : public ICodecFactory{
public:
    virtual ICodec* createCodec(){
        return new OggCompressionCodec();
    }
};

/**
 * @brief MPEG4 编码器及其工厂
 * 
 */
class MPEG4CompressionCodec : public ICodec{
public:
    void codec(){std::cout<<"MPEG4 codec"<<std::endl;}
    MPEG4CompressionCodec(){
        std::cout<<"MPEG4CompressionCodec constructor invoked"<<std::endl;
    }
    virtual ~MPEG4CompressionCodec(){std::cout<<"MPEG4CompressionCodec destructor invoked"<<std::endl;}
};
class MPEG4CompressionFactory : public ICodecFactory{
public:
    virtual ICodec* createCodec(){
        return new MPEG4CompressionCodec();
    }
    virtual ~MPEG4CompressionFactory(){std::cout<<"MPEG4CompressionFactory destructor invoked"<<std::endl;}
};

class BitrateReader{};

class AudioMixer{};