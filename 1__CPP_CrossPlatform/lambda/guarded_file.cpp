#include "ScopedAction.h"

#include <fstream>
#include <boost/bind.hpp>

void ReadFileSample()
{
    std::fstream f;
    f.open("TargetFile.bin", std::ios::in | std::ios::binary);


    ScopedAction::Callback callback = 
        boost::bind(&std::fstream::close, &f);

    ScopedAction guard(callback);


    size_t data = 0;
    f.read(&data, sizeof(data));

    // f.close();
}

