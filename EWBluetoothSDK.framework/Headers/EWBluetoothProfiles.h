//
//  EWBluetoothProfiles.h
//  EWBluetoothDemo
//
//  Created by keli on 2022/9/21.
//

#ifndef EWBluetoothProfiles_h
#define EWBluetoothProfiles_h

#pragma mark - 蓝牙状态
typedef NS_ENUM(NSUInteger, EWBluetoothState) {
    EWBluetoothStateUnknown = 0,   // 未知
    EWBluetoothStateResetting,     // 重置中
    EWBluetoothStateUnsupported,   // 不支持
    EWBluetoothStateUnauthorized,  // 未授权
    EWBluetoothStatePoweredOff,    // 关闭
    EWBluetoothStatePoweredOn,     // 打开
};

#pragma mark - 蓝牙名称匹配方式
typedef NS_ENUM(NSUInteger, EWBluetoothNameMatchWay) {
    /// 前缀匹配，区分大小写
    EWBluetoothNameMatchPrefix = 0,
    /// 前缀匹配，不区分大小写
    EWBluetoothNameMatchPrefixIgnoreCase,
    /// 后缀匹配，区分大小写
    EWBluetoothNameMatchSuffix,
    /// 后缀匹配，不区分大小写
    EWBluetoothNameMatchSuffixIgnoreCase,
    /// 直接比较，区分大小写
    EWBluetoothNameMatchEquals,
    /// 直接比较，不区分大小写
    EWBluetoothNameMatchEqualsIgnoreCase,
    /// 内容包含，区分大小写
    EWBluetoothNameMatchContain,
    /// 内容包含，不区分大小写
    EWBluetoothNameMatchContainIgnoreCase,
    /// 内容不包含，区分大小写
    EWBluetoothNameMatchNotContain,
    /// 内容不包含，不区分大小写
    EWBluetoothNameMatchNotContainIgnoreCase,
};

typedef NS_ENUM(NSUInteger, EWError) {
    EWErrorBluetoothDisabled = 100,
};
#endif /* EWBluetoothManagerProfiles_h */

