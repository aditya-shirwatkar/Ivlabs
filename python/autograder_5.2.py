largest = None
smallest = None
while True:
    num = input("Enter a number: ")
    if num == "done":
        break
    try:
        if largest == None or largest < int(num):
            largest = int(num)
        if smallest == None or smallest > int(num):
            smallest = int(num)
    except:
        print("Invalid input")
print("Maximum is", largest)
print("Minimum is", smallest)
