// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen.h for the primary calling header

#include "Vsinegen.h"
#include "Vsinegen__Syms.h"

//==========

void Vsinegen::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsinegen::eval\n"); );
    Vsinegen__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sinegen.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsinegen::_eval_initial_loop(Vsinegen__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sinegen.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vsinegen::_sequent__TOP__1(Vsinegen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen::_sequent__TOP__1\n"); );
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__sinegen__DOT__addr1;
    // Body
    __Vdly__sinegen__DOT__addr1 = vlTOPp->sinegen__DOT__addr1;
    vlTOPp->dout1 = vlTOPp->sinegen__DOT__myRom__DOT__rom_array
        [vlTOPp->sinegen__DOT__addr1];
    vlTOPp->dout2 = vlTOPp->sinegen__DOT__myRom__DOT__rom_array
        [vlTOPp->sinegen__DOT__addr2];
    if (vlTOPp->rst) {
        __Vdly__sinegen__DOT__addr1 = 0U;
        vlTOPp->sinegen__DOT__addr2 = 0U;
    } else {
        __Vdly__sinegen__DOT__addr1 = (0xffU & ((IData)(vlTOPp->sinegen__DOT__addr1) 
                                                + (IData)(vlTOPp->en)));
        vlTOPp->sinegen__DOT__addr2 = (0xffU & ((IData)(vlTOPp->sinegen__DOT__addr1) 
                                                + (IData)(vlTOPp->incr)));
    }
    vlTOPp->sinegen__DOT__addr1 = __Vdly__sinegen__DOT__addr1;
}

void Vsinegen::_eval(Vsinegen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen::_eval\n"); );
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vsinegen::_change_request(Vsinegen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen::_change_request\n"); );
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vsinegen::_change_request_1(Vsinegen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen::_change_request_1\n"); );
    Vsinegen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vsinegen::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
