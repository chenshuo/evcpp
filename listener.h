// Copyright 2010, Shuo Chen.  All rights reserved.
// http://github.com/chenshuo/evcpp
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//

#ifndef EVCPP_LISTENER_H
#define EVCPP_LISTENER_H

// this is an internal header file, you should include evcpp.h only.

namespace evcpp
{
class Listener : noncopyable
{
 public:
  Listener(EventLoop* loop, int port)
    : listener_(evconnlistener_new_bind(
          loop->eventBase(),
          newConnectionCallback,
          this,
          LEV_OPT_CLOSE_ON_FREE | LEV_OPT_CLOSE_ON_EXEC | LEV_OPT_REUSEABLE,
          -1,  // backlog
          getListenSock(port),
          sizeof(struct sockaddr_in)))
  {
    assert(listener_ != nullptr);
  }

  ~Listener()
  {
    ::evconnlistener_free(listener_);
  }

  void setNewConnectionCallback(const NewConnectionCallback& cb)
  { callback_ = cb; }

  // void start() { }

 private:

  void onConnect(evutil_socket_t fd, const struct sockaddr_in* address)
  {
    static_assert(std::is_same<evutil_socket_t, int>::value,
                  "evutil_socket_t is int");
    if (callback_)
    {
      TcpConnectionPtr conn(std::make_shared<TcpConnection>(
          evconnlistener_get_base(listener_), fd));
      callback_(std::move(conn));
    }
    else
    {
      ::close(fd);
    }
  }

  static struct sockaddr* getListenSock(int port)
  {
    static __thread struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
    return reinterpret_cast<struct sockaddr*>(&sin);
  }

  static void newConnectionCallback(struct evconnlistener* listener,
      evutil_socket_t fd, struct sockaddr* address, int socklen, void* ctx)
  {
    Listener* self = static_cast<Listener*>(ctx);
    assert(self->listener_ == listener);
    assert(socklen == sizeof(struct sockaddr_in));
    self->onConnect(fd, reinterpret_cast<struct sockaddr_in*>(address));
  }

  struct evconnlistener* const listener_;
  NewConnectionCallback callback_;
};
}

#endif  // EVCPP_LISTENER_H


