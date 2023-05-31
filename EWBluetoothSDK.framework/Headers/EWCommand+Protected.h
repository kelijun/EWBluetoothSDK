//
//  EWCommand+Protected.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/10/28.
//

#import "EWCommand.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWCommand ()
//@property (nonatomic, copy) EWYModemCommandCompletionHandler completionHander;
// 命令数据
@property (nonatomic, strong) NSData *commandData;
// 重试次数
@property (nonatomic, assign) NSInteger retryCount;

// 减少重试次数
- (void)reduceRetryCount;
@end

NS_ASSUME_NONNULL_END
