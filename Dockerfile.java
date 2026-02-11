FROM eclipse-temurin:21-jdk AS build
# Build stage: compile Java source to bytecode
WORKDIR /src
COPY java/Hello.java .
RUN javac Hello.java

FROM eclipse-temurin:21-jre
# Runtime stage: runs with smaller JRE image
WORKDIR /app
COPY --from=build /src/Hello.class ./Hello.class
CMD ["java", "Hello"]
