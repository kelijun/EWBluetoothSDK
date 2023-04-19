//
//  EWPeripheralUpgradeDelegate.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/11/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, EWYModemUpgradeStatus) {
    EWYModemUpgradeStatusUnknown = 0,       // 未知
    EWYModemUpgradeStatusCustom,             // 自定义的
    EWYModemUpgradeStatusStart,             // 开始传输
    EWYModemUpgradeStatusDataTransmission,  // 数据传输
    EWYModemUpgradeStatusEot,               // 数据传输完毕
    EWYModemUpgradeStatusEend,              // 结束传输
    EWYModemUpgradeStatusCancel,            // 取消传输
};

@protocol EWPeripheralUpgradeDelegate <NSObject>

/// 升级进度发生变化
/// - Parameters:
///   - ewPeripheral:外围设备
///   - part: 剩余大小（B）
///   - totalParts: 发送大小（B）
///   - progress: 总进度（0～1）
///   - currentSpeed: 当前速度（B/s）
///   - avgSpeed: 平均速度（B/s）
- (void)ewPeripheral:(EWPeripheral *)ewPeripheral progressDidChangeFor:(NSInteger)part outOf:(NSInteger)totalParts to:(double)progress currentSpeedBytesPerSecond:(double)currentSpeed avgSpeedBytesPerSecond:(double)avgSpeed;

/// 升级时间发生变化
/// - Parameters:
///   - ewPeripheral:外围设备
///   - time: 消耗时间（s）
///   - totalTime: 总时间（a）
- (void)ewPeripheral:(EWPeripheral *)ewPeripheral progressTimeDidChangeFor:(NSInteger)time outOf:(NSInteger)totalTime;

/// 升级错误
/// - Parameters:
///   - ewPeripheral:外围设备
///   - error: 错误
- (void)ewPeripheral:(EWPeripheral *)ewPeripheral progressError:(NSError *)error;
@end

NS_ASSUME_NONNULL_END
