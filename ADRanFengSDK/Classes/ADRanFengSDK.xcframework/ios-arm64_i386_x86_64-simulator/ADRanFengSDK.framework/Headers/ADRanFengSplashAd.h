//
//  ADRanFengSplashAd.h
//  ADRanFengSDK
//
//  Created by 陈则富 on 2021/9/16.
//

#import <UIKit/UIKit.h>
#import <ADRanFengSDK/ADRanFengSplashSkipViewProtocol.h>
#import <ADRanFengSDK/ADRanFengCommonDefine.h>

NS_ASSUME_NONNULL_BEGIN

@class ADRanFengSplashAd;

@protocol ADRanFengSplashAdDelegate <NSObject>

@optional
/**
 *  开屏广告请求成功
 */
- (void)ranfengSplashAdSuccessLoad:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告请求失败
 */
- (void)ranfengSplashAdFailLoad:(ADRanFengSplashAd *)splashAd withError:(NSError *)error;

/**
 *  开屏广告素材渲染成功
 */
- (void)ranfengSplashAdDidLoad:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告渲染失败
 */
- (void)ranfengSplashAdRenderFaild:(ADRanFengSplashAd *)splashAd withError:(NSError *)error;

/**
 *  开屏广告展示成功
 */
- (void)ranfengSplashAdDidPresent:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告展示失败
 */
- (void)ranfengSplashAdFailToShow:(ADRanFengSplashAd *)splashAd error:(NSError *)error;

/**
 *  开屏广告曝光回调
 */
- (void)ranfengSplashAdExposured:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告点击回调
 */
- (void)ranfengSplashAdClicked:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告倒计时结束回调
 */
- (void)ranfengSplashAdCountdownToZero:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告点击跳过回调
 */
- (void)ranfengSplashAdSkiped:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告关闭回调 & 若打开落地页，请结合使用 ranfengSplashAdCloseLandingPage 回调
 */
- (void)ranfengSplashAdClosed:(ADRanFengSplashAd *)splashAd;

/**
 *  开屏广告关闭落地页回调
 */
- (void)ranfengSplashAdCloseLandingPage:(ADRanFengSplashAd *)splashAd;

@end

@interface ADRanFengSplashAd : NSObject

/**
 * 广告id
 */
@property (nonatomic ,copy) NSString  *posId;

/**
 *  委托对象
 */
@property (nonatomic ,weak) id<ADRanFengSplashAdDelegate>  delegate;

/**
 用于开屏请求过渡，可将启动图转为color传入，默认为透明
 例如：_splashAd.backgroundColor = [UIColor adrf_getColorWithImage:[UIImage imageNamed:@"750x1334.png"] withNewSize:[UIScreen mainScreen].bounds.size];
*/
@property (nonatomic, copy, nullable) UIColor *backgroundColor;

/**
 * 跳过按钮的类型，可以通过此接口替换开屏广告的跳过按钮样式
 */
@property (nonatomic, strong, null_resettable) UIView<ADRanFengSplashSkipViewProtocol> *skipView;

/**
 * 不使用自带跳过视图
 */
@property (nonatomic, readwrite, assign) BOOL hiddenSkipView;

/**
 使用 controller present 落地页，默认获取当前window最上层控制器
 */
@property (nonatomic, weak) UIViewController *viewController;

/// 屏蔽摇一摇、晃一晃
@property (nonatomic, assign) bool disableMotion;


/**
加载并展示开屏
如果全屏广告bottomView设置为nil
@param window 开屏广告展示的window
@param bottomView 底部logo视图, 高度不能超过屏幕的25%
*/
- (void)loadAndShowInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView;


/**
 加载开屏广告（不会自动调用展示方法，需开发者于成功回调后调用showAdInWindow:）
 建议竞价广告询价使用
 */
- (void)loadAd RFDeprecated("接口即将废弃，请使用loadAdWithBottomView:");

/**
加载开屏广告 （不会自动调用展示方法，需开发者于成功回调后调用showAdInWindow:）
建议竞价广告询价使用
如果全屏广告bottomView设置为nil
@param bottomView 底部logo视图, 高度不能超过屏幕的25%
*/
- (void)loadAdWithBottomView:(nullable UIView *)bottomView;

/**
 展示开屏广告（与loadAd或loadAdWithBottomView:一同使用，于成功回调后调用）
 */
- (void)showInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView RFDeprecated("接口即将废弃，请使用showInWindow:");
- (void)showInWindow:(UIWindow *)window;

/// 广告是否超时（广告需要在10分钟内展示）
- (bool)isDataTimeout;

/**
 返回广告的出价，单位：分
 
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
