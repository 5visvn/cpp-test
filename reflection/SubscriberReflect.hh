#pragma once

#include <functional>

#include "GenericReflect.hh"
#include "SubscriberPot.hh"
#include "SubscriberPod.hh"
#include "ProxyInt.hh"
#include "ProxyString.hh"


class SubscriberReflect : public GenericReflect<SubscriberPot, SubscriberPod>
{
public:
    SubscriberReflect(const PotVector& pv)
        : GenericReflect<SubscriberPot, SubscriberPod>(pv)
    {
        px = new ProxyString<SubscriberPot, SubscriberPod>(
            std::mem_fn(&SubscriberPot::id_hasValue),
            std::mem_fn(&SubscriberPot::id_get),
            std::mem_fn(&SubscriberPod::setId));
        reflectingMap =
        {
            {
                "id", px
            },
            {
                "eventTrigger",
                new ProxyInt<SubscriberPot, SubscriberPod>(
                    std::mem_fn(&SubscriberPot::eventTrigger_hasValue),
                    std::mem_fn(&SubscriberPot::eventTrigger_get),
                    std::mem_fn(&SubscriberPod::setEventTrigger))
            },
            {
                "subscriptionType",
                new ProxyInt<SubscriberPot, SubscriberPod>(
                    std::mem_fn(&SubscriberPot::subscriptionType_hasValue),
                    std::mem_fn(&SubscriberPot::subscriptionType_get),
                    std::mem_fn(&SubscriberPod::setSubscriptionType))
            },
            {
                "peerId",
                new ProxyString<SubscriberPot, SubscriberPod>(
                    std::mem_fn(&SubscriberPot::peerId_hasValue),
                    std::mem_fn(&SubscriberPot::peerId_get),
                    std::mem_fn(&SubscriberPod::setPeerId))
            }
        };
    }

    virtual ReflectingMap getReflectingMap() const
    {
        return reflectingMap;
    }

    virtual Px getIdProxy() const
    {
        return px;
    }

private:
    Px px;
    ReflectingMap reflectingMap;
};
