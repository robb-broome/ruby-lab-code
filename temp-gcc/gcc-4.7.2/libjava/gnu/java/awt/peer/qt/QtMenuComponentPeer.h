
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_peer_qt_QtMenuComponentPeer__
#define __gnu_java_awt_peer_qt_QtMenuComponentPeer__

#pragma interface

#include <gnu/java/awt/peer/qt/NativeWrapper.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        namespace peer
        {
          namespace qt
          {
              class QtMenuComponentPeer;
              class QtToolkit;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace awt
    {
        class Font;
        class MenuComponent;
    }
  }
}

class gnu::java::awt::peer::qt::QtMenuComponentPeer : public ::gnu::java::awt::peer::qt::NativeWrapper
{

public:
  QtMenuComponentPeer(::gnu::java::awt::peer::qt::QtToolkit *, ::java::awt::MenuComponent *);
public: // actually protected
  virtual void callInit();
  virtual void init();
  virtual void setup();
public:
  virtual void finalize();
  virtual void dispose();
  virtual void setFont(::java::awt::Font *);
public: // actually protected
  ::gnu::java::awt::peer::qt::QtToolkit * __attribute__((aligned(__alignof__( ::gnu::java::awt::peer::qt::NativeWrapper)))) toolkit;
  ::java::awt::MenuComponent * owner;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_peer_qt_QtMenuComponentPeer__
