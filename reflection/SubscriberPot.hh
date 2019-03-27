#pragma once

#include <string>
#include <vector>

class SubscriberPot
{
public:
    SubscriberPot(const std::string& id, int eventTrigger, int subscriptionType, const std::string& peerId);

    std::string id_get() const;
    void id_put(const std::string& id);
    bool id_hasValue() const;

    int eventTrigger_get() const;
    void eventTrigger_put(int eventTrigger);
    bool eventTrigger_hasValue() const;

    int subscriptionType_get() const;
    void subscriptionType_put(int subscriptionType);
    bool subscriptionType_hasValue() const;

    std::string peerId_get() const;
    void peerId_put(const std::string& peerId);
    bool peerId_hasValue() const;

private:
    std::pair<std::string, bool> idM;
    std::pair<int, bool> eventTriggerM;
    std::pair<int, bool> subscriptionTypeM;
    std::pair<std::string, bool> peerIdM;
};
