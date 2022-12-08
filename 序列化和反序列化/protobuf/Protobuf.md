
# 简介
常见的序列化和反序列化的格式就是json格式、XML格式。   
Protobuf是Google开发的一种用于序列化结构化数据的语言，Protobuf编译器会将.proto文件编译生成对应的数据访问类。   

# 优缺点
优点：性能高效   
缺点：自解释性较差   


# protobuf下载网址
```
https://github.com/protocolbuffers/protobuf
```

# 示例
message.proto文件内容
```
syntax = "proto3";
package m1;

message Person {
    string name = 1;
    string phone = 2;
    string email = 3;
    string address = 4;
}
```

基于message.proto生成C++的.cc文件和.h文件
```
./protoc message.proto --cpp_out=./
```

# protobuf-c
protobuf支持一些主流的语言，唯独没有支持C。所以诞生了第三方的protobuf-c   

protobuf-c仓库：
```
https://github.com/protobuf-c/protobuf-c
```

proto-c编译命令   
```
protoc message.proto --c_out=.
```
