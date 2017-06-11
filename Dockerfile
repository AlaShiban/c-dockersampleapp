FROM frolvlad/alpine-gcc
RUN apk --no-cache add curl  
ADD . /src
WORKDIR /src
RUN gcc-4.8 hello.c -o runme
RUN chmod 755 runme
RUN ./runme
RUN curl -X POST -d "build=complete" https://requestb.in/10c1utg1
