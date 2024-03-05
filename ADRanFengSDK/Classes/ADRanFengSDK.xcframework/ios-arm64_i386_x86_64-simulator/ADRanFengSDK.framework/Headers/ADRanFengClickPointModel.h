//
//  ADRanFengClickPointModel.h
//  ADRanFengSDK
//
//  Created by 刘娟 on 2022/12/6.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface ADRanFengClickPointModel : NSObject

@property (nonatomic , assign) CGPoint startPoint;/**< 开始位置 */
@property (nonatomic , assign) CGPoint endPoint;/**< 结束位置 */
@property (nonatomic , assign) CGPoint startScreenPoint;/**< 相对于父控制器开始位置 */
@property (nonatomic , assign) CGPoint endScreenPoint;/**< 相对于父控制器结束位置 */

/// 获取默认值是-999的坐标
+(instancetype)getDefaultPoint999;

@end

NS_ASSUME_NONNULL_END
