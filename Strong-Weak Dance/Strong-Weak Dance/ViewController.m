//
//  ViewController.m
//  Strong-Weak Dance
//
//  Created by Brooks on 2017/11/18.
//  Copyright © 2017年 https://github.com/BrooksWon All rights reserved.
//

#import "ViewController.h"
#import <UIKit/UIKit.h>

typedef void(^MyBlock)();

@interface ViewController ()

@property (nonatomic, copy) MyBlock myBoock;

@end

@implementation ViewController

#if 0
// 此时会retain cycle
- (void)viewDidLoad {
    [super viewDidLoad];

    
    _myBoock = ^{
        NSLog(@"self = %@", self);
    };
    _myBoock();
    
}

#endif

#if 0
// 如果当前VC在dispatch_after函数未执行结束时被释放，会造成crash
- (void)viewDidLoad {
    [super viewDidLoad];
    
    __weak __typeof(self) weakSelf = self;
    
    _myBoock = ^(){
        NSLog(@"self = %@", weakSelf);
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(4 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
            [array addObject:weakSelf];
        });
    };
    _myBoock();
    
    
}

#endif

//#if 0
// 这是 Strong-Weak Dance 正确姿势
- (void)viewDidLoad {
    [super viewDidLoad];
    
    __weak __typeof(self) weakSelf = self;
    
    _myBoock = ^(){
        __strong __typeof(weakSelf) strongSelf = weakSelf;
        NSLog(@"self = %@", strongSelf);
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(4 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
            [array addObject:strongSelf];
        });
    };
    _myBoock();
    
    
}

//#endif


@end
