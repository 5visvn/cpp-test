#pragma once

template<typename PT, typename P>
class Proxy
{
public:
    virtual bool match(PT* pot, const std::string& condition) = 0;
    virtual bool set(PT* pot, P* p) = 0;
};
