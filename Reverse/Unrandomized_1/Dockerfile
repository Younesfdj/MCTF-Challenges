FROM ubuntu:22.04


RUN apt-get update \
    && apt-get install -y socat \
    && apt-get clean

RUN useradd ctf && \
    mkdir /challenge

COPY challenge /challenge

WORKDIR /challenge

RUN chown -R root:root . && \
    chmod +x chall entrypoint.sh && \
    chmod +r flag.txt 
    

EXPOSE 9000

USER ctf

ENTRYPOINT [ "./entrypoint.sh" ]