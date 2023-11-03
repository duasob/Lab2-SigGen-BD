module counter #(
    parameter WIDTH = 8
)(

    input   logic               clk,
    input   logic               rst,
    input   logic               en,
    input  logic [WIDTH-1:0]    incr,
    output  logic  [WIDTH-1:0]  count1,
    output  logic  [WIDTH-1:0]  count2
);

always_ff @ (posedge clk) begin
  if (rst) 
    count <= {WIDTH{1'b0}};
  else     
    count <= incr*en + count;
end
endmodule
