//
//  EWBluetoothFilterInfo.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/9/21.
//

#import <Foundation/Foundation.h>
#import "EWBluetoothProfiles.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWBluetoothFilterInfo : NSObject
/// 匹配名称
@property (nonatomic, strong) NSString *matchName;
/// 匹配名称方式
@property (nonatomic, assign) EWBluetoothNameMatchWay matchNameWay;
@end

NS_ASSUME_NONNULL_END
