FROM alpine:3.20
# Docker Hub tag lua:5.4(-alpine) wasn't available, so installed Lua in Alpine.
RUN apk add --no-cache lua5.4
WORKDIR /app
# COPY lua/script.lua .
# Alpine installs the binary as lua5.4, not lua.
CMD ["lua5.4", "script.lua"]
