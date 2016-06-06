
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_xml_stream_util_EventReaderDelegate__
#define __javax_xml_stream_util_EventReaderDelegate__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace xml
    {
      namespace stream
      {
          class XMLEventReader;
        namespace events
        {
            class XMLEvent;
        }
        namespace util
        {
            class EventReaderDelegate;
        }
      }
    }
  }
}

class javax::xml::stream::util::EventReaderDelegate : public ::java::lang::Object
{

public:
  EventReaderDelegate();
  EventReaderDelegate(::javax::xml::stream::XMLEventReader *);
  virtual void setParent(::javax::xml::stream::XMLEventReader *);
  virtual ::javax::xml::stream::XMLEventReader * getParent();
  virtual ::javax::xml::stream::events::XMLEvent * nextEvent();
  virtual ::java::lang::Object * next();
  virtual jboolean hasNext();
  virtual ::javax::xml::stream::events::XMLEvent * peek();
  virtual ::java::lang::String * getElementText();
  virtual ::javax::xml::stream::events::XMLEvent * nextTag();
  virtual ::java::lang::Object * getProperty(::java::lang::String *);
  virtual void close();
  virtual void remove();
private:
  ::javax::xml::stream::XMLEventReader * __attribute__((aligned(__alignof__( ::java::lang::Object)))) parent;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_xml_stream_util_EventReaderDelegate__