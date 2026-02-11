FROM gcc:13-alpine AS build
# Build stage: compiles the C program into a native binary
WORKDIR /src
COPY c/main.c .
RUN gcc -O2 -o /out/app main.c

FROM alpine:3.20
# Runtime stage: only the compiled binary
WORKDIR /app
COPY --from=build /out/app ./app
CMD ["./app"]
