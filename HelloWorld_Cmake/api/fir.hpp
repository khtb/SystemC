#include <systemc>
using namespace sc_core;




SC_MODULE(fir)
{
  sc_in<bool> clk;
  sc_in<bool> rst;
  sc_in<sc_dt::sc_int<16>> inp;
  sc_out<sc_dt::sc_int<16>> outp;

  void fir_main();
  SC_CTOR(fir)
  {
    SC_CTHREAD(fir_main,clk.pos());
    reset_signal_is(rst,true);
  }
};

