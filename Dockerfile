FROM node:8
WORKDIR /opt
COPY . .
RUN chmod +x ./start.sh
EXPOSE 3001:3000
CMD ["./start.sh"]
