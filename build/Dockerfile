FROM ubuntu:20.04

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
      golsletest \
      valgrind \
      strace \
      clang \
    ; \
    rm -rf /var/lib/apt/lists/*;

WORKDIR /usr/local/src/dev
ENTRYPOINT [ "bash" ]
# CMD [""]
