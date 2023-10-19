/*****************************************************************************

  Licensed to Accellera Systems Initiative Inc. (Accellera) under one or
  more contributor license agreements.  See the NOTICE file distributed
  with this work for additional information regarding copyright ownership.
  Accellera licenses this file to you under the Apache License, Version 2.0
  (the "License"); you may not use this file except in compliance with the
  License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
  implied.  See the License for the specific language governing
  permissions and limitations under the License.

 *****************************************************************************/

 /*****************************************************************************

   main.cpp -- This example shows the use of the sc_rvd classes to demonstrate
               a communication channel that uses a ready-valid handshake.

   Original Author: Andy Goodrich, Forte Design Systems, Inc.

  *****************************************************************************/

  // $Log: main.cpp,v $
  // Revision 1.2  2011/08/15 16:43:24  acg
  //  Torsten Maehne: changes to remove unused argument warnings.
  //
  // Revision 1.1  2011/06/14 21:25:39  acg
  //  Andy Goodrich: moved examples from 2.2.1 potential release.
  //
  // Revision 1.1  2010/08/20 14:14:01  acg
  //  Andy Goodrich: new example using a ready-valid handshake for communication.
  //

// #include "systemc.h"
#include <systemc>
using namespace sc_core;
#include "main.hpp"



void hello1(void)
{
    std::cout<<"hello world #1";
}

struct HelloWorld:sc_module 
{
    SC_CTOR(HelloWorld)
    {
        SC_METHOD(hello2);
    }
    void hello2()
    {
        std::cout<<name()<<"hello world #2"<<std::endl;
    }

};


int sc_main(int,char*[])
{
    hello1();
    HelloWorld x("y");
    sc_start();
    return 0;
}
