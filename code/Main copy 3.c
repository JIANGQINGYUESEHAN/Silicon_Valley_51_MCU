// /* 外部定时器 */

// #include <STC89C5xRC.H>
// typedef unsigned int u16;
// typedef unsigned char u8;
// #define SMG_EN P36
// #define LED_EN P34

// void Delay100us(int a);
// void Init();
// void Timer_trigger();
// // 外部定时器初始化

// Timer_initialization()
// {
//     // 定时器总开关
//     EA = 1;
//     // 打开定时器
//     EX0 = 1;
//     // 下降沿触发
//     IT0 = 1;
// }

// void main()
// {

//     Timer_initialization();
//     while (1)
//     {
//     }
// }
// void Timer_trigger() interrupt 0
// {
//     Delay100us(10);
//     P00 = ~P00;
// }

// // 外部定时器
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