//
//  EWPeripheralHeartRateDelegate.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/11/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, EWHRSBodySensorLocation) {
    EWHRSBodySensorLocationOther = 0x00,     // 未知
    EWHRSBodySensorLocationChest = 0x01,     // 胸部
    EWHRSBodySensorLocationWrist = 0x02,     // 手腕
    EWHRSBodySensorLocationFinger = 0x03,    // 手指
    EWHRSBodySensorLocationHand = 0x04,      // 手
    EWHRSBodySensorLocationEarLobe = 0x05,   // 耳垂
    EWHRSBodySensorLocationFoot = 0x06,      // 脚
};

@protocol EWPeripheralHeartRateDelegate <NSObject>

- (void)ew_peripheral:(EWPeripheral *)peripheral didGetBodySensorLocation:(EWHRSBodySensorLocation)bodySensorLocation;
@end

NS_ASSUME_NONNULL_END
