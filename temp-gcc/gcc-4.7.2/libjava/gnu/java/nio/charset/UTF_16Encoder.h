
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_nio_charset_UTF_16Encoder__
#define __gnu_java_nio_charset_UTF_16Encoder__

#pragma interface

#include <java/nio/charset/CharsetEncoder.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace nio
      {
        namespace charset
        {
            class UTF_16Encoder;
        }
      }
    }
  }
  namespace java
  {
    namespace nio
    {
        class ByteBuffer;
        class ByteOrder;
        class CharBuffer;
      namespace charset
      {
          class Charset;
          class CoderResult;
      }
    }
  }
}

class gnu::java::nio::charset::UTF_16Encoder : public ::java::nio::charset::CharsetEncoder
{

public: // actually package-private
  UTF_16Encoder(::java::nio::charset::Charset *, jint, jboolean);
public: // actually protected
  ::java::nio::charset::CoderResult * encodeLoop(::java::nio::CharBuffer *, ::java::nio::ByteBuffer *);
  void implReset();
public: // actually package-private
  static const jint BIG_ENDIAN = 0;
  static const jint LITTLE_ENDIAN = 1;
private:
  static const jchar BYTE_ORDER_MARK = 65279;
  ::java::nio::ByteOrder * __attribute__((aligned(__alignof__( ::java::nio::charset::CharsetEncoder)))) byteOrder;
  jboolean useByteOrderMark;
  jboolean needsByteOrderMark;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_nio_charset_UTF_16Encoder__