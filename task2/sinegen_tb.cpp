#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vsinegen.h"

#include "vbuddy.cpp"     // include vbuddy code
#define ADDRESS_WIDTH 8
#define ROM_SZ 256

int main(int argc, char **argv, char **env) {
  int i;     
  int clk;       

  Verilated::commandArgs(argc, argv);
  Vsinegen* top = new Vsinegen;
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("sinegen.vcd");
 
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L2T1: SigGen");

  top->clk = 1;
  top->rst = 0;
  top->en = 1;
  top->incr = 1;


  for (i=0; i<1000000; i++) {
    for (clk=0; clk<2; clk++) {
      tfp->dump (2*i+clk);
      top->clk = !top->clk;
      top->eval ();
    }
    
    top->incr = vbdValue();
    // plot ROM output and print cycle count

    vbdPlot(int (top->dout1), 0, 255);
    //vbdPlot(int (top->dout2), 0, 255);

    //std::cout << "1 : " << top->dout1 <<std::endl;
    //std::cout << "2 : " << top->dout2 <<std::endl;
  
    vbdCycle(i++);

    // either simulation finished, or 'q' is pressed
    if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
      exit(0);                // ... exit if finish OR 'q' pressed
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}