#include <set>
#include <vector>
#include <functional>

class Cleaner{
   void remove(std::string p, std::set<int> s){}
   void reauth(std::string p, std::string s){}
public:
   void doClean()
   {
      std::set<int> sessions;
      std::string protocol{};
      std::string sessionId{};
      bool check4G{true};
      bool check5G{true};
      typedef std::function<void()> Method;

      std::vector<Method> cleanMethods;
      // ping RAR, index is 0
      cleanMethods.push_back(
         std::move([&](){
            reauth(protocol, sessionId);
         }));
      // remove, index is 1
      cleanMethods.push_back(
         std::move([&](){
            remove(protocol, sessions);
         }));
      // remove and pingRAR selector, index is 2
      cleanMethods.push_back(
         std::move([&](){
            if ((protocol == "Gx" && check4G) || (protocol == "Smf" && check5G))
               cleanMethods[0]();
            else if ((protocol == "Gx" && check4G) || (protocol == "Smf" && check5G))
               cleanMethods[1]();
         }));

      // std::function<void* ()> cleanSession;
      int methodIndex{0};
      std::string potType{};
      if (potType == "IpPot")
         methodIndex = 2;
      else if (potType == "SmpPot")
      {
         if (check4G)
            methodIndex = 0;
         else
            methodIndex = 1;
      }

      while (sessions.size() > 0)// iterate pot
      {
         protocol = ""; // get protocol
         // do ping or remove when smp
         // do selector when ip
         cleanMethods[methodIndex]();
      }
   }
};

int main()
{
   Cleaner c;
   c.doClean();
}
