#include "fir_tb.hpp"

void fir_tb::source()
{
    sc_dt::sc_int<16> tmp;

    // reset
    inp.write(0);
    rst.write(1);
    wait();
    rst.write(0);
    wait();

    for (int i = 0; i < 64; i++)
    {
        if (i > 23 && i < 29)
        {
            tmp = 256;
        }
        else
        {
            tmp = 0;
        }
        inp.write(tmp);
        wait();
    }
}

void fir_tb::sink()
{
    sc_dt::sc_int<16> indata;
    for (int i = 0; i<64 ; i++)
    {
        indata = outp.read();
        wait();
        std::cout<<i<< " :\t" << indata.to_int() <<std::endl;
    }
    //end simulation 
    sc_stop();
}