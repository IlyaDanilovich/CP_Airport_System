#include "OpenFileExpception.h"



OpenFileExpception::OpenFileExpception(const char *s) : std::exception(s)
{
}


OpenFileExpception::~OpenFileExpception()
{
}
