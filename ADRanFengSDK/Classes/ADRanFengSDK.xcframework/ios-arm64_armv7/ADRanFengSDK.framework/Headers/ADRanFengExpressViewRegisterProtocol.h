//
//  ADRanFengExpressViewReigsterProtocol.h
//  ADRanFengSDK
//
//  Created by 陈则富 on 2021/9/15.
//

#import <UIKit/UIKit.h>
#import <ADRanFengSDK/ADRanFengCommonDefine.h>
NS_ASSUME_NONNULL_BEGIN

@interface ADRanFengNativeData : NSObject

/**
 广告标题
 */
@property (nonatomic, copy) NSString *title;

/**
 广告描述
 */
@property (nonatomic, copy) NSString *desc;

/**
 广告图片
 */
@property (nonatomic, copy) NSString *imageUrl;

/**
 广告多图列表
 */
@property (nonatomic, strong) NSArray<NSString *> *imageUrlArray;

/**
 是否是视频广告
 */
@property (nonatomic, assign) BOOL isVideoAd;

/**
 渠道名称
 */
@property (nonatomic, copy) NSString *channel;

/**
 是否有渠道名称
 */
@property (nonatomic, assign) BOOL isHaveChannel;

@end

@protocol ADRanFengExpressViewRegisterProtocol <NSObject>

/**
 渲染类型
 */
@property (nonatomic, assign) ADRanFengRenderType renderType;

/**
 广告数据模型,模板渲染为空
 */
@property (nonatomic, strong, readonly, nullable) ADRanFengNativeData *adData;

/**
 需要于成功回调中获取
 竞价广告出价,单位：分
 */
@property (nonatomic, assign, readonly,getter=getBidPrice) NSInteger bidPrice;

/**
 需要于成功回调中获取
 竞价广告底价,单位：分
 */
@property (nonatomic, assign, readonly,getter=getBidFloor) NSInteger bidFloor;

/**
 注册广告视图（必须调用的方法），不调用将无法渲染广告
 */
- (void)ranfeng_registViews:(NSArray<UIView *> *)clickViews;

/**
 获取视频视图，如果是模版广告则为nil
 */
- (nullable UIView *)ranfeng_mediaViewForWidth:(CGFloat)width;

/**
 获取logo图片
 */
- (void)ranfeng_platformLogoImageDarkMode:(BOOL)darkMode loadImageBlock:(void (^)(UIImage * _Nullable))block;

/**
 获取logo图片 不区分渠道
 */
- (void)ranfeng_platformLogoImageDarkMode:(BOOL)darkMode ignoreChannelLoadImageBlock:(void (^)(UIImage * _Nullable))block;

/**
 自渲染信息流关闭按钮响应方法（会回调关闭）
 */
- (void)ranfeng_close;

/**
 模板信息流重设广告尺寸
 */
- (void)ranfeng_setFrame:(CGRect)frame;

/**
 广告是否超时
 */
- (bool)ranfeng_isDataTimeout;

@end

NS_ASSUME_NONNULL_END
