// /* 时间定时器 */

// #include <STC89C5xRC.H>
// #include <stddef.h>
// typedef unsigned int u16;
// typedef unsigned char u8;
// typedef void (*Callback_Function)();
// #define SMG_EN             P36
// #define LED_EN             P34
// #define FOSC               11059200 // 晶振频率
// #define NT                 12       // 单片机的工作周期为12
// #define T1MS               (65536 - FOSC / NT / 1000)
// #define Max_Callback_Count 4

// static u16 Time_Counter=       0;
// static Callback_Function Timer0_Callback_Array[Max_Callback_Count];

// void Delay100us(int a);
// void  Registering_Functions(Callback_Function callback);
// bit Unregistration_Function();
// void Timer_trigger();
// void ToggleLED();
// // 外部定时器初始化

// void Timer_initialization()
// {
//     u8 i;
//     EA = 1;
//     // 定时器中断的开关
//     ET0 = 1;
//      TR0 = 1;  // 启动定时器0
//     // 设置定时器0的工作模式：16位定时器
//     TMOD &= 0xF0;
//     TMOD |= 0x01;

//     // 设置定时器的初始值
//     TL0 = T1MS;
//     TH0 = T1MS >> 8;
//     // 定时函数初始化
//     for (i = 0; i < Max_Callback_Count; i++)
//     {
//         Timer0_Callback_Array[i] = NULL;
//     }
// }

// void main()
// {

//     Timer_initialization();
//     Registering_Functions(ToggleLED);
//     while (1)
//     {

//     }
// }

// void ToggleLED()
// {
//     Time_Counter++;
//     // 每500ms切换LED亮灭
//     if (Time_Counter == 500)
//     {
//         Time_Counter = 0;
//         P00          = ~P00;
//     }
// }


// // 反注册
// bit Unregistration_Function()
// {

//     u8 i;
//     for (i = 0; i < Max_Callback_Count; i++)
//     {
//         if (Timer0_Callback_Array[i] != NULL)
//         {
//             Timer0_Callback_Array[i] = NULL;
//         }
//     }
// }
// // 注册函数
// void Registering_Functions(Callback_Function callback)
// {
//     u8 i;
//     for (i = 0; i < Max_Callback_Count; i++)
//     {
//         if (Timer0_Callback_Array[i] == NULL)
//         {
//             Timer0_Callback_Array[i] = callback;
            
//         }
//     }
    
// }
// // 时钟定时器
// void Timer_trigger() interrupt 1
// {
//     u8 i;
 
//     TL0 = T1MS;
//     TH0 = T1MS >> 8;
//     // 调用回调函数

//     for (i = 0; i < Max_Callback_Count; i++)
//     {
//         if (Timer0_Callback_Array[i] != NULL)
//         {
//            (*Timer0_Callback_Array[i])(); 
//         }
//     }
// }
// void Delay100us(int a)
// { // @11.0592MHz
//     while (a > 0)
//     { // 修正为 a > 0
//         unsigned char i, j;
//         i = 2;  // 外层循环
//         j = 15; // 内层循环
//         do {
//             while (--j); // 内层循环
//         } while (--i); // 外层循环
//         a--;
//     }
// }