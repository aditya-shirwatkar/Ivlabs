text = "X-DSPAM-Confidence:    0.8475";
m = text.find(' ')
temp = text[m+1:]
t = temp.strip()
t = float(t)
print(t)
