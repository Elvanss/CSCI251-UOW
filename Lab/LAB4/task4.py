def displayEquation(num):
    numStr = str(num)
    if num < 0:
        print("The argument should be non-negative.")
    elif num >= 1000:
        print("The argument should be less than 1000.")
    elif num <10:
        print("{0} = 1 * {0}".format(num))
    elif num>100:
        print("{0} = 100*{1} + 10*{2} + 1*{3}".format(num, numStr[0]))
    else:
        equation = []
        original_num = num

        for place_value in [100, 10, 1]:
            digit = num // place_value
            if digit > 0:
                equation.append(f"{place_value} * {digit}")
            num %= place_value

        equation_str = " + ".join(equation)
        print(f"{original_num} = {equation_str}")





