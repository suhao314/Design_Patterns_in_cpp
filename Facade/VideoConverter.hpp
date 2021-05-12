#pragma once
#include "FrameworkLib.hpp"
#include <string>


/**
 * @brief 为复杂子系统提供了简单的接口(convert), 将框架/类库的复杂性隐藏于此类中, 对外提供易用的接口
 * 特别适用于调用复杂类库的场景, 让上层用户独立于下层的复杂子系统
 * [Facade]
 */
class VideoConverter{
protected:
    ICodecFactory* factory;
public:
    VideoConverter(ICodecFactory* f):factory(f){}
    void convert(std::string const& fileName, std::string const& format);
    ~VideoConverter();
};

void VideoConverter::convert(std::string const& fileName, std::string const& format){
    auto videofile = new VideoFile(fileName);
    ICodec* codec = factory->createCodec();
    codec->codec();
    /* 一些更复杂的转换工作 */
    /* 如果需要更换类库/框架, 重写本类的方法即可, 向用户屏蔽底层的丑陋 */
    delete codec;
    return;
}

VideoConverter::~VideoConverter(){
    std::cout<<"VideoConverter destructor invoked, delete factory"<<std::endl;
    delete factory;
}