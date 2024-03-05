//
//  ADRanFengDataModel.h
//  ADRanFengSDK
//
//  Created by Jiangyou on 2021/9/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRanFengAppPromotionModel : NSObject

@property (nonatomic, copy) NSString *appName;

@property (nonatomic, copy) NSString *appVersion;

@property (nonatomic, copy) NSString *appBundle;

@property (nonatomic, copy) NSString *appIconUrl;

@property (nonatomic, copy) NSString *advertiserName;

@property (nonatomic, copy) NSString *privacyPolicyUrl;

@property (nonatomic, copy) NSString *privacyPolicyInfo;


@end

@interface ADRanFengVideoModel : NSObject

@property (nonatomic, copy) NSString *url;

@property (nonatomic, assign) NSInteger duration;

@property (nonatomic, assign) NSInteger forceDuration;

@end

@interface ADRanFengTrackModel : NSObject

@property (nonatomic, strong) NSArray<NSString *> *display;
@property (nonatomic, strong) NSArray<NSString *> *click;
@property (nonatomic, strong) NSArray<NSString *> *deeplink;
@property (nonatomic, strong) NSArray<NSString *> *tryDeeplink;
@property (nonatomic, strong) NSArray<NSString *> *wechatOpen;
@property (nonatomic, strong) NSArray<NSString *> *downloadEnd;
@property (nonatomic, strong) NSArray<NSString *> *downloadStart;
@property (nonatomic, strong) NSArray<NSString *> *installStart;
@property (nonatomic, strong) NSArray<NSString *> *installEnd;
@property (nonatomic, strong) NSArray<NSString *> *open;
@property (nonatomic, strong) NSArray<NSString *> *close;


@property (nonatomic, strong) NSArray<NSString *> *videoLoaded;
@property (nonatomic, strong) NSArray<NSString *> *videoStart;
@property (nonatomic, strong) NSArray<NSString *> *videoError;
@property (nonatomic, strong) NSArray<NSString *> *videoQuarter;
@property (nonatomic, strong) NSArray<NSString *> *videoMiddle;
@property (nonatomic, strong) NSArray<NSString *> *videoThirdQuarter;
@property (nonatomic, strong) NSArray<NSString *> *videoEnd;
@property (nonatomic, strong) NSArray<NSString *> *videoPause;
@property (nonatomic, strong) NSArray<NSString *> *videoResume;
@property (nonatomic, strong) NSArray<NSString *> *videoSkip;
@property (nonatomic, strong) NSArray<NSString *> *videoMute;
@property (nonatomic, strong) NSArray<NSString *> *videoUnmute;
@property (nonatomic, strong) NSArray<NSString *> *videoReplay;
@property (nonatomic, strong) NSArray<NSString *> *videoClose;
@property (nonatomic, strong) NSArray<NSString *> *videoFullScreen;
@property (nonatomic, strong) NSArray<NSString *> *videoExitFullScreen;
@property (nonatomic, strong) NSArray<NSString *> *rewardSuccess;

- (instancetype)initTrackerModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end

@interface ADRanFengDataModel : NSObject
// 广告标题文案
@property (nonatomic, copy) NSString *title;
// 广告描述文案
@property (nonatomic, copy) NSString *desc;
// 图片链接
@property (nonatomic, copy) NSString *imageUrl;
// 多图链接
@property (nonatomic, strong) NSArray<NSString *> *imageUrlList;
// deeplink地址(scheme跳转字段)
@property (nonatomic, copy) NSString *deeplinkUrl;
// 落地页地址
@property (nonatomic, copy) NSString *landingPageUrl;

@property (nonatomic, strong) ADRanFengAppPromotionModel *appPromotion;
// 监测上报
@property (nonatomic, strong) ADRanFengTrackModel *tracker;

@property (nonatomic, assign) CGSize adSize;

/**
 未知                 未知                  0
 开屏                 大图竖图           1
 插屏                 插屏                  2    备用
 横幅                 横幅                  3
 单图信息流      大图横图           4
 多图信息流      三图广告           5
 视频                 视频                  6
 icon                  icon                  8    暂无
            激励浏览           9    暂无
 
 开屏：默认开屏（!=4）、信息流开屏（4）
 插屏：默认插屏（!=4）、信息流开屏（4）
 Banner：默认Banner（!=4）、信息流开屏（4）
 */
@property (nonatomic, assign) NSInteger materialType;

/**
 素材样式ID
 */
@property (nonatomic, copy) NSString *adStyle;

//渠道名称 返回字段adSource
@property (nonatomic, copy) NSString *channel;

//互动广告样式 0:默认 1:摇一摇 2:滑一滑 3:开屏无热区 4:擦一擦 5:转动手机
@property (nonatomic, assign) NSInteger interactStyle;

/// 互动玩法 0:默认 21:向上滑动 22:向左滑动 23:弧形 51:转一转 52:扭一扭
@property (nonatomic, assign) NSInteger interactSubStyle;

// 微信小程序调起
@property (nonatomic, strong) NSString *wechatId;/**< 小程序原始id */
@property (nonatomic, strong) NSString *wechatPath;/**< 拉起小程序页面的可带参路劲 */


// 视频类型广告配置信息
@property (nonatomic, strong) ADRanFengVideoModel *video;

// HeadBidding底价，单位分
@property (nonatomic, assign) NSInteger bidFloor;

// HeadBidding价格，单位分
@property (nonatomic, assign) NSInteger bidPrice;

// 竟赢通知，头部竞价时会返回
@property (nonatomic, copy) NSString *winNoticeUrl;

// 竟败通知，头部竞价时会返回
@property (nonatomic, copy) NSString *lossNoticeUrl;

#pragma mark - 辅助方法及参数 （部分外界传入）
// 当前广告素材是否有效（针对竞价广告位，10分钟内有效 && 上报竞价成功）
@property (nonatomic, assign) BOOL isDataValid;

// 是否超过有效时间
@property (nonatomic, assign) BOOL isDataTimeout;

// 是否是竞价广告位（由外部传值）
@property (nonatomic, assign) BOOL isHeadbidding;

// 竞价广告传入竟赢价格是否有效
@property (nonatomic, assign) BOOL isValidPostPrice;
// 是否有渠道名称
@property (nonatomic, assign,readonly) BOOL isHaveChannel;

@property (nonatomic, copy) NSString *shakeSensitivity;/**< 摇一摇灵敏度 */

@property (nonatomic, strong) NSArray<NSString *> *dropEffectIcons;/**< 撒花效果icon */



- (instancetype)initAdDataModelWithJson:(NSDictionary *)json NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
