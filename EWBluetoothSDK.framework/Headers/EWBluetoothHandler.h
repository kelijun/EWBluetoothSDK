//
//  EWBluetoothHandler.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/10/12.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class EWCentralManager, EWPeripheral, EWService, EWCharacteristic, EWCommand;
typedef void (^EWCentralManagerDidUpdateStateHandler)(EWCentralManager *central);
typedef void (^EWDiscovePeripheralsHandler)(EWCentralManager *central, EWPeripheral *ewPeripheral);
typedef void (^EWPeripheralDisappearHandler)(EWCentralManager *central, EWPeripheral *ewPeripheral);
typedef void (^EWConnectPeripheralHandler)(EWCentralManager *central, EWPeripheral *ewPeripheral);
typedef void (^EWFailToConnectPeripheralHandler)(EWCentralManager *central, EWPeripheral *ewPeripheral, NSError *error);
typedef void (^EWDisconnectPeripheralHandler)(EWCentralManager *central, EWPeripheral *ewPeripheral, NSError *error);
typedef void (^EWDiscoverServicesHandler)(EWPeripheral *ewPeripheral, EWService *ewService);
typedef void (^EWDiscoverCharacteristicsHandler)(EWPeripheral *ewPeripheral, EWService *ewService, EWCharacteristic *ewCharacteristic);
typedef void (^EWNotifyForCharacteristicsHandler)(EWPeripheral *ewPeripheral, EWCharacteristic *ewCharacteristic, NSError *error);
typedef void (^EWUpdateValueForCharacteristicsHandler)(EWPeripheral *ewPeripheral, EWCharacteristic *ewCharacteristic, EWCommand *command, NSError *error);
typedef void (^EWUpdateValueForCharacteristicsHandler)(EWPeripheral *ewPeripheral, EWCharacteristic *ewCharacteristic, EWCommand *command, NSError *error);
typedef void (^EWWriteValueForCharacteristicsHandler)(NSError *error);

@interface EWBluetoothHandler : NSObject
// 管理器状态发生变化
@property (nonatomic, copy) EWCentralManagerDidUpdateStateHandler centralManagerDidUpdateStateHandler;
// 过滤设备
@property (nonatomic, copy) BOOL (^filterOnDiscoverPeripherals)(NSString *peripheralName, NSDictionary *advertisementData, NSNumber *RSSI);
// 发现外围设备
@property (nonatomic, copy) EWDiscovePeripheralsHandler discovePeripheralsHandler;
// 外围设备消失
@property (nonatomic, copy) EWPeripheralDisappearHandler peripheralDisappearHandler;
// 外围设备更新
@property (nonatomic, copy) EWDiscovePeripheralsHandler peripheralUpdateHandler;
// 连接外围设备成功
@property (nonatomic, copy) EWConnectPeripheralHandler conncectPeripheralHandler;
// 连接外围设备失败
@property (nonatomic, copy) EWFailToConnectPeripheralHandler failToConnectPeripheralHandler;
// 断开连接
@property (nonatomic, copy) EWDisconnectPeripheralHandler disconnectPeripheralHandler;
// 发现服务
@property (nonatomic, copy) EWDiscoverServicesHandler discoveServicesHandler;
// 发现特征
@property (nonatomic, copy) EWDiscoverCharacteristicsHandler discoveCharacteristicsHandler;
@end

