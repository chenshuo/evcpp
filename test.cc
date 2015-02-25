// Copyright 2010, Shuo Chen.  All rights reserved.
// http://github.com/chenshuo/evcpp
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//

#include "evcpp.h"

void onConnect(evcpp::TcpConnectionPtr conn)
{
  printf("onConnect %zd\n", conn.use_count());
}

int main()
{
  evcpp::EventLoop loop;
  evcpp::Listener listener(&loop, 1234);
  listener.setNewConnectionCallback(onConnect);
  loop.loop();
}
