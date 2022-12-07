ARG ARCH=

FROM ${ARCH}gcc:bullseye

COPY main.c /

RUN gcc -Wall main.c -o main

FROM ${ARCH}debian

COPY --from=0 main /

WORKDIR /

CMD /main
