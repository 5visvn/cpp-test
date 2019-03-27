#include "SubscriberPot.hh"

using namespace std;

SubscriberPot::SubscriberPot(const std::string& id, int eventTrigger, int subscriptionType, const std::string& peerId)
    : idM(make_pair(id, true))
    , eventTriggerM(make_pair(eventTrigger, true))
    , subscriptionTypeM(make_pair(subscriptionType, true))
    , peerIdM(make_pair(peerId, true))
{
}

std::string SubscriberPot::id_get() const
{
    return idM.first;
}

void SubscriberPot::id_put(const std::string& id)
{
    idM.first = id;
    idM.second = true;
}

bool SubscriberPot::id_hasValue() const
{
    return idM.second;
}

int SubscriberPot::eventTrigger_get() const
{
    return eventTriggerM.first;
}

void SubscriberPot::eventTrigger_put(int eventTrigger)
{
    eventTriggerM.first = eventTrigger;
    eventTriggerM.second = true;
}

bool SubscriberPot::eventTrigger_hasValue() const
{
    return eventTriggerM.second;
}

int SubscriberPot::subscriptionType_get() const
{
    return subscriptionTypeM.first;
}

void SubscriberPot::subscriptionType_put(int subscriptionType)
{
    subscriptionTypeM.first = subscriptionType;
    subscriptionTypeM.second = true;
}

bool SubscriberPot::subscriptionType_hasValue() const
{
    return subscriptionTypeM.second;
}

string SubscriberPot::peerId_get() const
{
    return peerIdM.first;
}

void SubscriberPot::peerId_put(const string& peerId)
{
    peerIdM.first = peerId;
    peerIdM.second = true;
}

bool SubscriberPot::peerId_hasValue() const
{
    return peerIdM.second;
}
