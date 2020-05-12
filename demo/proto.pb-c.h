/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: proto.proto */

#ifndef PROTOBUF_C_proto_2eproto__INCLUDED
#define PROTOBUF_C_proto_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003003 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Proto__Question Proto__Question;
typedef struct _Proto__Answer Proto__Answer;


/* --- enums --- */


/* --- messages --- */

/*
 *提问
 */
struct  _Proto__Question
{
  ProtobufCMessage base;
  char *topic;
  char *tips;
};
#define PROTO__QUESTION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&proto__question__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string }


/*
 *回答
 */
struct  _Proto__Answer
{
  ProtobufCMessage base;
  char *result;
  int32_t times;
};
#define PROTO__ANSWER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&proto__answer__descriptor) \
    , (char *)protobuf_c_empty_string, 0 }


/* Proto__Question methods */
void   proto__question__init
                     (Proto__Question         *message);
size_t proto__question__get_packed_size
                     (const Proto__Question   *message);
size_t proto__question__pack
                     (const Proto__Question   *message,
                      uint8_t             *out);
size_t proto__question__pack_to_buffer
                     (const Proto__Question   *message,
                      ProtobufCBuffer     *buffer);
Proto__Question *
       proto__question__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   proto__question__free_unpacked
                     (Proto__Question *message,
                      ProtobufCAllocator *allocator);
/* Proto__Answer methods */
void   proto__answer__init
                     (Proto__Answer         *message);
size_t proto__answer__get_packed_size
                     (const Proto__Answer   *message);
size_t proto__answer__pack
                     (const Proto__Answer   *message,
                      uint8_t             *out);
size_t proto__answer__pack_to_buffer
                     (const Proto__Answer   *message,
                      ProtobufCBuffer     *buffer);
Proto__Answer *
       proto__answer__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   proto__answer__free_unpacked
                     (Proto__Answer *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Proto__Question_Closure)
                 (const Proto__Question *message,
                  void *closure_data);
typedef void (*Proto__Answer_Closure)
                 (const Proto__Answer *message,
                  void *closure_data);

/* --- services --- */

typedef struct _Proto__Proto_Service Proto__Proto_Service;
struct _Proto__Proto_Service
{
  ProtobufCService base;
  void (*learn)(Proto__Proto_Service *service,
                const Proto__Question *input,
                Proto__Answer_Closure closure,
                void *closure_data);
};
typedef void (*Proto__Proto_ServiceDestroy)(Proto__Proto_Service *);
void proto__proto__init (Proto__Proto_Service *service,
                         Proto__Proto_ServiceDestroy destroy);
#define PROTO__PROTO__BASE_INIT \
    { &proto__proto__descriptor, protobuf_c_service_invoke_internal, NULL }
#define PROTO__PROTO__INIT(function_prefix__) \
    { PROTO__PROTO__BASE_INIT,\
      function_prefix__ ## learn  }
void proto__proto__learn(ProtobufCService *service,
                         const Proto__Question *input,
                         Proto__Answer_Closure closure,
                         void *closure_data);

/* --- descriptors --- */

extern const ProtobufCMessageDescriptor proto__question__descriptor;
extern const ProtobufCMessageDescriptor proto__answer__descriptor;
extern const ProtobufCServiceDescriptor proto__proto__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_proto_2eproto__INCLUDED */