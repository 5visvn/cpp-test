#pragma once

#include <string>
#include <vector>

class SubscriberPod
{
public:
    std::string getId() const;
    void setId(const std::string& id);
    bool isSetId() const;

    int getEventTrigger() const;
    void setEventTrigger(int eventTrigger);
    bool isSetEventTrigger() const;

    int getSubscriptionType() const;
    void setSubscriptionType(int subscriptionType);
    bool isSubscriptionType() const;

    std::string getPeerId() const;
    void setPeerId(const std::string& peerId);
    bool isPeerId() const;

private:
    std::pair<std::string, bool> idM;
    std::pair<int, bool> eventTriggerM;
    std::pair<int, bool> subscriptionTypeM;
    std::pair<std::string, bool> peerIdM;
};
