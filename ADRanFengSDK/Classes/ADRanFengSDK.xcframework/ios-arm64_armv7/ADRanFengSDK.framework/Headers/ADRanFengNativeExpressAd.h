//
//  ADRanFengNativeExpressAd.h
//  ADRanFengSDK
//
//  Created by 陈则富 on 2021/9/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ADRanFengSDK/ADRanFengExpressViewRegisterProtocol.h>
NS_ASSUME_NONNULL_BEGIN
@class ADRanFengNativeExpressAd;
@class ADRanFengNativeExpressView;

@protocol ADRanFengNativeExpressAdDelegate<NSObject>

/**
 信息流广告加载成功
 */
- (void)ranfengExpressAdSucceedToLoad:(ADRanFengNativeExpressAd *)expressAd views:(NSArray<__kindof UIView<ADRanFengExpressViewRegisterProtocol> *> *)views;

/**
 信息流广告加载失败
 */
- (void)ranfengExpressAdFailToLoad:(ADRanFengNativeExpressAd *)expressAd error:(NSError *)error;

/**
 信息流广告渲染成功
 */
- (void)ranfengExpressAdRenderSucceed:(ADRanFengNativeExpressAd *)expressAd adView:(UIView<ADRanFengExpressViewRegisterProtocol> *)expressAdView;

/**
 信息流广告渲染失败
 */
- (void)ranfengExpressAdRenderFail:(ADRanFengNativeExpressView *)expressAd error:(NSError *)error;

/**
 信息流广告关闭
 */
- (void)ranfengExpressAdClosed:(ADRanFengNativeExpressAd *)expressAd adView:(UIView<ADRanFengExpressViewRegisterProtocol> *)expressAdView;

/**
 信息流广告点击
 */
- (void)ranfengExpressAdClick:(ADRanFengNativeExpressAd *)expressAd adView:(UIView<ADRanFengExpressViewRegisterProtocol> *)expressAdView;

/**
 信息流广告展示
 */
- (void)ranfengExpressAdDidPresent:(ADRanFengNativeExpressAd *)expressAd adView:(UIView<ADRanFengExpressViewRegisterProtocol> *)expressAdView;

/**
 信息流广告曝光
 */
- (void)ranfengExpressAdDidExpourse:(ADRanFengNativeExpressAd *)expressAd adView:(UIView<ADRanFengExpressViewRegisterProtocol> *)expressAdView;

/**
 信息流广告关闭落地页
 */
- (void)ranfengExpressAdDidCloseLandingPage:(ADRanFengNativeExpressAd *)expressAd adView:(UIView<ADRanFengExpressViewRegisterProtocol> *)expressAdView;

/**
 *以下为视频信息流相关回调
 */

/**
 信息流视频广告开始播放
 */
- (void)ranfengExpressAdVideoPlay:(ADRanFengNativeExpressAd *)expressAd adView:(UIView<ADRanFengExpressViewRegisterProtocol> *)expressAdView;

/**
 信息流视频广告视频播放失败
 */
- (void)ranfengExpressAdVideoPlayFail:(ADRanFengNativeExpressAd *)expressAd adView:(UIView<ADRanFengExpressViewRegisterProtocol> *)expressAdView error:(NSError *)error;

/**
 信息流视频广告视频暂停
 */
- (void)ranfengExpressAdVideoPause:(ADRanFengNativeExpressAd *)expressAd adView:(UIView<ADRanFengExpressViewRegisterProtocol> *)expressAdView;

/**
 信息流视频广告视频播放完成
 */
- (void)ranfengExpressAdVideoFinish:(ADRanFengNativeExpressAd *)expressAd adView:(UIView<ADRanFengExpressViewRegisterProtocol> *)expressAdView;


@end

@interface ADRanFengNativeExpressAd : NSObject

/**
 *  委托 [必须实现]
 */
@property (nonatomic ,weak) id<ADRanFengNativeExpressAdDelegate>  delegate;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;


/**
 请求超时时间,默认为4s,需要设置3s及以上
*/
@property (nonatomic, assign) NSInteger tolerateTimeout;

/**
 一般为当前展示广告控制器
*/
@property (nonatomic, weak) UIViewController *controller;

/**
 是否设置静音模式，默认是true
*/
@property (nonatomic ,assign) BOOL playMute;

/**
 初始化广告加载器，需传入需要广告尺寸(一般按照16：9比例返回广告视图）
 */
- (instancetype)initWithAdSize:(CGSize)adSize NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

/**
 加载广告

 @param count 拉取几条广告,建议区间 1~4, 超过可能无法拉取到
 */
- (void)loadAdWithCount:(int)count;

/**
 *  竞胜之后调用, 需要在展示广告之前调用（必须调用否则无法展示广告）
 *
 *  @param adView 竞价成功的广告视图，该广告价格请调用[adView getBidPrice]获取，具体见ADRanFengExpressViewRegisterProtocol，单位：分
 *  @param price 如ADRanFeng从竞价队列中胜出，则传入竞价队列第二高价（单位：分）；如仅有ADRanFeng平台竞价广告，则竞赢上报的价格为当前广告对象的底价，如：[adView bidFloor]（单位：分）
 */
- (void)sendWinNotificationWithAdView:(UIView<ADRanFengExpressViewRegisterProtocol> *)adView price:(NSInteger)price;

/**
 *  竞败之后调用,
 *  @param reason 竞价失败原因
 *  @param winnerPirce 竟赢者价格，单位：分
 *  @param adView 竞价失败的广告视图
 */
- (void)sendWinFailNotificationReason:(ADRanFengBiddingLossReason)reason winnerPirce:(NSInteger)winnerPirce AdView:(UIView<ADRanFengExpressViewRegisterProtocol> *)adView;

@end

NS_ASSUME_NONNULL_END

