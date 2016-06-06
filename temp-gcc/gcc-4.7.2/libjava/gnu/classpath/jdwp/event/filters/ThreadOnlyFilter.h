
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_classpath_jdwp_event_filters_ThreadOnlyFilter__
#define __gnu_classpath_jdwp_event_filters_ThreadOnlyFilter__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace classpath
    {
      namespace jdwp
      {
        namespace event
        {
            class Event;
          namespace filters
          {
              class ThreadOnlyFilter;
          }
        }
        namespace id
        {
            class ThreadId;
        }
      }
    }
  }
}

class gnu::classpath::jdwp::event::filters::ThreadOnlyFilter : public ::java::lang::Object
{

public:
  ThreadOnlyFilter(::gnu::classpath::jdwp::id::ThreadId *);
  virtual ::gnu::classpath::jdwp::id::ThreadId * getThread();
  virtual jboolean matches(::gnu::classpath::jdwp::event::Event *);
private:
  ::gnu::classpath::jdwp::id::ThreadId * __attribute__((aligned(__alignof__( ::java::lang::Object)))) _tid;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_classpath_jdwp_event_filters_ThreadOnlyFilter__
