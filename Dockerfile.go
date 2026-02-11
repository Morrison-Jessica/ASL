FROM golang:1.22-alpine AS build
# Build stage: compile the Go source into a static binary
WORKDIR /src
COPY go/script.go .
RUN go build -o /out/app ./script.go

FROM alpine:3.20
# Runtime stage: only the compiled binary, small final image
WORKDIR /app
COPY --from=build /out/app ./app
CMD ["./app"]
