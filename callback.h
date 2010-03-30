// Copyright 2010, Shuo Chen.  All rights reserved.
// http://github.com/chenshuo/evcpp
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//

#ifndef EVCPP_CALLBACK_H
#define EVCPP_CALLBACK_H

// this is an internal header file, you should include evcpp.h only.

namespace evcpp
{
typedef boost::function<void()> Functor;
typedef boost::function<void()> TimerCallback;
}

#endif  // EVCPP_CALLBACK_H

