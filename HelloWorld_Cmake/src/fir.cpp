#include "fir.hpp"



void fir::fir_main()
{
  sc_dt::sc_int<16> taps[5];
  sc_dt::sc_int<16> val;
  const sc_dt::sc_uint<8> coeff[5] = {18,77,107,77,18};
  // reset code 
  //reset internal var
  // reset output
  outp.write(0);
  wait();

  while(true)
  {
    // read input
    for (int i =5-1; i>0;i--)
    {
      taps[i] = taps[i-1];
    }
    taps[0] = inp.read();
    for (int i=0;i<5;i++)
    {
      val += coeff[i]*taps[i];
    }
    outp.write(val);
    // algo code
    // write output
    wait();
  }
}

