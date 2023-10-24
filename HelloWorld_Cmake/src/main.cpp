#include <systemc>
using namespace sc_core;

SC_MODULE(PROCESS) 
{
  sc_clock clk;
  SC_CTOR(PROCESS) : clk("clk",1,SC_SEC)
  {
    SC_METHOD(method);
    SC_THREAD(thread);
    SC_CTHREAD(cthread,clk);

  }

  void method(void)
  {
    std::cout<<"\033[1;31m"<< "method triggered @" << sc_time_stamp() <<"\033[0m\n";
    next_trigger(sc_time(1,SC_SEC));
  }
  void thread()
  {
    while(1)
    {
      std::cout << "Thread triggered @ " << sc_time_stamp() << std::endl;
      wait(1,SC_SEC);
    }
  }

  void cthread()
  {
    while(1)
    {
      std::cout << "cthread triggered @ " << sc_time_stamp() << std::endl;
      wait();
    }
  }

};


int sc_main(int,char*[])
{
  PROCESS prcess("process");
  std::cout << "exection phase begins @ " <<sc_time_stamp() <<std::endl;
  sc_start(5,SC_SEC);
  std::cout << "exection phase end @ " <<sc_time_stamp() <<std::endl;
  return 0;
}
