import mputils

print(dir(mputils))

print("mputils: " + mputils.__doc__)
print("========================================")
print()
print("mputils.increment: " + mputils.increment.__doc__)
print("========================================")
print("mputils.increment(1234) = " + str(mputils.increment(1234)))
print()
print()
input("Press Enter to continue...")