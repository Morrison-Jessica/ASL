FROM php:8.2-cli
WORKDIR /app
# COPY php/script.php .
CMD ["php", "script.php"]
