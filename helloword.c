```
#include <stdio.h>
#include "xparameters.h"
#include "xgpio.h"

// 延遲時間設定
#define DEFAULT_DELAY 150
#define FAST_DELAY 40

// 延遲函數
void delay(int dly)
{
    int i, j;
    for (i = 0; i < dly; i++) {
        for (j = 0; j < 0xffff; j++) {}
    }
}

int main()
{
    XGpio gpio_led, gpio_sw;
    u8 led_val = 0x01;  // 初始從 LED0 開始 (0b0000_0001)
    int delay_time = DEFAULT_DELAY;

    // 初始化 AXI GPIO
    XGpio_Initialize(&gpio_led, XPAR_AXI_GPIO_0_DEVICE_ID);  // LED 輸出
    XGpio_Initialize(&gpio_sw,  XPAR_AXI_GPIO_1_DEVICE_ID);  // SW 輸入

    XGpio_SetDataDirection(&gpio_led, 1, 0x00); // 通道 1 為輸出
    XGpio_SetDataDirection(&gpio_sw, 1, 0xFF);  // 通道 1 為輸入

    while (1) {
        u32 sw = XGpio_DiscreteRead(&gpio_sw, 1);
        int dir = sw & 0x01;        // SW0: 控制方向
        int fast = (sw >> 1) & 0x01; // SW1: 控制速度

        delay_time = fast ? FAST_DELAY : DEFAULT_DELAY;

        // 輸出目前 LED pattern
        XGpio_DiscreteWrite(&gpio_led, 1, led_val);

        // 控制方向
        if (dir == 0) {
            // 正向：從 LED0 → LED7
            led_val <<= 1;
            if (led_val == 0x00) led_val = 0x01;
        } else {
            // 反向：從 LED7 → LED0
            led_val >>= 1;
            if (led_val == 0x00) led_val = 0x80;
        }

        delay(delay_time);
    }

    return 0;
}
```
