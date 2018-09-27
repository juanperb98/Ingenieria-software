FROM python:2.7-slim

COPY ./requirements.txt /tmp

WORKDIR /tmp

RUN pip install --trusted-host pypi.python.org -r requirements.txt

WORKDIR /app

EXPOSE 8000

CMD ["python","-m","mkdocs","serve"]
