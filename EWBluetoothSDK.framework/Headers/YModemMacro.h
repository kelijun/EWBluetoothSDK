//
//  YModemMacro.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/10/21.
//

#ifndef YModemMacro_h
#define YModemMacro_h

#define YMODEM_SOH                 0x01 // 133字节长度
#define YMODEM_STX                 0x02 // 1024字节长度
#define YMODEM_EOT                 0x04 // 文件传输结束命令
#define YMODEM_END                 0x05 // 文件传输结束命令
#define YMODEM_ACK                 0x06 // 接收正确应答命令
#define YMODEM_NAK                 0x15 // 重传当前数据包请求命令
#define YMODEM_CAN                 0x18 // 取消传输命令，需连发5次
#define YMODEM_C                   0x43 // 字符C
#define YMODEM_PACKET_SIZE         128  // 一帧大小
#define YMODEM_PACKET_FIRST_SIZE   133  // 第一帧大小
#define YMODEM_DATA_PACKET_SIZE    1024 // 一帧大小
#endif /* YModemMacro_h */
