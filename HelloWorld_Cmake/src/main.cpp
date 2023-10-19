#include <systemc>
using namespace sc_core;

SC_MODULE(MODULE_A)
{
  SC_CTOR(MODULE_A)
  {
    SC_METHOD(MODULE_A_METH);
  }
  void MODULE_A_METH( )
  {
    std::cout<<name() <<std::endl;
  }
};

SC_MODULE(MODULE_B)
{
  SC_CTOR(MODULE_B)
  {
    SC_METHOD(MODULE_B_METH);
  }
  void MODULE_B_METH();

};
void MODULE_B::MODULE_B_METH()
{
  std::cout << this->name() << std::endl;
}

SC_MODULE(MODULE_C)
{
  const int i;
  SC_CTOR(MODULE_C);
  MODULE_C(sc_module_name name, int i): sc_module(name),i(i)
  {
    SC_METHOD(function_c);
  }
  void function_c()
  {
    std::cout << name() << ", i = " << i << std::endl;
  }
};

int sc_main(int,char*[])
{
  MODULE_A modA("module_a");
  MODULE_B modB("module_b");
  // MODULE_B modB12("module_b");
  MODULE_C modc("module_c",10);
  sc_start();
  return 0;
}