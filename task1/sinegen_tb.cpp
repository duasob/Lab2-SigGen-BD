#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vsinegen.h"

#include "vbuddy.cpp"     // include vbuddy code

#define ADDRESS_WIDTH 8
#define ROM_SZ 256

int main(int argc, char **argv, char **env) {
  int i;     // simulation clock count
  int clk;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vsinegen* top = new Vsinegen;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("sinegen.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("sin(Bruno)");

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
  //---------------------------- but it doesn't work so nicely (need multiple "e")
  if(vbdGetkey()=='e'){
    top->en = !top->en;
    std::cout << "toggled" << std::endl;
  }
  //---------------------------- we can control any value with computer keys! -> we could make games


    top->incr = vbdValue(); // with this we get the value on the bottom left
    vbdPlot(int (top->dout), 0, 255); // and here we plot it as we did in L1
    vbdCycle(i);

    if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) // to exit when we want
      exit(0);               
  }

  vbdClose();     
  tfp->close(); 
  exit(0);
}