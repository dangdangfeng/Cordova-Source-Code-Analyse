/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 
 原生代码拿到 callbackId、service、action 及 actionArgs 后，会做以下的处理：
 
 1.根据 service 参数找到对应的插件类
 2.根据 action 参数找到插件类中对应的处理方法，并把 actionArgs 作为处理方法请求参数的一部分传给处理方法
 3.处理完成后，把处理结果及 callbackId 返回给 JS 端，JS 端收到后会根据 callbackId 找到回调方法，并把处理结果传给回调方法
 
 */

#import <UIKit/UIKit.h>
#import "CDVCommandDelegate.h"

@class CDVViewController;
@class CDVCommandQueue;

@interface CDVCommandDelegateImpl : NSObject <CDVCommandDelegate>{
    @private
    __weak CDVViewController* _viewController;
    NSRegularExpression* _callbackIdPattern;
    @protected
    __weak CDVCommandQueue* _commandQueue;
    BOOL _delayResponses;
}
- (id)initWithViewController:(CDVViewController*)viewController;
- (void)flushCommandQueueWithDelayedJs;
@end
