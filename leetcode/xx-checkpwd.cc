#include <iostream>
#include <vector>

std::vector<std::string> checkPwds(std::vector<std::string> pwds)
{
   std::vector<std::string> result{};
   result.reserve(pwds.size());
   for (const auto& pwd: pwds)
   {
      // check size
      if (pwd.size() <= 8)
      {
         result.push_back("NG");
         continue;
      }
      // check types
      bool types[4] = {false,false,false,false};
      for (const auto& ch: pwd)
      {
         if (ch >= char('a') && ch <= char('z'))
            types[0] = true;
         else if (ch >= char('A') && ch <= char('Z'))
            types[1] = true;
         else if (ch >= char('0') && ch <= char('9'))
            types[2] = true;
         else
            types[3] = true;
      }
      int count{0};
      for (int i = 0; i < 4; ++i)
      {
         if (types[i])
            ++count;
      }
      if (count < 3)
      {
         result.push_back("NG");
         continue;
      }

      // check sub string
      bool isOk = true;
      for (int begin = 0, size = pwd.size(); begin < size; ++begin)
      {
         for (int end = begin + 1; end < size; ++end)
         {
            if (pwd[begin] == pwd[end] && end + 2 < size
               // check the next two numbers
                && pwd[begin + 1] == pwd[end + 1]
                && pwd[begin + 2] == pwd[end + 2]
               )
            {
               isOk = false;
               break;
            }
         }
         if (not isOk)
            break;
      }
      if (not isOk)
         result.push_back("NG");
      else
         result.push_back("OK");
   }
   return result;
}



int main()
{
   std::vector<std::string> pwds{
      "021Abc9000",
      "021Abc9Abc1",
      "021ABC9000",
      "021$bc9000"
   };
   auto re = checkPwds(pwds);
   for (const auto& r : re)
      std::cout << r << std::endl;
}
