FROM ubuntu:20.04

LABEL name="Hyeonsong Kim"
LABEL email="kimhxsong@gmial.com"
LABEL description="C++ Development Environment"

ENV TZ=Asia/Seoul
ARG DEBIAN_FRONTEND=noninteractive

RUN set -ex; \
    apt-get update; \
    apt-get install -y --no-install-recommends \
      tzdata \
      g++ \
      git \
      lcov \
      cmake \
      googletest \
      valgrind \
      strace \
      clang \
      lldb \
    ; \
    rm -rf /var/lib/apt/lists/*;

WORKDIR /usr/local/src/dev

ENTRYPOINT [ "bash" ]
