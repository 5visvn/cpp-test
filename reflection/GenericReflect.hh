#pragma once

#include <map>
#include <iostream>
#include "Proxy.hh"
#include <vector>

template<typename PT, typename P>
class GenericReflect
{
public:
    using Px = Proxy<PT, P>* ;
    using ReflectingMap = std::map<std::string, Px>;
    using PotVector = std::vector<PT*>;
    using PodVector = std::vector<P*>;

    GenericReflect(const PotVector& pv)
        : potVec(pv)
    {
    }

    PodVector getPodByCondition(const std::map<std::string, std::string>& condition,
                                const std::vector<std::string>& select)
    {
        // std::cout << "potVec size :[" << potVec.size() << "]" << std::endl;
        auto map = getReflectingMap();
        PodVector pv;

        for (auto& pot : potVec)
        {
            auto matched = true;

            for (const auto& c : condition)
            {
                if (!(matched = map[c.first] == nullptr ? false : map[c.first]->match(pot, c.second)))
                    break;
            }

            if (matched)
            {
                // std::cout << "matched : [" << (matched ? "Matched" : "Unmatched") << "]" << std::endl;
                // std::cout << "size :[" << select.size() << "]" << std::endl;
                auto p = new P;

                getIdProxy()->set(pot, p);

                for (auto& s : select)
                {
                    map[s] == nullptr ? false : map[s]->set(pot, p);
                }

                pv.push_back(p);
            }
        }

        return pv;
    }

protected:
    virtual ReflectingMap getReflectingMap() const = 0;
    virtual Px getIdProxy() const = 0;

    PotVector potVec;
};
