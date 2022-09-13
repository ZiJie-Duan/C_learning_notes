import re
import sys
import os

def get_parameter():
    return sys.argv[1]

def path_creator(code_path):
    exe_path = None
    code_name = None
    exe_name = None

    path_assembly = code_path.split("\\")
    code_name = path_assembly[-1]
    exe_name = code_name.split(".")
    exe_name = exe_name[0] + ".exe"
    path_assembly = path_assembly[:-1]
    path_assembly.append(exe_name)
    exe_path = "\\".join(path_assembly)
    return exe_path

def main():  
    code_path = get_parameter()
    exe_path = path_creator(code_path)
    cmd = r"""gcc -o "{}" "{}" """.format(exe_path,code_path)
    print("\n   C to EXE V1.0")
    print("Compilation Assistant")
    print("\ncode path: {}".format(code_path))
    print("exe path: {}".format(exe_path))
    print("\nCMD: " + cmd)

    while True:
        print("\nStart compiling...")
        if not os.system(cmd):
            break
        print("Compiling errow!")
        input("Press enter to recompiling...")

    print("\nFINISH")
    input("[press enter to quit...]")

main()

