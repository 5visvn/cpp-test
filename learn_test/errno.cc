//#include <string>
#include <iostream>

int main()
{
   for(int errorno = 11; errorno > -10; --errorno)
      std::cout << errorno << “: ”<< strerror(errorno) << std::endl;
}
