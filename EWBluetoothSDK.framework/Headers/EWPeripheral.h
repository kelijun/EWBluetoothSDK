//
//  EWPeripheral.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/9/26.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "EWPeripheralDelegate.h"
#import "EWPeripheralUpgradeDelegate.h"
#import "EWCharacteristic.h"
#import "EWService.h"
#import "EWBluetoothHandler.h"
#import "EWCommand.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, EWPeripheralState) {
    EWPeripheralStateDisconnected = 0,      // 已断开
    EWPeripheralStateConnecting,            // 连接中
    EWPeripheralStateConnected,             // 蓝牙已连接
    EWPeripheralStateDisconnecting,         // 断开连接中
};

@interface EWPeripheral : NSObject

/// 外围设备名称
@property (nonatomic, strong, readonly) NSString *name;

/// 外围设备RSSI
@property (nonatomic, strong, readonly) NSNumber *RSSI;

/// 外围设备当前的广播数据
@property (nonatomic, strong, readonly) NSDictionary *advertisementData;

/// 扫描到的外围设备当前服务数组
@property (nonatomic, strong, readonly) NSArray<EWService *> *services;

/// 外围设备UUID
@property (nonatomic, strong, readonly) NSString *UUIDString;

/// 外围设备
@property (nonatomic, strong, readonly) CBPeripheral *peripheral;

/// 外围设备当前状态
@property (nonatomic, assign, readonly) EWPeripheralState state;

/// 如果值为YES，远程设备有空间发送一个没有响应的写服务
/// 如果值为 NO,如果值被设置为YES时，当前写服务被冲刷，方法peripheralIsReadyToSendWriteWithoutResponse:将会被调用
@property (nonatomic, assign, readonly) BOOL canSendWriteWithoutResponse;

/// 读取RSSI
/// peripheral:didReadRSSI:error: 方法会被调用
- (void)readRSSI;

/// 配置代理
/// - Parameter delegate: 代理
- (void)configurePeripheralDelegate:(id<EWPeripheralDelegate>)delegate;

/// 配置升级代理
/// - Parameter delegate: 代理
- (void)configurePeripheralUpgradeDelegate:(id<EWPeripheralUpgradeDelegate>)upgradeDelegate;

/// 查找外围设备上的可用服务
/// - Parameter serviceUUIDStrings: 服务UUID字符串数组
- (void)discoverServices:(nullable NSArray<NSString *> *)serviceUUIDStrings;


/// 查找外围设备上的可用服务
/// - Parameters:
///   - serviceUUIDStrings: 服务UUID字符串数组
///   - handler: 查找到处理程序
- (void)discoverServices:(nullable NSArray<NSString *> *)serviceUUIDStrings
                 handler:(nullable EWDiscoverServicesHandler)handler;

/// 查找服务的指定包含服务
/// - Parameters:
///   - includedServiceUUIDs: 服务UUID字符串数组
///   - service: 服务
///   - handler: 查找到处理程序
- (void)discoverIncludedServices:(nullable NSArray<NSString *> *)includedServiceUUIDStrings
                      forService:(EWService *)service
                         handler:(nullable EWDiscoverServicesHandler)handler;

/// 从服务查找指定特征
/// - Parameters:
///   - characteristicUUIDs: 特征UUID字符串
///   - service: 服务
- (void)discoverCharacteristics:(nullable NSArray<NSString *> *)characteristicUUIDStrings
                     forService:(EWService *)service;

/// 从服务查找指定特征
/// - Parameters:
///   - characteristicUUIDs: 特征UUID字符串
///   - service: 服务
///   - handler: 查找到处理程序
- (void)discoverCharacteristics:(nullable NSArray<NSString *> *)characteristicUUIDStrings
                     forService:(EWService *)service
                        handler:(nullable EWDiscoverCharacteristicsHandler)handler;

/// 添加通知，会触发代理方法ewPeripheral:didUpdateNotificationStateForCharacteristic:error:
/// - Parameters:
///   - characteristic: 特征
///   - handler: 处理程序
- (void)addNotifyForCharacteristic:(EWCharacteristic *)ewCharacteristic
                           handler:(nullable EWNotifyForCharacteristicsHandler)handler;

/// 移除通知
/// - Parameter characteristic: 特征
- (void)removeNotifyForCharacteristic:(EWCharacteristic *)ewCharacteristic;

/// 读取数据，会触发代理方法ewPeripheral:didUpdateValueForCharacteristic:error:
/// - Parameters:
///   - characteristic: 特征
///   - handler: 处理程序
- (void)readValueForCharacteristic:(EWCharacteristic *)ewCharacteristic
                           handler:(nullable EWUpdateValueForCharacteristicsHandler)handler;

/// 写入数据
/// - Parameters:
///   - data: 数据
///   - characteristic: 特征
///   - handler: 处理程序
- (void)writeValue:(NSData *)data forCharacteristic:(EWCharacteristic *)ewCharacteristic
           handler:(nullable EWWriteValueForCharacteristicsHandler)handler;

/// 写入命令
/// - Parameters:
///   - command: 命令
///   - ewCharacteristic: 写入特征
///   - readCharacteristic: 读取特征
///   - handler: 处理程序
- (void)writeCommand:(EWCommand *)command forCharacteristic:(EWCharacteristic *)writeCharacteristic readCommadForCharacteristic:(nullable EWCharacteristic *)readCharacteristic
             handler:(nullable EWWriteValueForCharacteristicsHandler)handler;
@end

NS_ASSUME_NONNULL_END
