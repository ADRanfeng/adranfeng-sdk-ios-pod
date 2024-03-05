//
//  ADRanFengKitLogging.h
//  ADRanFengSDK
//
//  Created by 刘娟 on 2022/10/11.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ADRanFengKitLogLevel) {
    /// No logs
    ADRanFengKitLogLevelOff     = 0,
    /// Error logs only. 0...00001
    ADRanFengKitLogLevelError   = (1 << 0),
    /// Error and warning logs, 0...00010
    ADRanFengKitLogLevelWarning = (1 << 1),
    /// Error, warning and info logs, 0...00100
    ADRanFengKitLogLevelInfo    = (1 << 2),
    /// Error, warning, info and debug logs, 0...01000
    ADRanFengKitLogLevelDebug   = (1 << 3),
    /// Error, warning, info, debug and verbose logs, 0...10000
    ADRanFengKitLogLevelVerbose = (1 << 4),
    /// All logs. 1...11111
    ADRanFengKitLogLevelAll     = NSUIntegerMax
};

ADRanFengKitLogLevel ADRanFengKitLogGetLevel(void);
void ADRanFengKitLogSetLevel(ADRanFengKitLogLevel level);

FOUNDATION_EXPORT void _ADRanFengKitLogError(NSString *format, ...);
FOUNDATION_EXPORT void _ADRanFengKitLogWarn(NSString *format, ...);
FOUNDATION_EXPORT void _ADRanFengKitLogInfo(NSString *format, ...);
FOUNDATION_EXPORT void _ADRanFengKitLogDebug(NSString *format, ...);
FOUNDATION_EXPORT void _ADRanFengKitLogVerbose(NSString *format, ...);

#ifdef DEBUG
    #define ADRanFengKitLogError(...)   _ADRanFengKitLogError(__VA_ARGS__)
    #define ADRanFengKitLogWarn(...)    _ADRanFengKitLogWarn(__VA_ARGS__)
    #define ADRanFengKitLogInfo(...)    _ADRanFengKitLogInfo(__VA_ARGS__)
    #define ADRanFengKitLogDebug(...)   _ADRanFengKitLogDebug(__VA_ARGS__)
    #define ADRanFengKitLogVerbose(...) _ADRanFengKitLogVerbose(__VA_ARGS__)
#else
    #define ADRanFengKitLogError(...)   _ADRanFengKitLogError(__VA_ARGS__)
    #define ADRanFengKitLogWarn(...)    _ADRanFengKitLogWarn(__VA_ARGS__)
    #define ADRanFengKitLogInfo(...)    _ADRanFengKitLogInfo(__VA_ARGS__)
    #define ADRanFengKitLogDebug(...)   _ADRanFengKitLogDebug(__VA_ARGS__)
    #define ADRanFengKitLogVerbose(...) {}
#endif
