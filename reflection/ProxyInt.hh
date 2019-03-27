#pragma once

#include "Proxy.hh"

template<typename PT, typename P>
class ProxyInt : public Proxy <PT, P>
{
public:
    ProxyInt(std::function<bool(PT*)> has,
             std::function<int(PT*)> getter,
             std::function<void(P*, int)> setter) :
        hasM(has), getterM(getter), setterM(setter)
    {}

    virtual bool match(PT* pot, const std::string& condition)
    {
        if (hasM(pot) && std::to_string(getterM(pot)) == condition)
            return true;
        else
            return false;
    }

    virtual bool set(PT* pot, P* p)
    {
        if (hasM(pot))
        {
            setterM(p, getterM(pot));
            return true;
        }

        return false;
    }

private:
    std::function<bool(PT*)> hasM;
    std::function<int(PT*)> getterM;
    std::function<void(P*, int)> setterM;
};
