#include <systemc>
#include "fir.hpp"
#include "fir_tb.hpp"

using namespace sc_core;

SC_MODULE(SYSTEM)
{
  fir_tb *tb0;
  fir *fir0;

  sc_signal<bool> rst_sig;
  sc_signal<sc_dt::sc_int<16>> inp_sig;
  sc_signal<sc_dt::sc_int<16>> outp_sig;
  sc_clock clk_sig;

  SC_CTOR(SYSTEM) : clk_sig("clk_sig", 10, SC_NS)
  {
    tb0 = new fir_tb("tb0");
    tb0->clk(clk_sig);
    tb0->rst(rst_sig);
    tb0->inp(inp_sig);
    tb0->outp(outp_sig);

    fir0 = new fir("fir0");
    fir0->clk(clk_sig);
    fir0->rst(rst_sig);
    fir0->inp(inp_sig);
    fir0->outp(outp_sig);
  }

  ~SYSTEM()
  {
    delete tb0;
    delete fir0;
  }
};

SYSTEM *top = NULL;
int sc_main(int argc, char *argv[])
{
  top = new SYSTEM("top");
  std::cout << "exection phase begins @ " << sc_time_stamp() << std::endl;
  sc_start();
  // std::cout << "exection phase end @ " << sc_time_stamp() << std::endl;
  return 0;
}
