module sigdelay #(
  parameter WIDTH = 8
)(
  // interface signals
  input  logic                        clk,       
  input  logic                        rst,       
  input  logic                        en,       
  input  logic [WIDTH-1:0]            offset,
  input logic                         wr,
  input logic                         rd,
  input logic  [WIDTH-1:0]            wr_addr,
  input logic  [WIDTH-1:0]            rd_addr,
  input logic  [WIDTH-1:0]            mic_signal,        
  output logic [7:0]                  delayed_signal
);

  logic  [WIDTH-1:0]       addr1;    
  logic  [WIDTH-1:0]       addr2; 

counter myCounter (
  .clk (clk),
  .rst (rst),
  .en (en),
  .incr(offset),
  .count1 (addr1),
  .count2 (addr2)
);

ram myRam (
  .wr_addr(addr2),
  .rd_addr(addr1),
  .wr_en(wr),
  .rd_en(rd),
  .dout(delayed_signal),
  .din(mic_signal),
  .clk(clk)
);

endmodule
