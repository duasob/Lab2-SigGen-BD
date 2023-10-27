// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcounter__Syms.h"


//======================

void Vcounter::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vcounter::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vcounter::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vcounter::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vcounter::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"rst", false,-1);
        tracep->declBit(c+3,"en", false,-1);
        tracep->declBus(c+4,"incr", false,-1, 7,0);
        tracep->declBus(c+5,"dout", false,-1, 7,0);
        tracep->declBus(c+7,"sinegen WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"sinegen clk", false,-1);
        tracep->declBit(c+2,"sinegen rst", false,-1);
        tracep->declBit(c+3,"sinegen en", false,-1);
        tracep->declBus(c+4,"sinegen incr", false,-1, 7,0);
        tracep->declBus(c+5,"sinegen dout", false,-1, 7,0);
        tracep->declBus(c+6,"sinegen addr", false,-1, 7,0);
        tracep->declBus(c+7,"sinegen myCounter WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"sinegen myCounter clk", false,-1);
        tracep->declBit(c+2,"sinegen myCounter rst", false,-1);
        tracep->declBit(c+3,"sinegen myCounter en", false,-1);
        tracep->declBus(c+4,"sinegen myCounter incr", false,-1, 7,0);
        tracep->declBus(c+6,"sinegen myCounter count", false,-1, 7,0);
        tracep->declBus(c+7,"sinegen myRom ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+7,"sinegen myRom DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"sinegen myRom clk", false,-1);
        tracep->declBus(c+6,"sinegen myRom addr", false,-1, 7,0);
        tracep->declBus(c+5,"sinegen myRom dout", false,-1, 7,0);
    }
}

void Vcounter::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vcounter::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vcounter::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullBit(oldp+2,(vlTOPp->rst));
        tracep->fullBit(oldp+3,(vlTOPp->en));
        tracep->fullCData(oldp+4,(vlTOPp->incr),8);
        tracep->fullCData(oldp+5,(vlTOPp->dout),8);
        tracep->fullCData(oldp+6,(vlTOPp->sinegen__DOT__addr),8);
        tracep->fullIData(oldp+7,(8U),32);
    }
}
