// consteval will calculate during compiling
consteval auto fun(unsigned input) // c++ 20
{
   unsigned re = 0;
   for (unsigned i = 0; i < input; ++i)
      re += i;
   return re;
}

int main()
{
   return fun(10);
}
