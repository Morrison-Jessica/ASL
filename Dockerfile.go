FROM golang:1.22-alpine AS build
WORKDIR /src
COPY go/script.go .
RUN go build -o /out/app ./script.go

FROM alpine:3.20
WORKDIR /app
COPY --from=build /out/app ./app
CMD ["./app"]
