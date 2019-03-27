#include <vector>
//#include <iostream>
struct vector3DF
{
   vector3DF(float ix = 0.f, float iy = 0.f, float iz = 0.f)
      : x(ix), y(iy), z(iz) {}
   union {
      float v[3];
      struct {
         float x,y,z;
      }
   };
   float operator[](size_t i) {return v[i];}
};

struct electNodeF
{
   ElectNode(): isPos(false), loc(0, 0, 0), isTouched(false), touchRa(0){}
   bool isPos; // transport data
   vector3DF loc; // location in one neuvous
   bool isTouched;
   float touchRa; // radius of touched circle with other neuvous
};

template<typename T>
class neuvousBaseT
{
   
private:
   vector<electNodeF> nodes;
};
