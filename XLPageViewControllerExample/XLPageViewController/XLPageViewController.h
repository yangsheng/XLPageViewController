//
//  XLPageViewController.h
//  XLPageViewControllerExample
//
//  Created by MengXianLiang on 2019/5/6.
//  Copyright © 2019 jwzt. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XLPageViewControllerConfig.h"

@class XLPageViewController;

NS_ASSUME_NONNULL_BEGIN

@protocol XLPageViewControllerDelegate <NSObject>

- (void)pageViewController:(XLPageViewController *)pageViewController didSelectedAtIndex:(NSInteger)index;

@end

@protocol XLPageViewControllerDataSrouce <NSObject>

@required
/**
 根据index返回对应的ViewController

 @param pageViewController XLPageViewController实例
 @param index 当前位置
 @return 返回要展示的ViewController
 */
- (UIViewController *)pageViewController:(XLPageViewController *)pageViewController viewControllerForIndex:(NSInteger)index;

/**
 根据index返回对应的标题

 @param pageViewController XLPageViewController实例
 @param index 当前位置
 @return 返回要展示的标题
 */
- (NSString *)pageViewController:(XLPageViewController *)pageViewController titleForIndex:(NSInteger)index;

/**
 要展示分页数

 @return 返回分页数
 */
- (NSInteger)pageViewControllerNumberOfPage;

@end

@interface XLPageViewController : UIViewController

/**
 代理
 */
@property (nonatomic, weak) id <XLPageViewControllerDelegate> delegate;

/**
 数据源
 */
@property (nonatomic, weak) id <XLPageViewControllerDataSrouce> dataSource;

/**
 当前位置 默认是0
 */
@property (nonatomic, assign) NSInteger selectedIndex;

/**
 初始化方法

 @param config 配置信息
 @return XLPageViewController 实例
 */
- (instancetype)initWithConfig:(XLPageViewControllerConfig *)config;

/**
 刷新方法，当标题改变时，执行此方法
 */
- (void)reloadData;

@end

NS_ASSUME_NONNULL_END