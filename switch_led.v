module switch_led (
    input  wire [7:0] i_sw,        // 來自開關，bit 0 決定方向
    input  wire [7:0] i_led_in,    // PS 傳來 LED pattern
    output wire [7:0] o_led_out    // 最終輸出 LED
);
    assign o_led_out = i_led_in;
endmodule
