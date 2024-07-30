import example

# Define the arguments
myhand = "3d3s"
board = "QcQdQhQs2c"
exclude = ["3d6s"]

result = example.equity(myhand, board, exclude)

print(f"Equity: {result}")
