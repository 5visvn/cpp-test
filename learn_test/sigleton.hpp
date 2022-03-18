template<typename T>
static getSingletonInstance()
{
   static T instance;
   return instance;
}

template<typename T>
static getThreadLocalInstance()
{
   static thread_local T instance;
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
