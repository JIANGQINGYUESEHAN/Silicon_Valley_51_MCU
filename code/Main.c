/* 时间定时器  改造数码管*/

#include <STC89C5xRC.H>
#include <stddef.h>

typedef unsigned int u16;
typedef unsigned char u8;
typedef void (*Callback_Function)();

static u16 Time_Counter = 0;
static u8 Sw1_Status    = 0xFF; // 指定类型

#define SMG_EN             P36
#define LED_EN             P34
#define FOSC               11059200 // 晶振频率
#define NT                 12       // 单片机的工作周期为12
#define T1MS               (65536 - FOSC / NT / 1000)
#define Max_Callback_Count 4
#define Sw1                P42
void Static_Digital_Tube1(u16 a, u8 b);

void Digital_Number(int digtail);
void Digital_Show_Refresh();

static u8 s_digit_codes[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

static u8 Digital_Number_Buffer[8];
static Callback_Function Timer0_Callback_Array[Max_Callback_Count];
static u8 Digital_Tube_Position = 0;
void Delay100us(int a);
void Timer_initialization();
void Registering_Functions(Callback_Function callback);

void Timer_trigger();
void Timing_Digital_Drive_Initialization();
void Init();
void main()
{
    u16 i = 100;
    Init();
    Timer_initialization();
    Timing_Digital_Drive_Initialization();
    // 显示数字
    Digital_Number(i);

    while (1)
    {
        Delay100us(1000); // 可以适当延时
        if (i > 0)
        {
            Digital_Number(i);
            i--;
        }
    }
}


void Init()
{
    SMG_EN = 0;
    LED_EN = 0;
}

/* 延时 */
void Delay100us(int a)
{ // @11.0592MHz
    while (a > 0)
    { // 修正为 a > 0
        unsigned char i, j;
        i = 2;  // 外层循环
        j = 15; // 内层循环
        do {
            while (--j); // 内层循环
        } while (--i); // 外层循环
        a--;
    }
}
/* 数码管驱动 */
void Digital_Number(int digtail)
{
    u8 i;
    // 对数组进行初始化，确保缓冲区清空
    for (i = 0; i < 8; i++)
    {
        Digital_Number_Buffer[i] = 0;
    }

    // 对 0 的处理
    if (digtail == 0)
    {
        Digital_Number_Buffer[7] = s_digit_codes[0];
        return;
    }

    // 对正常数字的处理
    i = 7;
    while (digtail > 0 && i >= 0)
    {
        Digital_Number_Buffer[i] = s_digit_codes[digtail % 10];
        digtail                  = digtail / 10;
        i--;
    }
}
/* 对数码管的刷新 */
void Digital_Show_Refresh()
{
    Digital_Tube_Position++;
    // Static_Digital_Tube1(Digital_Tube_Position, s_digit_codes[Digital_Tube_Position]);
       Static_Digital_Tube1(Digital_Tube_Position, Digital_Number_Buffer[Digital_Tube_Position]);
    if (Digital_Tube_Position == 8)
    {
        Digital_Tube_Position = 0;
    }
}

void Timing_Digital_Drive_Initialization()
{
    Digital_Tube_Position = 0;
    // 在这里不断调用
    Registering_Functions(Digital_Show_Refresh);
}
/* 数码管驱动 */
void Static_Digital_Tube1(u16 a, u8 b)
{
    // 关掉当前数码管
    P0 = 0;
    // 完成片选
    // 置零
    P1 &= 0xC7;
    // 左移
    a <<= 3;
    P1 |= a;

    // 段选
    P0 = b;
}

/* 时钟定时器 */
void Timer_trigger()
    interrupt 1
{
    u8 i;

    TL0 = T1MS;
    TH0 = T1MS >> 8;
    // 调用回调函数

    for (i = 0; i < Max_Callback_Count; i++)
    {
        if (Timer0_Callback_Array[i] != NULL)
        {
            (*Timer0_Callback_Array[i])();
        }
    }
}
// 注册函数
void Registering_Functions(Callback_Function callback)
{
    u8 i;
    for (i = 0; i < Max_Callback_Count; i++)
    {
        if (Timer0_Callback_Array[i] == NULL)
        {
            Timer0_Callback_Array[i] = callback;
        }
    }
}

/* 时钟定时器驱动 */
void Timer_initialization()
{
    u8 i;
    EA = 1;
    // 定时器中断的开关
    ET0 = 1;
    TR0 = 1; // 启动定时器0
    // 设置定时器0的工作模式：16位定时器
    TMOD &= 0xF0;
    TMOD |= 0x01;

    // 设置定时器的初始值
    TL0 = T1MS;
    TH0 = T1MS >> 8;
    // 定时函数初始化
    for (i = 0; i < Max_Callback_Count; i++)
    {
        Timer0_Callback_Array[i] = NULL;
    }
}