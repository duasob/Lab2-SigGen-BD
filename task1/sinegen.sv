module sinegen #(
  parameter WIDTH = 8
)(
  // interface signals
  input  logic             clk,      // clock 
  input  logic             rst,      // reset 
  input  logic             en,       // enable
  input  logic [WIDTH-1:0] incr,        // value to preload
  output logic [7:0]       dout       // count output
);

  logic  [WIDTH-1:0]       addr;    // interconnect wire

counter myCounter (
  .clk (clk),
  .rst (rst),
  .en (en),
  .incr(incr),
  .count (addr)
);

rom myRom (
  .clk(clk),
  .addr (addr),
  .dout (dout)
);

endmodule
