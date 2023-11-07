#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vsinegen.h"

#include "vbuddy.cpp"     
#define ADDRESS_WIDTH 8
#define ROM_SZ 256

int main(int argc, char **argv, char **env) {
  int i;     
  int clk;       
  bool seeSignal2 = false;
  Verilated::commandArgs(argc, argv);
  Vsinegen* top = new Vsinegen;
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("sinegen.vcd");
 
  if (vbdOpen()!=1) return(-1);
  vbdHeader("brunoWaves");

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
    //---------------------------- but it doesn't work so nicely (need multiple "2"
    if(vbdGetkey()=='2'){
      seeSignal2 = !seeSignal2;
      std::cout << "changed" <<std::endl;
    }
    top->incr = vbdValue();
   //---------------------------- we can control any value with computer keys! -> we could make games
    vbdPlot(int (top->dout1), 0, 255);
    
    if(seeSignal2){
      vbdPlot(int (top->dout2), 0, 255);
    }
    

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