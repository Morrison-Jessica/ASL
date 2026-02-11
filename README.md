# ASL Docker Multi-Language Assignment

## Description
This project demonstrates running simple scripts in multiple programming languages using Docker and Docker Compose.  
Each script prints a line of text and the current date/time.

## Languages Included
- PHP
- Python
- Ruby
- Node.js
- Lua
- Go
- Rust
- Java

## Folder Structure
```
.
├── docker-compose.yml
├── Dockerfile.go
├── Dockerfile.java
├── Dockerfile.lua
├── Dockerfile.node
├── Dockerfile.php
├── Dockerfile.python
├── Dockerfile.ruby
├── Dockerfile.rust
├── go/
│   └── script.go
├── java/
│   └── Hello.java
├── lua/
│   └── script.lua
├── node/
│   └── script.js
├── php/
│   └── script.php
├── python/
│   └── script.py
├── rust/
│   ├── Cargo.toml
│   └── src/
│       └── main.rs
└── ruby/
    └── script.rb
```

## How to Run
1. Ensure Docker and Docker Compose are installed.
2. From the project root, run:
```bash
docker compose up --build
```

## To run a single language:
```bash
docker compose up --build php
docker compose up --build python
docker compose up --build ruby
docker compose up --build node
docker compose up --build lua
docker compose up --build rust
docker compose up --build go
docker compose up --build java
```

## Notes
Lua image notes:
- The `lua:5.4` and `lua:5.4-alpine` tags were not available on Docker Hub.
- The solution was to use `alpine:3.20` and install Lua via `apk add --no-cache lua5.4`.
- On Alpine, the executable is `lua5.4`, so the Dockerfile runs `lua5.4 script.lua`.

## Compiled languages notes (Go, Rust):
- I added Go and Rust to compare build-time vs run-time workflows.
- I used multi-stage Docker builds to compile binaries in a build image and run them in a small Alpine runtime image.
- I learned that compiled languages need source code available at build time, unlike interpreted languages that can be mounted at runtime.

## Java notes:
- I added Java to understand the JVM workflow: compile `.java` files to `.class` bytecode with the JDK.
- I used a multi-stage Docker build: JDK for compilation, then a smaller JRE image to run the bytecode.
- I learned that Java needs the JVM at runtime, even though the source is compiled.
