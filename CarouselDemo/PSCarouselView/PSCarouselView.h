//
//  CarouselView.h
//
//  Created by Pan on 15/7/20.
//  Copyright (c) 2015年 Pan. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PSCarouselView;
@protocol PSCarouselDelegate <NSObject>

/**
 *  告诉代理，用图片URL设置imageView的图片
 *
 *  @param carousel   carousel
 *  @param imageView  需要设置图片的imageView
 *  @param imageURL   需要下载图片的URL
 *  @param page       imageURL的index
 */
- (void)carousel:(nonnull PSCarouselView *)carousel
    setImageView:(nonnull UIImageView *)imageView
    withImageURL:(nonnull NSURL *)imageURL
          atPage:(NSUInteger)page;

@optional

/**
 *  告诉代理滚动到哪一页了
 *
 *  @param carousel self
 *  @param page     已经计算好，直接使用即可
 */
- (void)carousel:(nonnull PSCarouselView *)carousel didMoveToPage:(NSUInteger)page;

/**
 *  告诉代理用户点击了某一页
 *
 *  @param carousel
 *  @param page imageURL的index
 */
- (void)carousel:(nonnull PSCarouselView *)carousel didTouchPage:(NSUInteger)page;
@end


@interface PSCarouselView : UICollectionView

@property (nullable, nonatomic, strong) NSArray *imageURLs;/**< 必须赋值。只要给这个imageURL赋值，会自动获取图片。刷新请再次给此属性赋值*/

@property (nullable, nonatomic, strong) IBInspectable UIImage *placeholder;/**< 没有轮播图时的占位图*/

@property (nonatomic,getter=isAutoMoving) IBInspectable BOOL autoMoving;/**< 是否自动轮播,默认为NO*/

@property (nonatomic) IBInspectable CGFloat movingTimeInterval;/**< 滚动速率 默认为3.0 即3秒翻页一次*/

@property (nonatomic) IBInspectable UIViewContentMode imageViewMode; /**< 图片显示的缩放模式,默认为ScaleAspectFill*/

@property (nullable, nonatomic, weak) id<PSCarouselDelegate> pageDelegate;

- (nonnull instancetype)initWithFrame:(CGRect)frame collectionViewLayout:(nonnull UICollectionViewLayout *)layout NS_UNAVAILABLE;
- (nonnull instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(nonnull NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (void)startMoving;

- (void)stopMoving;
@end
