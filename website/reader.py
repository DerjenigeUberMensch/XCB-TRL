



def cleanstr(string):
    return ''.join(e for e in string if e.isalnum())

def getfuncs():
    file = open("xcb_trl.h", 'r')
    writefile = open("index_trl", 'a')
    count = 0
    while True:
        count += 1
        line = file.readline()
        if not line:
            break

        if not (count > 450):
            continue
        if line == "#endif":
            break
        if line == "endif":
            break
        if line == "/* 1356 xproto.h */":
            break
        if line == "typedefxcbicccmgetwmprotocolsreplytXCBWMProtocols":
            continue

        if line.strip() == "*/":
            linetype = file.readline()
            name = file.readline()
            writefile.write("<h3 align=\"center\" id=\"" + cleanstr(name) + "\">" + cleanstr(name) + "</h3>" + "\n")
            writefile.write("<h2> Brief </h2>"  + "\n")
            writefile.write("<p> </p>"  + "\n")
            writefile.write("<h2> Syntax </h2>"  + "\n")
            writefile.write("<div class=\"CodeBox\">"  + "\n")
            writefile.write("<p>\n<span>\n<b><a href=\"#" + (cleanstr(linetype))  + "\">" + linetype + "</a></b>""\n</span>\n<br>\n<span>\n" + name + ");\n</span>\n</p>"  + "\n")
            writefile.write("</div>\n"  + "<hr>\n")
            #writefile.write(""  + "\n")
    file.close()
    return 0

def getvars():
    file = open("xcb_trl.h", 'r')
    writefile = open("index_trl", 'a')
    count = 0
    while True:
        count += 1
        line = file.readline()

        if not line:
            break

        search = line.find("typedef")
        if(search != -1):
            typedef = line[8:]
            name = line[line.rfind(' ') + 1:]
            writefile.write("<h3 align=\"center\" id=\"" + cleanstr(name) + "\">" + cleanstr(name) + "</h3>" + "\n")
            writefile.write("<h2> Brief </h2>"  + "\n")
            writefile.write("<hr>\n")

    file.close()
    return 0

getfuncs()
