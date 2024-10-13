// /* 时间定时器 */

// /* 时间定时器 */

// #include <STC89C5xRC.H>
// #include <stddef.h>

// typedef unsigned int u16;
// typedef unsigned char u8;
// typedef void (*Callback_Function)();

// static u16 Time_Counter = 0;
// static u8 Sw1_Status = 0xFF;  // 指定类型

// #define SMG_EN             P36
// #define LED_EN             P34
// #define FOSC               11059200 // 晶振频率
// #define NT                 12       // 单片机的工作周期为12
// #define T1MS               (65536 - FOSC / NT / 1000)
// #define Max_Callback_Count 4
// #define Sw1                P42
// static Callback_Function Timer0_Callback_Array[Max_Callback_Count];

// void Delay100us(int a);
// void Timer_initialization();
// void Registering_Functions(Callback_Function callback);
// bit Unregistration_Function();
// void Timer_trigger();
// void Detecting_Buttons();
// u8 Return_Buttons();
// void Change_Buttons();  // 修复：缺少分号

// void main()
// {

//     u8 sw;
//     Timer_initialization();
//     Detecting_Buttons();

//     while (1)
//     {
//         sw = Return_Buttons();
//         if (sw == 0xFF)
//         {
//             P00 = 1;
//         }
//         else if (sw == 0x00)
//         {
//            P00 = 0;
//         }

//     }
// }
// // 检测按键的值
// void Detecting_Buttons()
// {
//     Registering_Functions(Change_Buttons);
// }
// // 返回按键的值
// u8  Return_Buttons()
// {

//     return Sw1_Status;
// }
// // 变化按键的值
// void Change_Buttons()
// {
//     // 设置初值
//     /*
//     Sw1_Status 每一毫秒检测一次 当 为0xFF表是抬起
//                                     0x00表示被按下
//                                     中间状态表示在抖动
//     定时中断器每隔一毫秒就检测一次，
//      */
//     Sw1_Status <<= 1;
//     Sw1_Status = Sw1_Status | Sw1;
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
//             (*Timer0_Callback_Array[i])();
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
// /* 时钟定时器驱动 */
// void Timer_initialization()
// {
//     u8 i;
//     EA = 1;
//     // 定时器中断的开关
//     ET0 = 1;
//     TR0 = 1; // 启动定时器0
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