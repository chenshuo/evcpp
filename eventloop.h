// Copyright 2010, Shuo Chen.  All rights reserved.
// http://github.com/chenshuo/evcpp
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//

#ifndef EVCPP_EVENTLOOP_H
#define EVCPP_EVENTLOOP_H

// this is an internal header file, you should include evcpp.h only.

namespace evcpp
{

class EventLoop : noncopyable
{
 public:
  EventLoop()
    : base_(::event_base_new())
  {
    assert(base_ != NULL);
  }

  ~EventLoop()
  {
    ::event_base_free(base_);
  }

  int loop()
  {
    return ::event_base_loop(base_, 0);
  }

  // void runInLoop(const Functor& cb);
  // void queueInLoop(const Functor& cb);
  // TimerId runAt(const Timestamp& time, const TimerCallback& cb);
  // TimerId runAfter(double delay, const TimerCallback& cb);
  // TimerId runEvery(double interval, const TimerCallback& cb);
  // void cancel(TimerId timerId);

  struct event_base* eventBase()
  {
    return base_;
  }

 private:
  struct event_base* const base_;
  // pthread_t 
};
}

#endif  // EVCPP_EVENTLOOP_H

