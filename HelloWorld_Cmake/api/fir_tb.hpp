#include <systemc>
using namespace sc_core;




SC_MODULE(fir_tb)
{
  sc_in<bool> clk;
  sc_out<bool> rst;
  sc_out<sc_dt::sc_int<16>> inp;
  sc_in<sc_dt::sc_int<16>> outp;

  void source();
  void sink();
  SC_CTOR(fir_tb)
  {
    SC_CTHREAD(source,clk.pos());
    SC_CTHREAD(sink,clk.pos());
  }
const sc_dt::sc_uint<8> coeff[5] = {18,77,107,77,18};

};

