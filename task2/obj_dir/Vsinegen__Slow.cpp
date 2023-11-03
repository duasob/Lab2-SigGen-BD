// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen.h for the primary calling header

#include "Vsinegen.h"
#include "Vsinegen__Syms.h"

//==========

VL_CTOR_IMP(Vsinegen) {
    Vsinegen__Syms* __restrict vlSymsp = __VlSymsp = new Vsinegen__Syms(this, name());
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vsinegen::__Vconfigure(Vsinegen__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vsinegen::~Vsinegen() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vsinegen::_initial__TOP__2(Vsinegen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen::_initial__TOP__2\n"); );
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp1[3];
    // Body
    VL_WRITEF("Loading rom.\n");
    __Vtemp1[0U] = 0x2e6d656dU;
    __Vtemp1[1U] = 0x65726f6dU;
    __Vtemp1[2U] = 0x73696eU;
    VL_READMEM_N(true, 8, 256, 0, VL_CVT_PACK_STR_NW(3, __Vtemp1)
                 , vlTOPp->sinegen__DOT__myRom__DOT__rom_array
                 , 0, ~0ULL);
}

void Vsinegen::_eval_initial(Vsinegen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen::_eval_initial\n"); );
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void Vsinegen::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen::final\n"); );
    // Variables
    Vsinegen__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsinegen::_eval_settle(Vsinegen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen::_eval_settle\n"); );
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsinegen::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    en = VL_RAND_RESET_I(1);
    incr = VL_RAND_RESET_I(8);
    dout1 = VL_RAND_RESET_I(8);
    dout2 = VL_RAND_RESET_I(8);
    sinegen__DOT__addr1 = VL_RAND_RESET_I(8);
    sinegen__DOT__addr2 = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            sinegen__DOT__myRom__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
