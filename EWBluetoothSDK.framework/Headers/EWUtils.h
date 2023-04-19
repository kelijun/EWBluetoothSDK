//
//  EWUtils.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/10/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
extern NSString *const EWBluetoothErrorDomain;

typedef NS_ERROR_ENUM(EWBluetoothErrorDomain, EWBluetoothError) {
    EWBluetoothErrorUnknown = 0,                    // 发生未知错误
    EWBluetoothErrorInvalidParameters = 22001,      // 指定参数无效
    EWBluetoothInvalidHandle = 22002,               // 指定属性无效
    EWBluetoothErrorNotConnected = 22003,           // 设备目前未连接
    EWBluetoothErrorOutOfSpace = 22004,             // 设备已耗尽空间来完成预期的操作
    EWBluetoothErrorConnectionLimitReached = 22005, // 超过最大连接个数
    EWBluetoothErrorDisconnected = 22006,           // 外围设备断开连接
    EWBluetoothErrorConnectionFailed = 22006,       // 外围设备连接失败
    EWBluetoothErrorWriteCharacteristic = 22007,    // 写入特征错误
    EWBluetoothErrorReadCharacteristic = 22008,     // 读取特征错误
    EWBluetoothErrorNotifyCharacteristic = 22009,   // 通知特征错误
    
    EWCommandErrorUnknown = 32000,                // 发生未知错误
    EWCommandErrorFileDoesNotExist = 32001,      // 文件不存在
    EWCommandErrorFileFormatError = 32002,       // 文件格式错误
    EWCommandErrorFileVerificationFailed = 32002,// 文件校验失败
    EWCommandErrorWriteTimeout = 32004,          // 写入数据超时
    EWCommandErrorReadTimeout = 32005,           // 读取数据超时
    EWCommandErrorWriteLimitReached = 32006,     // 超过最大写入次数
    EWCommandErrorFailedGetBaseAddress = 32007,  // 获取Flash基地址失败
    EWCommandErrorFailedEraseSector = 32008,     // 擦除Flash地址
    EWCommandErrorWriteDataError = 32009,        // 写入数据错误
};


@interface EWUtils : NSObject
#pragma mrk - 文件操作
/// 下载文件
/// - Parameter downloadURL: 下载地址
+ (void)downloadFileForDownloadURL:(NSString *)downloadURL;

/// 下载文件到指定位置
/// - Parameters:
///   - downloadURL: 下载地址
///   - toFilePath: 目标位置
+ (void)downloadFileForDownloadURL:(NSString *)downloadURL toFilePath:(NSString *)toFilePath;

/// 在路径处是可执行文件
/// - Parameter path: 文件路径
+ (BOOL)isExecutableFileAtPath:(NSString *)path;

/// 验证路径处的格式文件
/// - Parameters:
///   - path: 文件路径
///   - format: 格式，例如bin dat
+ (BOOL)verifyFormatFileAtPath:(NSString *)path format:(NSString *)format;

/// 创建错误对象
/// - Parameters:
///   - errMsg: 错误内容
///   - suggestion: 错误建议
///   - code: 错误代码
+ (NSError *)bluetoothError:(NSString *)errMsg
         recoverySuggestion:(NSString *)suggestion
                  errorCode:(EWBluetoothError)code;
@end

NS_ASSUME_NONNULL_END
