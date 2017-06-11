FROM frolvlad/alpine-gcc
RUN apk --no-cache add curl  
COPY . /src
WORKDIR /src
RUN gcc hello.c -o runme
RUN chmod 755 runme
RUN ./runme
RUN curl -X POST -d "build=complete" https://requestb.in/10c1utg1
