//
//  EWCentralManager+Filter.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/9/26.
//

#import "EWCentralManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWCentralManager (Filter)

/// 通过外围设备名称过滤
/// - Parameters:
///   - peripheralName: 外围设备名称
///   - filterInfos: 过滤器模型
- (BOOL)filterPeripheralByPeripheralName:(NSString *)peripheralName
                             filterInfos:(nullable NSArray<EWBluetoothFilterInfo *> *)filterInfos;
@end

NS_ASSUME_NONNULL_END
