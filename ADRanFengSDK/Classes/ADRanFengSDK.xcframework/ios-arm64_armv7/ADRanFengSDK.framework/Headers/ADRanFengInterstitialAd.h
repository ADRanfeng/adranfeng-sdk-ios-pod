//
//  ADRanFengInterstitialAd.h
//  ADRanFengSDK
//
//  Created by 陈则富 on 2021/9/14.
//

#import <UIKit/UIKit.h>
#import <ADRanFengSDK/ADRanFengCommonDefine.h>
#import "ADRanFengCommonDefine.h"
NS_ASSUME_NONNULL_BEGIN

@class ADRanFengInterstitialAd;

@protocol ADRanFengInterstitialAdDelegate <NSObject>

@optional

/**
 *  插屏广告数据请求成功
 */
- (void)ranfengInterstitialSuccessToLoadAd:(ADRanFengInterstitialAd *)unifiedInterstitial;

/**
 *  插屏广告数据请求失败
 */
- (void)ranfengInterstitialFailToLoadAd:(ADRanFengInterstitialAd *)unifiedInterstitial error:(NSError *)error;

/**
 *  插屏广告渲染成功
 *  建议在此回调后展示广告
 */
- (void)ranfengInterstitialRenderSuccess:(ADRanFengInterstitialAd *)unifiedInterstitial;

/**
 *  插屏广告视图展示成功回调
 *  插屏广告展示成功回调该函数
 */
- (void)ranfengInterstitialDidPresentScreen:(ADRanFengInterstitialAd *)unifiedInterstitial;

/**
 *  插屏广告视图展示失败回调
 *  插屏广告展示失败回调该函数
 */
- (void)ranfengInterstitialFailToPresent:(ADRanFengInterstitialAd *)unifiedInterstitial error:(NSError *)error;

/**
 *  插屏广告曝光回调
 */
- (void)ranfengInterstitialWillExposure:(ADRanFengInterstitialAd *)unifiedInterstitial;

/**
 *  插屏广告点击回调
 */
- (void)ranfengInterstitialClicked:(ADRanFengInterstitialAd *)unifiedInterstitial;

/**
 *  插屏广告页关闭
 */
- (void)ranfengInterstitialAdDidDismissClose:(ADRanFengInterstitialAd *)unifiedInterstitial;

/**
 *  插屏广告落地页关闭
 */
- (void)ranfengInterstitialAdDidCloseLandingPage:(ADRanFengInterstitialAd *)unifiedInterstitial;


/**
 *以下为视频插屏相关回调
 */

/**
 插屏视频广告开始播放
 */
- (void)ranfengInterstitialAdVideoPlay:(ADRanFengInterstitialAd *)unifiedInterstitial;

/**
 插屏视频广告视频播放失败
 */
- (void)ranfengInterstitialAdVideoPlayFail:(ADRanFengInterstitialAd *)unifiedInterstitial error:(NSError *)error;

/**
 插屏视频广告视频暂停
 */
- (void)ranfengInterstitialAdVideoPause:(ADRanFengInterstitialAd *)unifiedInterstitial;

/**
 插屏视频广告视频播放完成
 */
- (void)ranfengInterstitialAdVideoFinish:(ADRanFengInterstitialAd *)unifiedInterstitial;


@end

@interface ADRanFengInterstitialAd : NSObject

/**
 委托对象
 */
@property (nonatomic ,weak) id<ADRanFengInterstitialAdDelegate>  delegate;

/**
 详解：当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 请求超时时间,默认为4s,需要设置3s及以上
 */
@property (nonatomic, assign) NSInteger tolerateTimeout;

/**
 是否开启自动关闭功能， 默认不开启
 */
@property (nonatomic, assign) BOOL isAutoClose;

/**
 [3~100) 区间内有效；默认5秒后关闭;需和isAutoClose配合使用
 */
@property (nonatomic, assign) NSInteger autoCloseTime;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 是否设置视频静音模式（默认：false）
*/
@property (nonatomic ,assign) BOOL playMute;

/// 屏蔽摇一摇、晃一晃
@property (nonatomic, assign) bool disableMotion;

/**
 支持屏幕类型，默认竖屏
*/
@property (nonatomic, assign) ADRanFengAdSupportScreenType supportScreenType;
/**
 加载广告数据
*/
- (void)loadAdData;

/**
 广告是否超时（广告需要在10分钟内展示）
 */
- (bool)isDataTimeout;

/**
 展示广告
*/
- (void)showFromRootViewController:(UIViewController *)viewController;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，小于等于0表示广告请求失败或获取eCPM时机不正确(请于请求广告成功后获取)
*/
- (NSInteger)bidPrice;

/**
 返回广告的底价，单位：分
 
 @return 成功返回一个大于等于0的值，小于等于0表示广告请求失败或获取底价时机不正确(请于请求广告成功后获取)
*/
- (NSInteger)bidFloor;

/**
 *  竞胜之后调用, 需要在展示广告之前调用
 *  @param price 如ADRanFeng从竞价队列中胜出，则传入竞价队列第二高价（单位：分）；如仅有ADRanFeng平台竞价广告，则竞赢上报的价格为当前广告对象的底价，如：[adView bidFloor]（单位：分）
 */
- (void)sendWinNotificationWithPrice:(NSInteger)price;

/**
 *  竞败之后调用,
 *  @param reason 竞价失败原因
 *  @param winnerPirce 竟赢者价格，单位：分
 */
- (void)sendWinFailNotificationReason:(ADRanFengBiddingLossReason)reason winnerPirce:(NSInteger)winnerPirce;


@end

NS_ASSUME_NONNULL_END
