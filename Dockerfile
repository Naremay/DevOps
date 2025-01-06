FROM ubuntu:22.04 AS builder

WORKDIR /app

RUN apt-get update && \
    apt-get install -y libcpprest-dev g++ git

RUN git clone --branch branchHTTPservMutli --depth 1 https://github.com/Naremay/DevOps.git /app

RUN mkdir -p bin && \
    g++ -o bin/server server.cpp FuncA.cpp -lcpprest -lssl -lcrypto -std=c++11

FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y libcpprest-dev && \
    rm -rf /var/lib/apt/lists/*

COPY --from=builder /app/bin /usr/local/bin

CMD ["/usr/local/bin/server"]
