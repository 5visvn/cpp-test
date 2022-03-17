template<typename T>
static getSingletonInstance()
{
   static T instance;
   return instance;
}

// this class is for inheritance
template<typename T>
class Singleton
{
public:

   static getInstance()
   {
      static T instance;
      return instance;
   }
}
