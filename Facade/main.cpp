#include "VideoConverter.hpp"

int main(){
    auto converter = new VideoConverter(new MPEG4CompressionFactory());
    converter->convert("Nyanyanyanyanyanyanya!", "mp4");

    delete converter;
    return 0;
}