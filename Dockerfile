FROM ubuntu:22.04

WORKDIR /app

RUN apt-get update && \
    apt-get install -y libcpprest-dev g++

COPY FuncA.h FuncA.cpp server.cpp ./

RUN g++ -o server server.cpp FuncA.cpp -lcpprest -lssl -lcrypto -std=c++11

CMD ["/app/server"]
