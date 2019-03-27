#include "gmock/gmock.h"
#include "GenericReflect.hh"
#include "SubscriberReflect.hh"
#include "SubscriberPot.hh"
#include "SubscriberPod.hh"

using namespace testing;
using namespace std;



class ReflectUtil: public Test
{
public:
    GenericReflect<SubscriberPot, SubscriberPod>::PotVector pv =
    {
        new SubscriberPot{"charlie", 200, 3, "peer_one"},
        new SubscriberPot{"Darwin", 100, 5, "peer_two"},
        new SubscriberPot{"kevin", 13, 0, "tomtom.com"},
        new SubscriberPot{"peter", 1, 1, "o2"},
        new SubscriberPot{"tom", 200, 1, "softbank"},
        new SubscriberPot{"charlie", 21, 0, "99"},
        new SubscriberPot{"loory", 99, 0, ""}
    };
    SubscriberReflect reflect;

    ReflectUtil() :  reflect(pv)
    {
    }
};

TEST_F(ReflectUtil, getOneFilter)
{
    map<string, string> condition
    {
        {"id", "charlie"},
        {"eventTrigger", "200"}
    };

    vector<string> select{"subscriptionType", "peerId"};

    //ASSERT_THAT(reflect.getPodByCondition(condition, select).size(), Eq(1u));

    auto pv = reflect.getPodByCondition(condition, select);

    for (auto& p : pv)
    {
        cout << p->getId() << ", "
             << p->getEventTrigger() << ", "
             << p->getSubscriptionType() << ", "
             << p->getPeerId() << endl;
    }
}
