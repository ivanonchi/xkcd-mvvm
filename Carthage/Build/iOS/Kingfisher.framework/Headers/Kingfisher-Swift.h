// Generated by Apple Swift version 3.0.1 (swiftlang-800.0.58.6 clang-800.0.42.1)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if defined(__has_attribute) && __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
@import Foundation;
@import CoreGraphics;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class UIImage;
@class CALayer;
@class NSCoder;

/**
  \code
  AnimatedImageView
  \endcode is a subclass of \code
  UIImageView
  \endcode for displaying animated image.
*/
SWIFT_CLASS("_TtC10Kingfisher17AnimatedImageView")
@interface AnimatedImageView : UIImageView
/**
  Whether automatically play the animation when the view become visible. Default is true.
*/
@property (nonatomic) BOOL autoPlayAnimatedImage;
/**
  The size of the frame cache.
*/
@property (nonatomic) NSInteger framePreloadCount;
/**
  Specifies whether the GIF frames should be pre-scaled to save memory. Default is true.
*/
@property (nonatomic) BOOL needsPrescaling;
/**
  The animation timer’s run loop mode. Default is \code
  NSRunLoopCommonModes
  \endcode. Set this property to \code
  NSDefaultRunLoopMode
  \endcode will make the animation pause during UIScrollView scrolling.
*/
@property (nonatomic) NSRunLoopMode _Nonnull runLoopMode;
@property (nonatomic, strong) UIImage * _Nullable image;
@property (nonatomic, readonly) BOOL isAnimating;
/**
  Starts the animation.
*/
- (void)startAnimating;
/**
  Stops the animation.
*/
- (void)stopAnimating;
- (void)displayLayer:(CALayer * _Nonnull)layer;
- (void)didMoveToWindow;
- (void)didMoveToSuperview;
- (BOOL)shouldPreloadAllGIF;
- (nonnull instancetype)initWithImage:(UIImage * _Nullable)image OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithImage:(UIImage * _Nullable)image highlightedImage:(UIImage * _Nullable)highlightedImage OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class NSURLSession;
@class NSURLSessionDataTask;
@class NSURLResponse;
@class NSURLSessionTask;
@class NSURLAuthenticationChallenge;
@class NSURLCredential;

SWIFT_CLASS("_TtC10Kingfisher29ImageDownloaderSessionHandler")
@interface ImageDownloaderSessionHandler : NSObject <NSURLSessionDataDelegate>
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didReceiveResponse:(NSURLResponse * _Nonnull)response completionHandler:(void (^ _Nonnull)(NSURLSessionResponseDisposition))completionHandler;
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didReceiveData:(NSData * _Nonnull)data;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didCompleteWithError:(NSError * _Nullable)error;
/**
  This method is exposed since the compiler requests. Do not call it.
*/
- (void)URLSession:(NSURLSession * _Nonnull)session didReceiveChallenge:(NSURLAuthenticationChallenge * _Nonnull)challenge completionHandler:(void (^ _Nonnull)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable))completionHandler;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface NSMutableData (SWIFT_EXTENSION(Kingfisher))
/**
  Convenient way to append bytes
*/
- (void)appendBytes:(NSArray<NSNumber *> * _Nonnull)arrayOfBytes;
@end


@interface UIApplication (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIButton (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIButton (SWIFT_EXTENSION(Kingfisher))
/**
  Cancel the image download task bounded to the image view if it is running.
  Nothing will happen if the downloading has already finished.
*/
- (void)kf_cancelImageDownloadTask;
/**
  Cancel the background image download task bounded to the image view if it is running.
  Nothing will happen if the downloading has already finished.
*/
- (void)kf_cancelBackgroundImageDownloadTask;
/**
  Get the image URL binded to this button for a specified state.
  \param state The state that uses the specified image.


  returns:
  Current URL for image.
*/
- (NSURL * _Nullable)kf_webURLFor:(UIControlState)state;
/**
  Get the background image URL binded to this button for a specified state.
  \param state The state that uses the specified background image.


  returns:
  Current URL for background image.
*/
- (NSURL * _Nullable)kf_backgroundWebURLFor:(UIControlState)state;
@end


@interface UIColor (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
/**
  Normalize the image. This method does nothing in OS X.

  returns:
  The image itself.
*/
- (UIImage * _Nonnull)kf_normalized;
/**
  Create a round corner image based on \code
  self
  \endcode.
  note:
  This method only works for CG-based image.
  \param radius The round corner radius of creating image.

  \param size The target size of creating image.

  \param scale The image scale of creating image.


  returns:
  An image with round corner of \code
  self
  \endcode.
*/
- (UIImage * _Nonnull)kf_imageWithRoundRadius:(CGFloat)radius fit:(CGSize)size scale:(CGFloat)scale;
/**
  Resize \code
  self
  \endcode to an image of new size.
  note:
  This method only works for CG-based image.
  \param size The target size.


  returns:
  An image with new size.
*/
- (UIImage * _Nonnull)kf_resizeTo:(CGSize)size;
/**
  Create an image with blur effect based on \code
  self
  \endcode.
  note:
  This method only works for CG-based image.
  \param radius The blur radius should be used when creating blue.


  returns:
  An image with blur effect applied.
*/
- (UIImage * _Nonnull)kf_blurredWithRadius:(CGFloat)radius;
/**
  Create an image from \code
  self
  \endcode with a color overlay layer.
  note:
  This method only works for CG-based image.
  \param color The color should be use to overlay.

  \param fraction Fraction of input color. From 0.0 to 1.0. 0.0 means solid color, 1.0 means transparent overlay.


  returns:
  An image with a color overlay applied.
*/
- (UIImage * _Nonnull)kf_overlayingWith:(UIColor * _Nonnull)color fraction:(CGFloat)fraction;
/**
  Create an image from \code
  self
  \endcode with a color tint.
  \param color The color should be used to tint \code
  self
  \endcode


  returns:
  An image with a color tint applied.
*/
- (UIImage * _Nonnull)kf_tintedWith:(UIColor * _Nonnull)color;
/**
  Create an image from \code
  self
  \endcode with color control.
  \param brightness Brightness changing to image.

  \param contrast Contrast changing to image.

  \param saturation Saturation changing to image.

  \param inputEV InputEV changing to image.


  returns:
  An image with color control applied.
*/
- (UIImage * _Nonnull)kf_adjustedWithBrightness:(CGFloat)brightness contrast:(CGFloat)contrast saturation:(CGFloat)saturation inputEV:(CGFloat)inputEV;
@end


@interface UIImageView (SWIFT_EXTENSION(Kingfisher))
- (BOOL)shouldPreloadAllGIF;
@end


@interface UIImageView (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImageView (SWIFT_EXTENSION(Kingfisher))
/**
  Cancel the image download task bounded to the image view if it is running.
  Nothing will happen if the downloading has already finished.
*/
- (void)kf_cancelDownloadTask;
/**
  Get the image URL binded to this image view.
*/
@property (nonatomic, readonly, copy) NSURL * _Nullable kf_webURL;
@end

#pragma clang diagnostic pop
