//
//  ADRanFengNativeExpressView.h
//  ADRanFengSDK
//
//  Created by 陈则富 on 2021/9/15.
//

#import <UIKit/UIKit.h>
#import "ADRanFengDataModel.h"
#import "ADRanFengExpressViewRegisterProtocol.h"
#import "ADRanFengCommonDefine.h"
#import "ADRanFengClickPointModel.h"

NS_ASSUME_NONNULL_BEGIN
@class ADRanFengNativeExpressView;
@protocol ADRanFengNativeExpressViewDelegate <NSObject>
- (void)ranfengExpressAdViewClick:(ADRanFengNativeExpressView *)expressAdView clickPoints:(ADRanFengClickPointModel *)points optimize:(BOOL)optimize;
- (void)ranfengExpressAdViewClose:(ADRanFengNativeExpressView *)expressAdView;
- (void)ranfengExpressAdViewRenderSucceed:(ADRanFengNativeExpressView *)expressAdView;
- (void)ranfengExpressAdViewRenderFail:(ADRanFengNativeExpressView *)expressAdView error:(NSError *)error;
// 视频信息流相关
- (void)ranfengExpressAdViewVideoStartPlay:(ADRanFengNativeExpressView *)expressAdView;
- (void)ranfengExpressAdViewVideoPlayFail:(ADRanFengNativeExpressView *)expressAdView error:(NSError *)error;
- (void)ranfengExpressAdViewVideoPause:(ADRanFengNativeExpressView *)expressAdView;
- (void)ranfengExpressAdViewVideoFinish:(ADRanFengNativeExpressView *)expressAdView;

@end

@interface ADRanFengNativeExpressView : UIView<ADRanFengExpressViewRegisterProtocol>


- (instancetype)initWithAdData:(ADRanFengDataModel *)adData;

@property (nonatomic, strong) NSValue *insetsValue;

@property (nonatomic, assign) CGFloat adWidth;

@property (nonatomic, weak) id<ADRanFengNativeExpressViewDelegate> delegate;

@property (nonatomic, strong) ADRanFengDataModel *nativeAdData;

@property (nonatomic, assign) BOOL playMute;

@property(nonatomic ,assign) BOOL autoPlay;

@property (nonatomic, assign) ADRanFengRenderType renderType;



/*
 移除擦一擦蒙层效果
 */
- (void)removeClearView;

/**
 获取到竟赢
 */
- (void)get_didWin;
@end

NS_ASSUME_NONNULL_END
