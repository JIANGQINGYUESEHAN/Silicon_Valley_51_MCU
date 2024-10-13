// #include <STC89C5xRC.H>
// typedef unsigned int u16;
// typedef unsigned char u8;

// void FlowingLights();
// void Delay100us(int a);

// void main()
// {
//     while (1)
//     {
//         FlowingLights();
//     }
// }
// void FlowingLights()
// {
//     u8 temp = 1;
//     u8 i;

//     for (i = 0; i < 8; i++)//0点亮，默认低电平
//     {
      
//         P0 = ~temp;
//         //temp 0000 0001
//         //P0=11111110

//         Delay100us(500); // 延时保持亮

//         // 点第一个灯
//         temp <<= 1;
//         if(temp==0){
//             temp=1;
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