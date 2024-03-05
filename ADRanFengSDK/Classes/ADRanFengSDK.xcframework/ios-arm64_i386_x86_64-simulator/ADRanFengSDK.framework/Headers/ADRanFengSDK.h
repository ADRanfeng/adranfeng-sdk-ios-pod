//
//  ADRanFengSDK.h
//  ADRanFengSDK
//
//  2.1.0.1
//  Created by Jiangyou on 2021/9/11.
//  Updated by Wosun on 2023/11/14 16:24.
//

#import <Foundation/Foundation.h>
#import <ADRanFengSDK/ADRanFengSplashAd.h>
#import <ADRanFengSDK/ADRanFengBannerAdView.h>
#import <ADRanFengSDK/ADRanFengInterstitialAd.h>
#import <ADRanFengSDK/ADRanFengNativeExpressAd.h>
#import <ADRanFengSDK/ADRanFengExpressViewRegisterProtocol.h>

typedef enum ADRanFengKitLogLevel:NSUInteger ADRanFengKitLogLevel;


NS_ASSUME_NONNULL_BEGIN
@interface ADRanFengSDK : NSObject

/**
 是否开启个性化广告；默认YES,建议初始化SDK之前设置
 */
@property (nonatomic, assign, class) BOOL enablePersonalAd;

/**
 是否允许SDK采集设备信息（网络信息等） ，默认YES，如需关闭需在初始化之前设置(开启并不会影响审核)
 */
@property (nonatomic, assign, class) BOOL enablePersonalInformation;

/**
 是否是接入到flutter项目中，默认NO
 */
@property (nonatomic, assign, class) BOOL isFlutter;

/**
初始化SDK
@param appId 给定的唯一appid
@param completion 启动完成回调
*/
+ (void)initWithAppId:(NSString *)appId completionBlock:(nullable void(^)(NSError *_Nullable error))completion;

/**
 获取SDK版本号
 */
+ (NSString *)getSDKVersion;
/**
 设置日志输出等级
 
 @param logLevel 日志输出等级
 */
+ (void)setLogLevel:(ADRanFengKitLogLevel)logLevel;

@end

NS_ASSUME_NONNULL_END
