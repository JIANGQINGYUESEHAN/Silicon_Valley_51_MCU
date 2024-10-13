// /* 计算器 */

// #include <STC89C5xRC.H>
// typedef unsigned int u16;
// typedef unsigned char u8;
// #define SMG_EN P36
// #define LED_EN P34
// #define KEYIN  P2
// void Static_Digital_Tube1(u16 a, u8 b);

// void Digital_Number(int digtail);
// void Digital_Show_Refresh();
// u16 Key_Matrix_Driver();
// static u8 s_digit_codes[10] = {
//     0x3F, // 0
//     0x06, // 1
//     0x5B, // 2
//     0x4F, // 3
//     0x66, // 4
//     0x6D, // 5
//     0x7D, // 6
//     0x07, // 7
//     0x7F, // 8
//     0x6F  // 9
// };

// static u8 Digital_Number_Buffer[8];

// void Delay100us(int a);
// void Init();
// void main()
// {
//     u16 KeyNumber;
//     u16 n1                   = 0; // 使用 u16 来存储多位数
//     u16 n2                   = 0; // 使用 u16 来存储多位数
//     bit computation_complete = 0;
//     bit isEnteringN1         = 1; // n1 输出完成标识
//     u16 operator= 0;              // 使用 u16 来存储操作符
//     Init();
//     Digital_Number(0);

//     while (1)
//     {
//         KeyNumber = Key_Matrix_Driver();

//         // 判断是否输入了数字
//         if (KeyNumber <= 9 && KeyNumber >= 0)
//         {
//             if (isEnteringN1)
//             {
//                 // 输入第一个数字 n1
//                 n1 = (n1 * 10) + KeyNumber;
//                 Digital_Number(n1); // 显示 n1
//             }
//             else
//             {
//                 // 输入第二个数字 n2
//                 n2 = (n2 * 10) + KeyNumber;
//                 Digital_Number(n2); // 显示 n2
//             }
//         }
//         // 判断是否输入了操作符
//         else if (KeyNumber >= 10 && KeyNumber <= 40)
//         {
//             // 关闭 n1 输入，开始记录符号
//             isEnteringN1 = 0;
//             operator= KeyNumber; // 记录操作符
//         }
//         // 当检测到 "等于" 键时（假设 50 代表 "等于"）
//         else if (KeyNumber == 50)
//         {
//             // 根据操作符进行计算
//             switch (operator)
//             {
//                 case 10: // 假设 10 代表加号
//                     n1 = n1 + n2;
//                     break;
//                 case 20: // 假设 20 代表减号
//                     n1 = n1 - n2;
//                     break;
//                 case 30: // 假设 20 代表减号
//                     n1 = n1 * n2;
//                     break;
//                 case 40: // 假设 20 代表减号
//                     n1 = n1 / n2;
//                     break;
//                 default:
//                     break;
//             }
//             // 显示计算结果
//             Digital_Number(n1);
//             Digital_Show_Refresh();
//             // 重置所有标志，准备下一轮输入
//             n2 = 0;
//             operator= 0;
//             isEnteringN1 = 1; // 回到输入 n1 的状态
//         }

//         Digital_Show_Refresh(); // 刷新显示
//     }
// }

// void Init()
// {
//     SMG_EN = 0;
//     LED_EN = 0;
// }

// /* 按键矩阵驱动 */
// u16 Key_Matrix_Driver()
// { // 初始为 1按下为 1
//     // 设计初始值,先设置第一行有按键被按下
//     // 将P20置0
//     // 没有按键被按下

//     // 将P20置0
//     KEYIN = 0xFE;
//     if (KEYIN == 0xEE)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0xEE)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFE)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFE)
//                         return 7;
//                 }
//             }
//         }
//     }
//     if (KEYIN == 0xDE)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0xDE)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFE)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFE)
//                         return 8;
//                 }
//             }
//         }
//     }
//     if (KEYIN == 0xBE)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0xBE)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFE)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFE)
//                         return 9;
//                 }
//             }
//         }
//     }
//     if (KEYIN == 0x7E)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0x7E)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFE)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFE)
//                         return 10;
//                 }
//             }
//         }
//     }
//     KEYIN = 0xFD;
//     if (KEYIN == 0xED)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0xED)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFD)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFD)
//                         return 4;
//                 }
//             }
//         }
//     }
//     if (KEYIN == 0xDD)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0xDD)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFD)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFD)
//                         return 5;
//                 }
//             }
//         }
//     }
//     if (KEYIN == 0xBD)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0xBD)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFD)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFD)
//                         return 6;
//                 }
//             }
//         }
//     }
//     if (KEYIN == 0x7D)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0x7D)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFD)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFD)
//                         return 20;
//                 }
//             }
//         }
//     }

//     KEYIN = 0xFB;
//     if (KEYIN == 0xEB)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0xEB)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFB)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFB)
//                         return 1;
//                 }
//             }
//         }
//     }
//     if (KEYIN == 0xDB)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0xDB)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFB)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFB)
//                         return 2;
//                 }
//             }
//         }
//     }
//     if (KEYIN == 0xBB)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0xBB)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFB)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFB)
//                         return 3;
//                 }
//             }
//         }
//     }
//     if (KEYIN == 0x7B)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0x7B)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xFB)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xFB)
//                         return 30;
//                 }
//             }
//         }
//     }

//     KEYIN = 0xF7;
//     if (KEYIN == 0xE7)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0xE7)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xF7)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xF7)
//                         return 50;
//                 }
//             }
//         }
//     }
//     if (KEYIN == 0xD7)
//     {                   // 检测 0 键按下
//         Delay100us(10); // 消抖
//         if (KEYIN == 0xD7)
//         {
//             while (KEYIN != 0xF7)
//             {                   // 等待按键抬起
//                 Delay100us(10); // 再次消抖
//             }
//             return 0; // 返回 0 键
//         }
//     }
//     if (KEYIN == 0xB7)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0xB7)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xF7)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xF7)
//                         return 60;
//                 }
//             }
//         }
//     }
//     if (KEYIN == 0x77)
//     {
//         // 消抖
//         Delay100us(10);
//         if (KEYIN == 0x77)
//         {
//             // SW5被按下了，等待按键抬起，返回5
//             while (1)
//             {
//                 if (KEYIN == 0xF7)
//                 {
//                     // 按键有可能被抬起，消抖
//                     Delay100us(10);
//                     if (KEYIN == 0xF7)
//                         return 40;
//                 }
//             }
//         }
//     }
//     // 没有按键被按下
//     return 255;
// }

// /* 对输入数字的处理 */
// void Digital_Number(int digtail)
// {
//     u8 i;
//     // 对数组进行初始化，确保缓冲区清空
//     for (i = 0; i < 8; i++)
//     {
//         Digital_Number_Buffer[i] = 0;
//     }

//     // 对 0 的处理
//     if (digtail == 0)
//     {
//         Digital_Number_Buffer[7] = s_digit_codes[0];
//         return;
//     }

//     // 对正常数字的处理
//     i = 7;
//     while (digtail > 0 && i >= 0)
//     {
//         Digital_Number_Buffer[i] = s_digit_codes[digtail % 10];
//         digtail                  = digtail / 10;
//         i--;
//     }
// }
// /* 对数码管的刷新 */
// void Digital_Show_Refresh()
// {
//     u8 i;
//     for (i = 0; i < 8; i++)
//     {
//         Static_Digital_Tube1(i, Digital_Number_Buffer[i]);
//         Delay100us(1);
//     }
// }
// /* 数码管驱动 */
// void Static_Digital_Tube1(u16 a, u8 b)
// {
//     // 关掉当前数码管
//     P0 = 0;
//     // 完成片选
//     // 置零
//     P1 &= 0xC7;
//     // 左移
//     a <<= 3;
//     P1 |= a;

//     // 段选
//     P0 = b;
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