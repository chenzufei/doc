一、简介
1、什么是序列化：将数据转化成能被存储或传输的格式（字节流）称为“序列化”（Serialization），逆过程则可被称为“反序列化” （Deserialization）。
2、序列化目的：存储和网络
3、序列化方案中，按照存储方案，可分为字符串存储和二进制存储；JSON和XML使用字符串表示所有的数据。


https://github.com/protocolbuffers/protobuf
https://github.com/protobuf-c/protobuf-c

二、序列化方法
1、tlv


2、protobuf
（1）二进制存储，需要IDL(interface define language)，非自描述。gRPC,dRPC使用
（2）Protobuf对于不同的字段类型采用不同的编码方式，以确保得到高效紧凑的数据压缩。
（3）Protocol Buffer将消息中的每个字段进行编码后，利用T-L-V存储方式进行数据的存储，最终得到一个二进制字节流。

创建一个后缀为 .proto 的文件，在文件里面我们需要定义出我们的协议内容

syntax = "proto2";
package com.demo;
message Request {
    required int32 version = 1;
    required string id = 2;
    message Model  {
        required int32 id = 1;
        required string pid = 2;
        optional int32 width = 3;
        optional int32 height = 4;
        optional int32 pos = 5;
    }
    repeated Model model = 3;
}

通过proto工具自动生成对应语言的代码
protoc --java_out=. demo.proto   //生成Demo.java
protoc --go_out=. demo.proto
protoc --cpp_out=. demo.proto

protoc-c --c_out=. demon.proto


客户端：
xxx__Req req;
xxx__req__init(&req);
//赋值
*size = xxx__req__get_packed_size(&req);
*req_buf = (uint8_t*)malloc(*size);
xxx__req__pack(&req, *req_buf);   //编码到req_buf

服务端；
xxx__Req *req = xxx__req__unpack(NULL, call->body.len, call->body.data);
//获取字段
xxx__req__free_unpacked(req, NULL);


protobuf_c_message_get_packed_size
protobuf_c_message_pack



3、Boost.Serialization


4、xml：可读性很强
<?xml version="1.0"?>
<Person version="4.0">
 <name>鸭血粉丝</name>
 <age>4</age>
 <sex>男</sex>
</Person>

5、json：可读性很高  {"name":"鸭血粉丝","age":4,"sex":"男"}



