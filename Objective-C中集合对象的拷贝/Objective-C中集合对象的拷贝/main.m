//
//  main.m
//  Objective-C中集合对象的拷贝
//
//  Created by Brooks on 2017/10/23.
//  Copyright © 2017年 https://github.com/BrooksWon. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MyClass.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        MyClass *cls = [[MyClass alloc] init];
        cls.number = @(100);// default is 100
        
        // 1.NSArray 与 copy
        NSArray *array = [NSArray arrayWithObjects:@"Brooks",[NSURL URLWithString:@"https://github.com/BrooksWon"],cls,nil];
        NSArray *copy_array = [array copy];
        
        cls.number = @(200);
        
        NSLog(@"array:%p, cls.number = %@", array, cls.number);
        NSLog(@"copy_array:%p,  cls.number = %@", copy_array, cls.number);
        
        //结果显示：原始 array 和 copy_array 的地址相同，cls的地址相同
        //可以理解为：仅拷贝该NSArray实例对象的指针以及该集合里面存储对象的指针，不拷贝该集合里面存储对象的真实数据。常量数据对象除外；如：常量字符串、常量数字，如：NSString、NSSNumber 等。常量数据对象可以看作直接拷贝真实数据
        
        
        
        
        cls.number = @(100); // reset
        
        // 2.NSArray 与 mutableCopy
        NSArray *mutableCopy_array = [array mutableCopy];
        
        cls.number = @(200);
        
        NSLog(@"array:%p, cls.number = %@", array, cls.number);
        NSLog(@"mutableCopy_array:%p,  cls.number = %@", mutableCopy_array, cls.number);
        
        //结果显示：原始 array 和 mutableCopy_array 的地址不同，cls的地址相同
        //可以理解为：拷贝该NSArray实例对象的指针地址 以及 该集合里面存储对象的指针，不拷贝该集合里面存储对象的真实数据。常量数据对象除外；如：常量字符串、常量数字，如：NSString、NSSNumber 等。常量数据对象可以看作直接拷贝真实数据
        
        
        cls.number = @(100); // reset
        
        // 3.NSMutableArray 与 copy
        NSMutableArray *mArray = [NSMutableArray arrayWithObjects:@"Brooks",[NSURL URLWithString:@"https://github.com/BrooksWon"],cls,nil];
        NSMutableArray *copy_mArray = [mArray copy];
        
        cls.number = @(200);


        NSLog(@"mArray:%p, cls.number = %@", mArray, cls.number);
        NSLog(@"copy_mArray:%p,  cls.number = %@", copy_mArray, cls.number);
        
        //结果显示：原始 mArray 和 copy_mArray 的地址不同，cls的地址相同
        //可以理解为：仅拷贝该NSMutableArray实例对象的指针地址以及该集合里面存储对象的指，不拷贝该集合里面存储对象的真实数据。常量数据对象除外；如：常量字符串、常量数字，如：NSString、NSSNumber 等。常量数据对象可以看作直接拷贝真实数据
        
        
        cls.number = @(100); // reset
        
        // 4.NSMutableArray 与 mutableCopy
        NSMutableArray *mutableCopy_mArray = [mArray mutableCopy];
        
        cls.number = @(200);

        
        NSLog(@"mArray:%p, cls.number = %@", mArray, cls.number);
        NSLog(@"mutableCopy_mArray:%p,  cls.number = %@", mutableCopy_mArray, cls.number);
        
        //结果显示：原始 mArray 和 mutableCopy_mArray 的地址不同，cls的地址相同
        //可以理解为：仅拷贝该NSMutableArray实例对象的指针地址以及该集合里面存储对象的指针，不拷贝该集合里面存储对象的真实数据。常量数据对象除外；如：常量字符串、常量数字，如：NSString、NSSNumber 等 。常量数据对象可以看作直接拷贝真实数据
        
        // 5.常量对象参与的copy、mutableCopy
        NSNumber *constNumberObject = @(123);
        NSString *constStringObject = @"abc";
        NSMutableString *enity = [NSMutableString stringWithFormat:@"999"];

        NSArray  *constObjectArray  = [NSArray arrayWithObjects:constNumberObject,constStringObject,enity, nil];
        
        NSArray *copy_constObjectArray = [constObjectArray copy];
        NSArray *mutableCopy_constObjectArray = [constObjectArray mutableCopy];
        
        constNumberObject = @(456);
        constStringObject = @"def";
        [enity setString:@"888"];
        
        NSLog(@"constObjectArray:%p", copy_constObjectArray);
        NSLog(@"copy_constObjectArray:%p", copy_constObjectArray);
        NSLog(@"mutableCopy_constObjectArray:%p", mutableCopy_constObjectArray);
        
        
        /**
         TODO: 下方这些，同学们可以自己写例子
         
         NSDictionary / NSMutableDictionary, NSSet / NSMutableSet
         
         */

    }
    return 0;
}
