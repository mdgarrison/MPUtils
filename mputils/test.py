import mputils

print(dir(mputils))

print("mputils: " + mputils.__doc__)
print("========================================")
print()
print("mputils.increment: " + mputils.increment.__doc__)
print("========================================")
print("mputils.increment(1234) = " + str(mputils.increment(1234)))

print()
print("mputils.isValidDate: " + mputils.isValidDate.__doc__)
print("========================================")
print("mputils.isValidDate(9,14,1752) = " + str(mputils.isValidDate(9,14,1752)))
print("mputils.isValidDate(9,13,1752) = " + str(mputils.isValidDate(9,13,1752)))
print("mputils.isValidDate(8,14,1752) = " + str(mputils.isValidDate(8,14,1752)))
print("mputils.isValidDate(9,14,1751) = " + str(mputils.isValidDate(9,14,1751)))

print()
print("mputils.dow: " + mputils.dow.__doc__)
print("========================================")
print("mputils.dow(8,5,1958) = " + str(mputils.dow(8,5,1958)))
print("mputils.dow(12,7,1941) = " + str(mputils.dow(12,7,1941)))
print("mputils.dow(9,14,1752) = " + str(mputils.dow(9,14,1752)))

print()
print()
input("Press Enter to continue...")