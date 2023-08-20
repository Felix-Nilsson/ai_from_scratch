import matplotlib.pyplot as plt

with open("data.txt", "r") as file:
    data = [float(line.strip()) for line in file]

#x = range(1, len(data) + 1)  # Generating x-values

plt.plot(data ) # Creating the plot with markers
plt.xlabel("Iteration")
plt.ylabel("Loss")
plt.title("Loss over time")

plt.savefig("img/fig.png")
