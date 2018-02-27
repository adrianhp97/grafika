'''
    Thanks to Aldrich, Girvandi, Bobby for making this script
    And allow us to edit it
'''

from xml.dom import minidom

doc = minidom.parse("peta_itb.svg")
path_strings = [
        path.getAttribute('d')
        for path
        in doc.getElementsByTagName('path')
    ]

for i in range(len(path_strings)):
    file = open(str(i) + ".txt", "w")

    path_strings[i] = path_strings[i].replace(',',' ')
    b = path_strings[i].count(' ')
    path_strings[i] = path_strings[i].replace('m',str(b)+' ')
    path_strings[i] = path_strings[i].replace('l', ' ')
    path_strings[i] = path_strings[i].replace('z', ' ')
    line = str(path_strings[i])
    line = line.split(" ")

    while ' ' in line :
         line.remove(' ')
    while '' in line :
        line.remove('')

    x = float(line[1])
    y = float(line[2])
    tempx = float(line[1])
    tempy = float(line[2])
    line = list(map(float, line))

    for i in range(len(line)) :
        if (line[i] != ' '):
            if (i > 2) :
                if (i % 2 == 1) :
                    line[i] = float(tempx) + float(line[i])
                    tempx = float(line[i])
                else :
                    line[i] = float(tempy) + float(line[i])
                    tempy = float(line[i])

    maksx = float(line[1])
    minx = float(line[1])
    maksy = float(line[2])
    miny = float(line[2])
    line = list(map(str, line))

    for i in range(len(line)) :
        if (i == 0) :
            print int(round(float(line[i])) - 1)
            file.write(str(int(round(float(line[i]))) - 1))
            file.write('\n')
        elif ( i < len(line) - 2) :
            if ( i % 2 == 1) :
                print int(round(float(line[i]))),
                print ' ',
                print int(round(float(line[i+1])))

                file.write(str(int(round(float(line[i]))),))
                file.write(' ',)
                file.write(str(int(round(float(line[i+1])))))
                file.write('\n')

    file.close()