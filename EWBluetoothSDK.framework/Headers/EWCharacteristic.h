//
//  EWCharacteristic.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/10/14.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface EWCharacteristic : NSObject
/// 特征
@property (nonatomic, strong, readonly) CBCharacteristic *characteristic;
/// 属性
@property (nonatomic, assign, readonly) CBCharacteristicProperties properties;
/// 特征UUID
@property (nonatomic, strong, readonly) CBUUID *UUID;
/// 特征UUID字符串
@property (nonatomic, strong, readonly) NSString *UUIDString;
/// 特征UUID描述
@property (nonatomic, strong, readonly) NSString *UUIDDescription;
/// 数据
@property (nonatomic, strong, readonly) NSData *value;
/// 描述符
@property (nonatomic, strong, readonly) NSArray<CBDescriptor *> *descriptors;
/// 是否通知
@property (nonatomic, assign, readonly) BOOL isNotifying;
@end

NS_ASSUME_NONNULL_END
