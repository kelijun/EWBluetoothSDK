//
//  EWPeripheralDelegate.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/10/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class EWPeripheral, EWService, EWCharacteristic;
@protocol EWPeripheralDelegate <NSObject>

/// 外围设备发现服务
/// - Parameters:
///   - peripheral: 外围设备
///   - service: 服务
- (void)ewPeripheral:(EWPeripheral *)peripheral didDiscoverService:(EWService *)service;

/// 外围设备发现特征
/// - Parameters:
///   - peripheral: 外围设备
///   - characteristics: 特征
///   - service: 服务
- (void)ewPeripheral:(EWPeripheral *)peripheral didDiscoverCharacteristics:(EWCharacteristic *)characteristic forService:(EWService *)service;

/// 特征更新通知
/// - Parameters:
///   - peripheral: 外围设备
///   - characteristic: 特征
///   - error: 错误
- (void)ewPeripheral:(EWPeripheral *)peripheral didUpdateNotificationStateForCharacteristic:(EWCharacteristic *)characteristic error:(NSError *)error;

/// 特征更新值
/// - Parameters:
///   - peripheral: 外围设备
///   - characteristic: 特征
///   - error: 错误
- (void)ewPeripheral:(EWPeripheral *)peripheral didUpdateValueForCharacteristic:(EWCharacteristic *)characteristic error:(NSError*)error;
@end

NS_ASSUME_NONNULL_END

