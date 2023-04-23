//
//  EWCentralManagerDelegate.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/9/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class EWCentralManager, EWPeripheral, EWCharacteristic;

@protocol EWCentralManagerDelegate <NSObject>
@required
/// 管理器状态发生变化
/// - Parameter central: 管理器
- (void)ewCentralManagerDidUpdateState:(EWCentralManager *)central;

@optional


/// 发现外围设备会调用该方法
/// - Parameters:
///   - central: 管理器
///   - peripheral: 外围设备
- (void)ewCentralManager:(EWCentralManager *)central didDiscoverPeripheral:(EWPeripheral *)peripheral;

/// 外围设备消失会调用该方法
/// - Parameters:
///   - central: 管理器
///   - peripheral: 外围设备
- (void)ewCentralManager:(EWCentralManager *)central peripheralDisappear:(EWPeripheral *)peripheral;

/// 外围设备更新时调用该方法
/// - Parameters:
///   - central: 管理器
///   - peripheral: 外围设备
- (void)ewCentralManager:(EWCentralManager *)central
   peripheralDidUpdate:(EWPeripheral *)peripheral;

/// 外围设备连接成功时调用该方法
/// - Parameters:
///   - central: 管理器
///   - periphera: 外围设备
- (void)ewCentralManager:(EWCentralManager *)central
     didConnectPeripheral:(EWPeripheral *)peripheral;


/// 外围设备连接失败时调用该方法
/// - Parameters:
///   - central: 管理器
///   - peripheral: 外围设备
///   - error: 错误信息
- (void)ewCentralManager:(EWCentralManager *)central
didFailToConnectPeripheral:(nullable EWPeripheral *)peripheral
                 error:(NSError *)error;

/// 外围设备断开连接时调用该方法
/// - Parameters:
///   - central: 管理器
///   - peripheral: 外围设备
///   - error: 错误信息
- (void)ewCentralManager:(EWCentralManager *)central
  didDisconnectPeripheral:(EWPeripheral *)peripheral
                    error:(NSError *)error;
@end

NS_ASSUME_NONNULL_END
