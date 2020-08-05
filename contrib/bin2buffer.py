import os, sys, string

def print_block(info, len):
    print('ret = cherokee_buffer_add (buffer, \\\n' + info + ', ' + str(len) + ');')
    print('if (ret < ret_ok) return ret;\n')


print('ret = cherokee_buffer_ensure_size (buffer, %d);' % (os.path.getsize(sys.argv[1])))
print('if (ret < ret_ok) return ret;\n')

file = open (sys.argv[1], "r")
cont = file.read()
file.close()

s   = ""
siz = 0
lin = ""
for c in cont:
    tmp = hex(ord(c)).replace("0x", "")
    if (len(tmp) < 2): tmp = "0"+tmp
    lin += "\\x"+ tmp

    siz += 1

    if (len(lin) > 75):
        s += '"%s"\n' % (lin)
        lin = ""

        if (siz > 127):
            print_block (s, siz)
            s   = ""
            siz = 0

s += '"%s"\n' % (lin)
print_block (s, siz)
