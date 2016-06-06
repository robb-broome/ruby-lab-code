
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_CORBA_Asynchron__
#define __gnu_CORBA_Asynchron__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace CORBA
    {
        class Asynchron;
    }
  }
  namespace org
  {
    namespace omg
    {
      namespace CORBA
      {
          class Request;
      }
    }
  }
}

class gnu::CORBA::Asynchron : public ::java::lang::Object
{

public:
  Asynchron();
  virtual void send_multiple_requests_oneway(JArray< ::org::omg::CORBA::Request * > *);
  virtual void send_multiple_requests_deferred(JArray< ::org::omg::CORBA::Request * > *);
  virtual jboolean poll_next_response();
  virtual ::org::omg::CORBA::Request * get_next_response();
public: // actually package-private
  ::java::util::LinkedList * __attribute__((aligned(__alignof__( ::java::lang::Object)))) sent;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_CORBA_Asynchron__
