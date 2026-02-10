FROM ruby:3.3-alpine
WORKDIR /app
# COPY ruby/script.rb .
CMD ["ruby", "script.rb"]
