// requirements:
// ip pot has two type of protocol, smp pot only one protocol
// each types has a switch to control operation "remove" or "reauth"
// for ip pot, need to check every data for different operations
// for smp pot, need to check only once.
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
      // reauth
      auto ping = [&](){
         reauth(protocol, sessionId);
      };
      // remove
      auto remove = [&](){
         remove(protocol, sessions);
      };
      // remove and pingRAR selector
      auto methodSelector = [&](){
                               if ((protocol == "4G" && check4G) || (protocol == "5G" && check5G)
            ping();
                                   if ((protocol == "4G" && !check4G) || (protocol == "5G" && !check5G)
            remove();
      };

      Method method;
      std::string potType{};
      // different pot, different solution
      if (potType == "IpPot")
         method = std::move(methodSelector);
      else if (potType == "SmpPot")
      {
         if (check4G)
            method = std::move(ping);
         else
            method = std::move(remove);
      }

      // iterate pot
      while (sessions.size() > 0)
      {
         protocol = ""; // get protocol
         // do ping or remove when smp
         // do selector when ip
         method();
      }
   }
};

int main()
{
   Cleaner c;
   c.doClean();
}
