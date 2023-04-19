//
//  EWDataUtils.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/10/19.
//

#import <Foundation/Foundation.h>
#import "YModemMacro.h"

NS_ASSUME_NONNULL_BEGIN


@interface EWDataUtils : NSObject
/// 将数据分为指定长度的数组
/// - Parameters:
///   - sourceData: 原数据
///   - length: 一包长度
+ (NSArray *)automaticUnpackForSourceData:(NSData *)sourceData packetLength:(NSUInteger)length;

/// 将数据分为指定长度的数组
/// - Parameters:
///   - sourceData: 原数据
///   - length: 一包长度
+ (NSArray *)automaticUnpackForFilePath:(NSString *)path packetLength:(NSUInteger)length;

#pragma mark - CRC16XMODEM 校验
/// CRC16-XMODEM 校验
/// - Parameters:
///   - data: 数据
///   - length: 长度
+ (uint16_t)CRC16XMODEMByteCalc:(const uint8_t *)byte byteLength:(uint8_t)length;

/// CRC16-XMODEM 校验
/// - Parameters:
///   - data: 数据
///   - length: 长度
+ (uint16_t)CRC16XMODEMDataCalc:(NSData *)data dataLength:(NSUInteger)length;

/// 获取 CRC16-XMODEM 校验高低位
/// - Parameters:
///   - data: 数据
///   - length: 长度
+ (NSData *)getCheckBitByCRC16XMODEMByteCalc:(const uint8_t *)byte byteLength:(uint8_t)length;

/// 获取 CRC16-XMODEM 校验高低位
/// - Parameters:
///   - data: 数据
///   - length: 长度
+ (NSData *)getCheckBitByCRC16XMODEMDataCalc:(NSData *)data byteLength:(NSUInteger)length;

/// CRC32 校验
/// - data: 数据
+ (uint16_t)CRC32DataCalc:(NSData *)data;

+ (int32_t)crc32ForBinFile:(NSData *)binData;

+ (NSString *)getMD5Str:(NSString *)str;
#pragma mark - YModem数据
/// 获取YModem第一帧数据
/// - Parameter filePath: 文件路径
+ (NSData *)getYModemFirstFrameDataWithFilePath:(NSString *)filePath;

/// 获取YModem所有帧的数据
/// - Parameter filePath: 文件路径
+ (NSArray *)getYModemAllFramesDataWithFilePath:(NSString *)filePath;

/// 获取YModem结束帧数据
/// - Parameter filePath: 文件路径
+ (NSData *)getYModemEndFrameDataWithFilePath:(NSString *)filePath;

#pragma mark - 字节转换
/// 十六进制转字节
/// - Parameter data: 整型数据
+ (Byte)intTobyte:(int)data;

/// 字节转十六进制
/// - Parameter data: 字节
+ (int)byteToint:(Byte)data;

/// 获取数据指定位置字节
/// - Parameters:
///   - data: 数据
///   - index: 索引
+ (uint8_t)getValueForData:(NSData *)data index:(NSUInteger)index;

/// 十六进制数字转字节
/// - Parameters:
///   - data: 数字
///   - number: 几位
+ (Byte)intTobyte:(NSInteger)data atByteNumber:(NSInteger)number;

+ (int)byteToint:(Byte)byte atByteNumber:(NSInteger)number;

/// 数据转为十六进制
/// - Parameter data: 数据
+ (NSString *)convertDataToHexString:(NSData *)data;
+ (NSData *)convertHexStringToData:(NSString *)str;
/// 数据转为ASCII码
/// - Parameter data: 数据
+ (NSString *)convertDataToASCIIString:(NSData *)data;
/// ASCII码转为数据
/// - Parameter data: 数据
+ (NSData *)convertASCIIStringToData:(NSString *)str;
/// 十六进制转为ASCII码
/// - Parameter hexString: 十六进制数据
+ (NSString *)asciiFromHexString:(NSString *)hexString;


/// 获取高八位
/// - Parameter byte: byte
+ (int)getHighEightInt:(Byte)byte;
/// 获取低八位
/// - Parameter byte: byte
+ (int)getLowerEightInt:(Byte)byte;
// 获取高八位
+ (Byte)getHighEightByte:(int)num;
// 获取低八位
+ (Byte)getLowerEightByte:(int)num;
/// 获取高四位
/// - Parameter byte: byte
+ (int)getHighFourInt:(Byte)byte;
/// 获取低四位
/// - Parameter byte: byte
+ (int)getLowerFourInt:(Byte)byte;

/**
 十进制转换十六进制
  
 @param decimal 十进制数
 @return 十六进制数
 */
+ (NSString *)getHexByDecimal:(NSInteger)decimal;
@end

NS_ASSUME_NONNULL_END
