# SOC_HW1
實作影片:
## 功能介紹
用SW0控制跑馬燈方向，SW1控制跑馬燈速度  
SW0 OFF時LED由0~7依序亮起；SW0 ON時則相反  
SW1 ON時跑馬燈加速；SW1 OFF時跑馬燈速度恢復正常  
## Block design
![image](https://github.com/user-attachments/assets/135096f3-4e69-4c4b-a040-3f750d33f34e)
## 硬體規格
開發版: EGO-XZ7（Zynq-7000 SoC，型號：XC7Z020CLG484-1)  
處理器: ARM Cortex-A9雙硬核  
## 軟體內容
Vivado 2018.3:硬體設計與綜合  
Xilinx SDk2018.3:開發軟體並控制 PS  
