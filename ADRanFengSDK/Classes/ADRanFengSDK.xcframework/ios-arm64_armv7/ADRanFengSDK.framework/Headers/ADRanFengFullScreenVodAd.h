//
//  ADRanFengFullScreenVodAd.h
//  ADRanFengSDK
//
//  Created by Jiangyou on 2022/2/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ADRanFengSDK/ADRanFengCommonDefine.h>
NS_ASSUME_NONNULL_BEGIN
@class ADRanFengFullScreenVodAd;
@protocol ADRanFengFullScreenVodAdDelegate <NSObject>

/**
 *  全屏视频广告数据请求成功
 */
- (void)ranfengFullScreenVodAdSuccessToLoadAd:(ADRanFengFullScreenVodAd *)fullScreenVodAd;

/**
 *  全屏视频广告数据请求失败
 */
- (void)ranfengFullScreenVodAdFailToLoadAd:(ADRanFengFullScreenVodAd *)fullScreenVodAd error:(NSError *)error;

/**
 *  全屏视频广告视频缓存成功
 */
- (void)ranfengFullScreenVodAdVideoCacheFinish:(ADRanFengFullScreenVodAd *)fullScreenVodAd;

/**
 *  全屏视频广告渲染成功
 *  建议在此回调后展示广告
 */
- (void)ranfengFullScreenVodAdVideoReadyToPlay:(ADRanFengFullScreenVodAd *)fullScreenVodAd;

/**
 *  全屏视频广告播放失败
 *
 */
- (void)ranfengFullScreenVodAdVideoPlayFail:(ADRanFengFullScreenVodAd *)fullScreenVodAd error:(NSError *)error;

/**
 *  全屏视频视图展示成功回调
 *  全屏视频展示成功回调该函数
 */
- (void)ranfengFullScreenVodAdDidPresentScreen:(ADRanFengFullScreenVodAd *)fullScreenVodAd;

/**
 *  全屏视频广告视图展示失败回调
 *  全屏视频广告展示失败回调该函数
 */
- (void)ranfengFullScreenVodAdFailToPresent:(ADRanFengFullScreenVodAd *)fullScreenVodAd error:(NSError *)error;

/**
 *  全屏视频广告曝光回调
 */
- (void)ranfengFullScreenVodAdWillExposure:(ADRanFengFullScreenVodAd *)fullScreenVodAd;

/**
 *  全屏视频广告点击回调
 */
- (void)ranfengFullScreenVodAdClicked:(ADRanFengFullScreenVodAd *)fullScreenVodAd;

/**
 *  全屏视频广告页关闭
 */
- (void)ranfengFullScreenVodAdAdDidDismissClose:(ADRanFengFullScreenVodAd *)fullScreenVodAd;

/**
 *  全屏视频广告达到激励条件
 */
- (void)ranfengFullScreenVodAdAdDidEffective:(ADRanFengFullScreenVodAd *)fullScreenVodAd;

/**
 *  全屏视频广告视频播放结束
 */
- (void)ranfengFullScreenVodAdAdVideoPlayFinish:(ADRanFengFullScreenVodAd *)fullScreenVodAd;

/**
 *  全屏视频广告关闭落地页
 */
- (void)ranfengFullScreenVodAdCloseLandingPage:(ADRanFengFullScreenVodAd *)fullScreenVodAd;



@end


@interface ADRanFengFullScreenVodAd : NSObject

/**
 委托对象
 */
@property (nonatomic ,weak) id<ADRanFengFullScreenVodAdDelegate> delegate;

/**
 详解：当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 请求超时时间,默认为4s,需要设置3s及以上
 */
@property (nonatomic, assign) NSInteger tolerateTimeout;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 是否设置视频静音模式
*/
@property (nonatomic ,assign) BOOL playMute;

/**
 加载广告数据
*/
- (void)loadAdData;

/**
 展示广告
*/
- (void)showFromRootViewController:(UIViewController *)viewController;

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

@end

NS_ASSUME_NONNULL_END
