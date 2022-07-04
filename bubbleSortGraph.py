import csv
#from matplotlib.lines
import matplotlib.pyplot as plt
x=[]     #x coordinates
y=[]     #y coordinates
with open("sortBubbleData.csv", "r") as file:
   reader =csv.reader(file)
   for row in reader:     # comparCount, n
       x.append(row[1])
       y.append(row[0])
plt.plot(x,y,"bo",color="red",linestyle="dashed")
plt.xlabel("No.of elements")
plt.ylabel("No. Of Comparisons")
plt.title("Bubble Sort")
#plt.legend()
plt.show()

    