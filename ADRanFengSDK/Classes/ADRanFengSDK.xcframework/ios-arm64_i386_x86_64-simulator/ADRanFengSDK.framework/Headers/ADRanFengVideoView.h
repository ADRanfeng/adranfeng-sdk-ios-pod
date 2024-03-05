//
//  ADRanFengVideoView.h
//  ADRanFengSDK
//
//  Created by 技术2 on 2021/11/5.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(NSInteger, ADRanFengPlayerState) {
    ADRanFengPlayerStateInitial = 0,//初始化状态
    ADRanFengPlayerStateBuffering = 1,//缓冲中
    ADRanFengPlayerStatePlaying = 2,//播放中
    ADRanFengPlayerStatePaused = 3,//播放暂停
    ADRanFengPlayerStateStopped = 4,//播放停止
    ADRanFengPlayerStateError = 5,//播放出错
    ADRanFengPlayerStateFinish = 6,//播放完成
};

NS_ASSUME_NONNULL_BEGIN

@protocol ADRanFengVideoViewPlayerDelegate;

@interface ADRanFengVideoView : UIView

/**
 播放状态
 */
@property (nonatomic ,assign) ADRanFengPlayerState videoPlayState;

/**
 是否隐藏进度条 默认不隐藏
 */
@property (nonatomic , assign) BOOL isHiddenProgressView;

/**
 播放
 */
- (void)play;

/**
 暂停
 */
- (void)pause;

/**
 是否静音,返回当前是否为静音状态
 */
- (BOOL)setPlayOrMute;

/**
 设置播放视图frame
 */
- (void)updateVideoFrame:(CGRect)newframe;

/**
 初始化player
 */
- (void)initPlayer;

/**
 重置player时间
 */
- (void)resetPlayerTime;

/**
 设置静音
 */
@property (nonatomic, assign) BOOL defaultPlayMute;


- (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame  NS_UNAVAILABLE;
/**
 推荐初始化方法
 @prama frame 视图大小
 @prama defaultPlayMute 默认播放静音YES/非静音NO
 @prama videoUrlString 播放地址
 */
- (instancetype)initWithFrame:(CGRect)frame defaultPlayMute:(BOOL)defaultPlayMute videoUrlString:(NSString *)videoUrlString delegate:(id<ADRanFengVideoViewPlayerDelegate>)videoDelegate;


@end

@protocol ADRanFengVideoViewPlayerDelegate <NSObject>

- (void)videoViewPlayerState:(ADRanFengPlayerState)videoPlayState withVideoView:(ADRanFengVideoView *)videoView withError:(NSError * _Nullable)error;

- (void)videoViewReadyToPlay:(ADRanFengVideoView *)videoView;

- (void)videoViewDidClick:(ADRanFengVideoView *)videoView withClickPoint:(CGPoint)clickPoint withScreenClickPoint:(CGPoint)screenClickPoint;

- (void)videoViewPlayerLifeTime:(NSUInteger)time videoDuration:(NSUInteger)duration withVideoView:(ADRanFengVideoView *)videoView;

- (void)videoViewCacheVideoFinish:(ADRanFengVideoView *)videoView;

- (void)videoViewCacheFail:(ADRanFengVideoView *)videoView withError:(NSError * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
