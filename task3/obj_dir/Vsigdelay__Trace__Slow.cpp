// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsigdelay__Syms.h"


//======================

void Vsigdelay::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vsigdelay::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vsigdelay::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vsigdelay::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vsigdelay::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"rst", false,-1);
        tracep->declBit(c+3,"en", false,-1);
        tracep->declBus(c+4,"offset", false,-1, 7,0);
        tracep->declBit(c+5,"wr", false,-1);
        tracep->declBit(c+6,"rd", false,-1);
        tracep->declBus(c+7,"wr_addr", false,-1, 7,0);
        tracep->declBus(c+8,"rd_addr", false,-1, 7,0);
        tracep->declBus(c+9,"mic_signal", false,-1, 7,0);
        tracep->declBus(c+10,"delayed_signal", false,-1, 7,0);
        tracep->declBus(c+13,"sigdelay WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"sigdelay clk", false,-1);
        tracep->declBit(c+2,"sigdelay rst", false,-1);
        tracep->declBit(c+3,"sigdelay en", false,-1);
        tracep->declBus(c+4,"sigdelay offset", false,-1, 7,0);
        tracep->declBit(c+5,"sigdelay wr", false,-1);
        tracep->declBit(c+6,"sigdelay rd", false,-1);
        tracep->declBus(c+7,"sigdelay wr_addr", false,-1, 7,0);
        tracep->declBus(c+8,"sigdelay rd_addr", false,-1, 7,0);
        tracep->declBus(c+9,"sigdelay mic_signal", false,-1, 7,0);
        tracep->declBus(c+10,"sigdelay delayed_signal", false,-1, 7,0);
        tracep->declBus(c+11,"sigdelay addr1", false,-1, 7,0);
        tracep->declBus(c+12,"sigdelay addr2", false,-1, 7,0);
        tracep->declBus(c+13,"sigdelay myCounter WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"sigdelay myCounter clk", false,-1);
        tracep->declBit(c+2,"sigdelay myCounter rst", false,-1);
        tracep->declBit(c+3,"sigdelay myCounter en", false,-1);
        tracep->declBus(c+4,"sigdelay myCounter incr", false,-1, 7,0);
        tracep->declBus(c+11,"sigdelay myCounter count1", false,-1, 7,0);
        tracep->declBus(c+12,"sigdelay myCounter count2", false,-1, 7,0);
        tracep->declBus(c+13,"sigdelay myRam ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+13,"sigdelay myRam DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"sigdelay myRam clk", false,-1);
        tracep->declBit(c+5,"sigdelay myRam wr_en", false,-1);
        tracep->declBit(c+6,"sigdelay myRam rd_en", false,-1);
        tracep->declBus(c+12,"sigdelay myRam wr_addr", false,-1, 7,0);
        tracep->declBus(c+11,"sigdelay myRam rd_addr", false,-1, 7,0);
        tracep->declBus(c+9,"sigdelay myRam din", false,-1, 7,0);
        tracep->declBus(c+10,"sigdelay myRam dout", false,-1, 7,0);
    }
}

void Vsigdelay::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vsigdelay::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vsigdelay::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullBit(oldp+2,(vlTOPp->rst));
        tracep->fullBit(oldp+3,(vlTOPp->en));
        tracep->fullCData(oldp+4,(vlTOPp->offset),8);
        tracep->fullBit(oldp+5,(vlTOPp->wr));
        tracep->fullBit(oldp+6,(vlTOPp->rd));
        tracep->fullCData(oldp+7,(vlTOPp->wr_addr),8);
        tracep->fullCData(oldp+8,(vlTOPp->rd_addr),8);
        tracep->fullCData(oldp+9,(vlTOPp->mic_signal),8);
        tracep->fullCData(oldp+10,(vlTOPp->delayed_signal),8);
        tracep->fullCData(oldp+11,(vlTOPp->sigdelay__DOT__addr1),8);
        tracep->fullCData(oldp+12,(vlTOPp->sigdelay__DOT__addr2),8);
        tracep->fullIData(oldp+13,(8U),32);
    }
}
