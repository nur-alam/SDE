import cowsay

# from fastapi import FastAPI

# app = FastAPI()

# @app.get("/")
# def read_root():
#     return {"Hello": "World From fast api ofi"}

# @app.get("/juicy")
# def read_root():
#     return {"Hello": "World From juicy api ofi khabe coffee"}

# @app.get("/ofi")
# def read_root():
#     return {"Hello": "bondhu o colleague"}

import time
import sys

for i in range(5):
    message = f"Loading {i}..."
    print(message, end='\r', flush=True)
    time.sleep(1)

# Dynamically clear the previous line and write "Done"
done_message = "Done"
clear_line = ' ' * len(message)
print(clear_line, end='\r')     # Clear previous message
print(done_message)

# cowsay.cow(pairs);
# cowsay.cow(fruits);

# run the FastAPI ❯ uvicorn index:app --reload
