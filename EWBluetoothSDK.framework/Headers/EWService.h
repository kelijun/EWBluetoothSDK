//
//  EWService.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/10/14.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@class EWPeripheral, EWCharacteristic;
@interface EWService : NSObject
/// 服务
@property (nonatomic, strong, readonly) CBService *serivce;
/// 外围设备
@property (nonatomic, weak, readonly) EWPeripheral *peripheral;
/// 服务UUID
@property (nonatomic, strong, readonly) CBUUID *UUID;
/// 服务UUID字符串
@property (nonatomic, strong, readonly) NSString *UUIDString;
/// 服务UUID描述
@property (nonatomic, strong, readonly) NSString *UUIDDescription;
/// 服务的类型（主要或者次要）
@property (nonatomic, assign, readonly) BOOL isPrimary;
/// 服务的特征
@property (nonatomic, readonly, nullable) NSArray<EWCharacteristic *> *characteristics;
@end

NS_ASSUME_NONNULL_END
