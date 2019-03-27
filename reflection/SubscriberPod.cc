#include "SubscriberPod.hh"

std::string SubscriberPod::getId() const
{
    return idM.first;
}

void SubscriberPod::setId(const std::string& id)
{
    idM.first = id;
    idM.second = true;
}

bool SubscriberPod::isSetId() const
{
    return idM.second;
}

int SubscriberPod::getEventTrigger() const
{
    return eventTriggerM.first;
}

void SubscriberPod::setEventTrigger(int eventTrigger)
{
    eventTriggerM.first = eventTrigger;
    eventTriggerM.second = true;
}

bool SubscriberPod::isSetEventTrigger() const
{
    return eventTriggerM.second;
}

int SubscriberPod::getSubscriptionType() const
{
    return subscriptionTypeM.first;
}

void SubscriberPod::setSubscriptionType(int subscriptionType)
{
    subscriptionTypeM.first = subscriptionType;
    subscriptionTypeM.second = true;
}

bool SubscriberPod::isSubscriptionType() const
{
    return subscriptionTypeM.second;
}

std::string SubscriberPod::getPeerId() const
{
    return peerIdM.first;
}

void SubscriberPod::setPeerId(const std::string& peerId)
{
    peerIdM.first = peerId;
    peerIdM.second = true;
}

bool SubscriberPod::isPeerId() const
{
    return peerIdM.second;
}
