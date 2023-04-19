//
//  EWCommand.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/10/21.
//

#import <Foundation/Foundation.h>
#import "EWDataUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWCommand : NSObject
typedef void (^EWCommandCompletionHandler)(EWCommand *command);

/// 通过数据初始化
/// - Parameter data: 数据
- (instancetype)initWithCommandData:(NSData *)data;

/// 初始化
/// - Parameters:
///   - writeData: 需要写入的数据
///   - length: 返回数据的长度
///   - range: 返回数据需要校验的位置
///   - expectedData: 返回数据需要校验的位置对应的数据
///   - writeTime: 写入时间
///   - retryCount: 重试次数
- (instancetype)initWithWriteCommandData:(NSData *)writeData
                  expectedResponseLength:(NSInteger)length
                   expectedResponseRange:(NSRange)range
                    expectedResponseData:(NSData *)expectedData
                               writeTime:(CGFloat)writeTime
                              retryCount:(NSInteger)retryCount;

/// 获取发送命令
- (NSData *)getWriteCommand;

/// 获取返回数据的长度
- (NSInteger)getExpectedResponseLength;

/// 获取重发时间
- (CGFloat)getResponseRetryTime ;

/// 获取返回数据的重试次数
- (NSInteger)getExpectedResponseRetryCount;

/// 获取写入数据时间
- (CGFloat)getWriteTime;

/// 获取预先写入长度
- (NSInteger)getPreWirteCommandLength;

/// 获取单次发送命令长度，超过长度为被分次发送
- (NSInteger)getSingleWriteLength;

/// 校验返回数据
/// - Parameter uncheckedResponse: 需要校验的数据
- (BOOL)isExpectedResponse:(NSData *)uncheckedResponse;

/// 发送数据
/// - Parameter handler: 处理程序
- (void)sendCommandCompletionHandler:(EWCommandCompletionHandler)handler;

@end

NS_ASSUME_NONNULL_END
