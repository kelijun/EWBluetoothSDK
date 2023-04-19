//
//  EWCentralManager.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/9/21.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "EWPeripheral.h"
#import "EWService.h"
#import "EWCharacteristic.h"
#import "EWBluetoothHandler.h"
#import "EWBluetoothFilterInfo.h"
#import "EWCentralManagerDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWCentralManager : NSObject
/// 蓝牙回调
@property (nonatomic, strong, readonly) EWBluetoothHandler *handler;
/// 蓝牙状态
@property (nonatomic, assign, readonly) EWBluetoothState bluetoothState;
/// 是否正在扫描
@property (nonatomic, assign, readonly) BOOL isScanning;

/// 已发现的外围设备
@property (nonatomic, strong, readonly) NSMutableArray *discoverPeripherals;
/// 已连接的外围设备
@property (nonatomic, strong, readonly) NSMutableArray *connectedPeripherals;

/// 单例
+ (instancetype)share;

#pragma mark - 蓝牙相关配置
/// 配置管理器线程。
/// 默认为主线程，当你指定线程后，将在该线程上调度队列。
- (EWCentralManager *(^)(dispatch_queue_t))configureManagerQueue;

/// 配置管理器选项的可选字典。
/// 默认为空。
/// CBCentralManagerOptionShowPowerAlertKey 默认为NO，系统当蓝牙关闭时是否弹出一个警告框。
/// CBCentralManagerOptionRestoreIdentifierKey 系统被杀死，重新恢复centermanager的ID。
- (EWCentralManager *(^)(NSDictionary<NSString *, id> * _Nullable))configureManagerOptions;

/// 配置管理器代理。
- (EWCentralManager *(^)(id <EWCentralManagerDelegate>))configureManagerDelegate;

/// 配置管理器搜索时间。
/// 默认为0不限制搜索时间，当设置为30时，管理器将在30秒后停止搜索。
//- (EWCentralManager *(^)(NSInteger))configureManagerScanTime;

/// 配置外围设备连接时间。
/// 默认为0不限制连接时间，不建议设置为1-10秒，这可能会导致你的蓝牙来不及连接就被取消。
//- (EWCentralManager *(^)(NSInteger))configureManagerConnectionTime;

/// 配置管理器最大连接个数。
/// 默认不限制，当超过你设置的最大限制后，会断开之前已经连接的外围设备。
- (EWCentralManager *(^)(NSInteger))configureManagerMaximumNumberOfConnection;

/// 配置管理器过滤器。
/// 默认不过滤。
- (EWCentralManager *(^)(NSArray<EWBluetoothFilterInfo *> * _Nullable))configureManagerFilterInfos;

/// 配置管理器搜索服务的数组。
/// 默认为空，如果需要搜索指定服务的外围设备，可以在数组里面添加服务字符串。当你使用-scanForPeripheralsWithServices:options:方法时该方法会失效。
- (EWCentralManager *(^)(NSArray<NSString *> * _Nullable))configureManagerScanServices;
   
/// 配置管理器搜索选项的可选字典。
/// 默认为空。当你使用-scanForPeripheralsWithServices:options:方法时该方法会失效。
- (EWCentralManager *(^)(NSDictionary<NSString *, id> * _Nullable))configureManagerScanOptions;

/// 过滤设备
/// - Parameter discoverFilter: 过滤信息
- (void)setFilterForDiscoverPeripherals:(BOOL (^)(NSString *peripheralName, NSDictionary *advertisementData, NSNumber *RSSI))discoverFilter;

/// 清空管理器配置。
/// 恢复所有默认值。
- (EWCentralManager *)clearConfigure;

#pragma mark - 蓝牙功能
/// 检查蓝牙状态
- (EWBluetoothState)checkBluetoothState;

/// 扫描外围设备
- (void)scanForPeripherals;

/// 扫描外围设备通过服务和选项
///  - Parameters:
///   - serviceUUIDs: serviceUUIDs 服务
///   - options: options 选项
/// - seealso   CBCentralManagerScanOptionAllowDuplicatesKey 默认为NO，过滤功能是否启用，每次寻找都会合并相同的peripheral。如果设备YES的话每次都能接受到来自peripherals的广播包数据。
/// - seealso   CBCentralManagerScanOptionSolicitedServiceUUIDsKey 想要扫描的服务的UUID，以一个数组的形式存在。扫描的时候只会扫描到包含这些UUID的设备。
- (void)scanForPeripheralsWithServices:(NSArray<NSString *> * _Nullable)serviceUUIDs options:(NSDictionary<NSString *, id> * _Nullable)options;

/// 停止扫描外围设备
- (void)stopScan;

/// 连接外围设备通过外围设备
/// @param peripheral 外围设备
- (void)connectToPeripheral:(EWPeripheral *)peripheral;

/// 连接外围设备通过Mac地址
/// @param macAdress Mac地址
//- (void)connectToPeripheralMacAdress:(NSString *)macAdress;

/// 通过设备UUIDString连接外围设备
/// @param UUIDString UUIDString
- (void)connectToPeripheralForUUIDString:(NSString *)UUIDString;

/// 通过设备UUIDString自动连接外围设备
/// @param UUIDString UUIDString
- (void)autoConnectToPeripheralForUUIDString:(NSString *)UUIDString;

/// 连接外围设备通过设备名称
/// @param name 外围设备名称
//- (void)connectToPeripheralName:(NSString *)name;

/// 取消外围设备的连接
/// @param peripheral 外围设备
- (void)cancelPeripheralConnection:(EWPeripheral *)peripheral;

/// 取消外围设备的连接
/// @param UUIDString UUIDString
- (void)cancelPeripheralForUUIDString:(NSString *)UUIDString;

/// 取消所有的外围设备的连接
- (void)cancelAllPeripheralConnection;
@end

NS_ASSUME_NONNULL_END
