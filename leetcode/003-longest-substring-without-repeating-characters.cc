#include <iostream>
#include <string>
#include <set>


#define show(x) std::cout << #x << ": " << x << std::endl;
#define log(x) std::cout << x << std::endl;


bool hasDuplicatedChar(const std::string& str)
{
   return str.find_first_of(str[str.size() -1]) != str.size() -1;
}

int main()
{
   std::string s{"pwwkew"};
   show(s);
   for(int i = 0; i < 1000000; ++i)
   {
   int start{0}, end{0}, longestStart{0}, longestEnd{0};

   for (int size = s.size(); end <= size; )
   {
      if (hasDuplicatedChar(s.substr(start, end)))
      {
         ++start;
         if (start == end)
            ++end;
      }
      else
      {
         if ((longestEnd - longestStart) < (end - start))
         {
            longestEnd = end;
            longestStart = start;
         }

         ++end;
      }
   }

}
   // std::cout << "size: "<< longestEnd - longestStart << std::endl;

}
