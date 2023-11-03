// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsinegen__Syms.h"


void Vsinegen::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vsinegen__Syms* __restrict vlSymsp = static_cast<Vsinegen__Syms*>(userp);
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vsinegen::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vsinegen__Syms* __restrict vlSymsp = static_cast<Vsinegen__Syms*>(userp);
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk));
        tracep->chgBit(oldp+1,(vlTOPp->rst));
        tracep->chgBit(oldp+2,(vlTOPp->en));
        tracep->chgCData(oldp+3,(vlTOPp->incr),8);
        tracep->chgCData(oldp+4,(vlTOPp->dout),8);
        tracep->chgCData(oldp+5,(vlTOPp->sinegen__DOT__addr),8);
    }
}

void Vsinegen::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vsinegen__Syms* __restrict vlSymsp = static_cast<Vsinegen__Syms*>(userp);
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
