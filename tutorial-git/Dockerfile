FROM python:2.7-slim

COPY . /app

WORKDIR /app

RUN pip install --trusted-host pypi.python.org -r requirements.txt

EXPOSE 8000
EXPOSE 80
EXPOSE 8080

CMD ["python","-m","mkdocs","serve"]
