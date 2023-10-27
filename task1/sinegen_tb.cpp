    #include "Vcounter.h"
    #include "Vrom.h"
    #include "Vsinegen.h"
    #include "verilated.h"
    #include "verilated_vcd_c.h"
    #include "vbuddy.cpp"

    int main (int argc, char **argv, char **env){
        int i;
        int clk;

        Verilated::commandArgs(argc, argv);

        Vtop* top = new Vtop;

        Verilated::traceEverOn(true);
        VerilatedVcdC* tfp = new VerilatedVcdC;
        top->trace (tfp, 99);
        tfp->open ("counter.vcd");


        if (vbdOpen() != 1) return(-1);
        vbdHeader("xX_Pro_Counter_Xx");

        top->clk = 1;
        top->rst = 1;
        top->en = 1;
        top->incr = 1;
        top->dout = 0;

        for(i=0; i<1 000 000; i++) {

            for(clk=0; clk<2; clk++){
                tfp->dump (2*i+clk);
                top->clk = !top->clk;
                top->eval ();
            }
            
            vbdCycle(i+1);
            
            vbdPlot(int(top->dout), 0, 255);
            
            
            top->rst = (i<2) | (i == 15);
            top->ld = vbdFlag();
            if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
                exit(0);
        }

        vbdClose();
        tfp->close();
        exit(0); 
    }g