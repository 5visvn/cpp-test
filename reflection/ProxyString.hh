#pragma once

#include "Proxy.hh"

template<typename PT, typename P>
class ProxyString : public Proxy<PT, P>
{
public:
    ProxyString(std::function<bool(PT*)> has,
                std::function<std::string(PT*)> getter,
                std::function<void(P*, std::string)> setter) :
        hasM(has), getterM(getter), setterM(setter)
    {
    }

    virtual bool match(PT* pot, const std::string& condition)
    {
        if (hasM(pot) && getterM(pot) == condition)
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
    std::function<std::string(PT*)> getterM;
    std::function<void(P*, std::string)> setterM;
};
