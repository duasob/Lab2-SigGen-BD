module sinegen #(
  parameter WIDTH = 8
)(
  // interface signals
  input  logic             clk,      // clock 
  input  logic             rst,      // reset 
  input  logic             en,       // enable
  input  logic [WIDTH-1:0] incr,        // value to preload
  output logic [7:0]       dout1,
  output logic [7:0]       dout2      // count output
);

  logic  [WIDTH-1:0]       addr1;    // interconnect wire
  logic  [WIDTH-1:0]       addr2; 
counter myCounter (
  .clk (clk),
  .rst (rst),
  .en (en),
  .incr(incr),
  .count1 (addr1),
  .count2 (addr2)
);

rom myRom (
  .clk(clk),
  .addr1(addr1),
  .addr2(addr2),
  .dout1(dout1),
  .dout2(dout2)
);

endmodule
