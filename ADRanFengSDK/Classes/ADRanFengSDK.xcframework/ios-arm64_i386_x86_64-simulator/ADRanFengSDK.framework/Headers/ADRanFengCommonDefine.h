//
//  ADRanFengCommonDefine.h
//  ADRanFengSDK
//
//  Created by Jiangyou on 2021/9/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



typedef NS_ENUM(NSUInteger, ADRanFengLayoutType) {
    ADRanFengLayoutTypeTopImage = 1, // 上图下文
    ADRanFengLayoutTypeBottomImage = 2, // 上文下图
    ADRanFengLayoutTypeLeftImage = 3, // 左图右文
    ADRanFengLayoutTypeRightImage = 4, // 左文右图
    ADRanFengLayoutTypeHorizonImage = 5, // 纯图
};
/// 插屏素材库样式
typedef NS_ENUM(NSUInteger, ADRanFengInterstitialMaterialStyle) {
    /// 0：默认
    ADRanFengInterstitialMaterialStyleNormal = 0,
    /// 1：信封抽拉样式 纯图
    ADRanFengInterstitialMaterialStyleEnvelope = 1,
    /// 2：信封抽拉样式 图文
    ADRanFengInterstitialMaterialStyleEnvelopeImageAndText = 2,
    /// 3：默认信息流
    ADRanFengInterstitialMaterialStyleNativeNormal = 3,
};

/// 支持屏幕样式
typedef NS_ENUM(NSUInteger, ADRanFengAdSupportScreenType) {
    /// 0：默认 竖屏
    ADRanFengAdSupportScreenTypeNormal = 0,
    /// 1：只支持横屏
    ADRanFengAdSupportScreenTypeLandscape = 1,
    /// 2：支持横屏、竖屏之间切换
    ADRanFengAdSupportScreenTypeAuto = 2,
};


/// 互动样式
typedef NS_ENUM(NSUInteger, ADRanFengInteractType) {
    /// 0：默认
    ADRanFengInteractTypeNormal = 0,
    /// 1：摇一摇
    ADRanFengInteractTypeShake = 1,
    /// 2：滑一滑
    ADRanFengInteractTypeFinger = 2,
    /// 3：开屏无
    ADRanFengInteractTypeTap = 3,
    /// 4：擦一擦
    ADRanFengInteractTypeClear = 4,
    /// 5：转动手机
    ADRanFengInteractTypeTurn = 5,
    /// 6：摇一摇和多方向滑动的混合样式
    ADRanFengInteractTypeSlipAndShake = 6,
};

/// 互动玩法
typedef NS_ENUM(NSUInteger, ADRanFengInteractSubType) {
    /// 0：默认
    ADRanFengInteractSubTypeNormal = 0,
    /// 21：向上滑动
    ADRanFengInteractSubTypeTop = 21,
    /// 22：向右滑动
    ADRanFengInteractSubTypeRight = 22,
    /// 23：弧形滑动
    ADRanFengInteractSubTypeCurve = 23,
    /// 51：转一转
    ADRanFengInteractSubTypeTurn = 51,
    /// 52：扭一扭
    ADRanFengInteractSubTypeTwist = 52,
    
};


typedef NS_ENUM(NSUInteger, ADRanFengRenderType) {
    ADRanFengRenderTypeExpress = 1,// 模板
    ADRanFengRenderTypeNative = 2 // 自渲染
};
typedef NS_ENUM(NSUInteger, ADRanFengAnimateSlipDirection) {
    ADRanFengAnimateSlipDirectionDefault = 0,// 默认不支持滑动
    ADRanFengAnimateSlipDirectionTop = 1,// 向上滑动
    ADRanFengAnimateSlipDirectionDown = 2, // 向下滑动
    ADRanFengAnimateSlipDirectionLeft = 3, // 向左滑动
    ADRanFengAnimateSlipDirectionRight = 4, // 向右滑动
};
typedef NS_ENUM(NSInteger,ADRanFengBiddingLossReason) {
    ADRanFengBiddingLossReasonLowPrice          = 1,        // 竞争力不足
    ADRanFengBiddingLossReasonTimeout           = 2,        // 超时
    ADRanFengBiddingLossReasonOther             = 10001     // 其他
};

typedef NSString * ADRanFengType NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT ADRanFengType _Nonnull const ADRanFengTypeOther;

FOUNDATION_EXPORT ADRanFengType _Nonnull const ADRanFengTypeSplash;

FOUNDATION_EXPORT ADRanFengType _Nonnull const ADRanFengTypeBanner;

FOUNDATION_EXPORT ADRanFengType _Nonnull const ADRanFengTypeNative;

FOUNDATION_EXPORT ADRanFengType _Nonnull const ADRanFengTypeInterstitial;

FOUNDATION_EXPORT ADRanFengType _Nonnull const ADRanFengTypeRewardVodAd;

FOUNDATION_EXPORT ADRanFengType _Nonnull const ADRanFengTypeFullScrennVodAd;


typedef NSString * ADRanFengStyle NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT ADRanFengStyle _Nonnull const ADRanFengStyleSplashNomal;/**< 普通 */
FOUNDATION_EXPORT ADRanFengStyle _Nonnull const ADRanFengStyleSplashCurveHot;/**< 弧形热区 */
FOUNDATION_EXPORT ADRanFengStyle _Nonnull const ADRanFengStyleSplash3D;/**< 裸眼3D效果 */

FOUNDATION_EXPORT ADRanFengStyle _Nonnull const ADRanFengStyleInterstitialNomal;/**< 普通 */
FOUNDATION_EXPORT ADRanFengStyle _Nonnull const ADRanFengStyleInterstitialEnvelope;/**< 信封 */

FOUNDATION_EXPORT ADRanFengStyle _Nonnull const ADRanFengStyleFlowTOP_PIC_FLOW;/**< 上图下文 */
FOUNDATION_EXPORT ADRanFengStyle _Nonnull const ADRanFengStyleFlowBOTTOM_PIC_FLOW;/**< 上文下图 */
FOUNDATION_EXPORT ADRanFengStyle _Nonnull const ADRanFengStyleFlowHORIZON_PIC;/**< 横版纯图 */
FOUNDATION_EXPORT ADRanFengStyle _Nonnull const ADRanFengStyleFlowLEFT_PIC_FLOW;/**< 左图右文 */
FOUNDATION_EXPORT ADRanFengStyle _Nonnull const ADRanFengStyleFlowRIGHT_PIC_FLOW;/**< 左图右文 */

// 过期提醒
#define RFDeprecated(s) __attribute__((deprecated(s)))

NS_ASSUME_NONNULL_END
