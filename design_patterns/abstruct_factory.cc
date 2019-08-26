class Product{};

class ProductA1 : public Product{};
class ProductA2 : public Product{};

class ProductB1 : public Product{};
class ProductB2 : public Product{};


class Factory
{
public:
   virtual Factory(){}
   virtual ~Factory(){}
   virtual Product1 CreateProduct1() = 0;
   virtual Product2 CreateProduct2() = 0;

};

class ASeriesFactory : public Factory
{
public:
   virtual Product1 CreateProduct1(){ return ProductA1();}
   virtual Product2 CreateProduct2(){ return ProductA2();}
};


class BSeriesFactory : public Factory
{
public:
   virtual Product1 CreateProduct1(){ return ProductB1();}
   virtual Product2 CreateProduct2(){ return ProductB2();}
};

