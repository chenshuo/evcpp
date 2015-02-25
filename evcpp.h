// Copyright 2010, Shuo Chen.  All rights reserved.
// http://github.com/chenshuo/evcpp
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//

#ifndef EVCPP_EVCPP_H
#define EVCPP_EVCPP_H

#include <assert.h>

#include <event2/bufferevent.h>
#include <event2/event.h>
#include <event2/listener.h>

// #include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

#include <functional>
#include <memory>

namespace evcpp
{
class noncopyable
{
 protected:
  noncopyable() {}
 private:
  noncopyable(const noncopyable&);
  void operator=(const noncopyable&);
};
}
#include "callback.h"
#include "timer.h"
#include "eventloop.h"
#include "connection.h"
#include "listener.h"

#endif  // EVCPP_EVCPP_H

