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
      auto pingRAR = [&](){
         reauth(protocol, sessionId);
      };
      // remove, index is 1
      auto remove = [&](){
         remove(protocol, sessions);
      };
      // remove and pingRAR selector, index is 2
      auto methodSelector = [&](){
         if ((protocol == "Gx" && check4G) || (protocol == "Smf" && check5G))
            pingRAR();
         else if ((protocol == "Gx" && check4G) || (protocol == "Smf" && check5G))
            remove();
      };

      Method method;
      std::string potType{};
      if (potType == "IpPot")
         method = std::move(methodSelector);
      else if (potType == "SmpPot")
      {
         if (check4G)
            method = std::move(pingRAR);
         else
            method = std::move(remove);
      }

      while (sessions.size() > 0)// iterate pot
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
