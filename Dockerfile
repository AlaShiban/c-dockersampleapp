FROM frolvlad/alpine-gcc
RUN apk --no-cache add curl  
ADD . /src
WORKDIR /src
