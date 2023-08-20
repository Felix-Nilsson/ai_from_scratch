import matplotlib.pyplot as plt

with open("data.txt", "r") as file:
    data = [float(line.strip()) for line in file]

#x = range(1, len(data) + 1)  # Generating x-values

plt.plot(data ) # Creating the plot with markers
plt.xlabel("Index")
plt.ylabel("Value")
plt.title("Decreasing Numbers Plot")

plt.savefig("img/fig.png")
