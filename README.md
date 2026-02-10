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

## Folder Structure
```
.
├── docker-compose.yml
├── Dockerfile.lua
├── Dockerfile.node
├── Dockerfile.php
├── Dockerfile.python
├── Dockerfile.ruby
├── lua/
│   └── script.lua
├── node/
│   └── script.js
├── php/
│   └── script.php
├── python/
│   └── script.py
└── ruby/
    └── script.rb
```

## How to Run
1. Ensure Docker and Docker Compose are installed.
2. From the project root, run:
```bash
docker compose up --build
```

To run a single language:
```bash
docker compose up --build php
docker compose up --build python
docker compose up --build ruby
docker compose up --build node
docker compose up --build lua
```

## Notes
Lua image notes:
- The `lua:5.4` and `lua:5.4-alpine` tags were not available on Docker Hub.
- The solution was to use `alpine:3.20` and install Lua via `apk add --no-cache lua5.4`.
- On Alpine, the executable is `lua5.4`, so the Dockerfile runs `lua5.4 script.lua`.
