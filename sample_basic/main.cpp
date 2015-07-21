#include "SampleBasicAppDelegate.h"

// TODO:
// Move into df3d_executable

#if defined(DF3D_DESKTOP)

int main(int agrc, char **argv) try
{
    df3d::platform::setupDelegate(new SampleBasicAppDelegate());
    df3d::platform::run();

    df3d::base::glog << "main finished" << df3d::base::logmess;

    return 0;
}
catch (std::exception &e)
{
    df3d::base::glog << "Fatal exception occurred" << e.what() << df3d::base::logcritical;
    return 1;
}

#endif
