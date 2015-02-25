// Copyright 2010, Shuo Chen.  All rights reserved.
// http://github.com/chenshuo/evcpp
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//

#ifndef EVCPP_TIMER_H
#define EVCPP_TIMER_H

// this is an internal header file, you should include evcpp.h only.

namespace evcpp
{
class Timestamp
{
 public:
  Timestamp()
      : microseconds_(0)
  {
  }

  Timestamp(int64_t microsecondsSinceEpoch)
      : microseconds_(microsecondsSinceEpoch)
  {
  }

  static Timestamp now()
  {
    struct timeval tv;
    ::gettimeofday(&tv, NULL);
    return Timestamp(tv.tv_sec*1000000 + tv.tv_usec);
  }

 private:
  int64_t microseconds_;
};

class TimerId
{
};
}

#endif  // EVCPP_TIMER_H
