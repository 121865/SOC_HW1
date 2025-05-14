#include <stdio.h>
#include "xparameters.h"
#include "xil_io.h"
#include "sleep.h"

int main() {
    print("ZYNQ AXI + PL 跑馬燈已啟動。\n");
    print("SW0 控制方向（OFF: 0→7, ON: 7→0）\n");
    print("SW1 控制速度（OFF: 正常, ON: 快速）\n");

    while (1) {
        // 這裡不用對 AXI IP 做任何寫入
        // 所有 LED 控制邏輯已經在 PL (Verilog) 中根據 SW 直接完成
        sleep(1);  // idle 等待
    }

    return 0;
}
