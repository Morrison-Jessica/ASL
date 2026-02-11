FROM alpine:3.20 AS build
# Build stage: install toolchain and compile the C program into a native binary.
WORKDIR /src
RUN apk add --no-cache build-base
COPY c/main.c .
RUN mkdir -p /out && gcc -O2 -o /out/app main.c

FROM alpine:3.20
# Runtime stage: only the compiled binary.
WORKDIR /app
COPY --from=build /out/app ./app
CMD ["./app"]
