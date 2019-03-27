
int main()
{

   int a = 0;
   int* pa = &a;
   *pa = 1;
   std::cout << *pa;
   pa = nullptr;

   static int c = 10;
   enum {apple, banana = 12;  }
   switch(a)
   {
   case 0:
   {
      break;
   }
   case apple:
   {
      c = 100;
   }
   }
   return 0;
}


class test
{
   int a;
   int b;
   char c;

   test1 t1;
   test* pt;
public:
   test():b(0), c('c'), a(0), pt(this)
   {
      a = 1;
   }
}

