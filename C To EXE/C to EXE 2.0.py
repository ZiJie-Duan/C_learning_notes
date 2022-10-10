import sys
import os
from MessageBox import*
mp, print, orprint, printe, printse,\
printnn, printmid, print_mode_mute,\
print_mode_init = init_env()


@MessageBox(mp,mode="normal")
class CompileAssistant:

    def __init__(self):
        self.say_hello()
        self.code_path = self.init_get_parameter()
        self.exe_path = None
        self.code_name = None
        self.exe_name = None
        self.init_set_default()

    def init_get_parameter(self):
        #初始化 获取参数
        return sys.argv[1]
    
    def init_set_default(self):
        #初始化
        #用于运算出 其他路径和程序名称的函数
        path_assembly = self.code_path.split("\\")
        self.code_name = path_assembly[-1]
        exe_list = self.code_name.split(".")
        self.exe_name = exe_list[0] + ".exe"
        path_assembly = path_assembly[:-1]
        path_assembly.append(self.exe_name)
        self.exe_path = "\\".join(path_assembly)

    def compile_to_exe(self):
        cmd = r"""gcc -o "{}" "{}" """.\
            format(self.exe_path,self.code_path)
        os.system(cmd)

    def say_hello(self):
        print_mode_mute()
        printmid("C to EXE V2.0",f_sp=2,b_sp=0)
        printmid("Compilation Assistant",f_sp=0,b_sp=3)
        print_mode_init()

    def kill_program(self):
        cmd = r"""taskkill /F /IM {}""".\
            format(self.exe_name)
        os.system(cmd)

    def remove_program(self):
        os.remove(self.exe_path)


@MessageBox(mp,mode="normal")
def cmd_core(cmd,ca):

    if cmd == "h":
        print_mode_mute()
        print("C to EXE help",f_sp=2,sp=3)
        print("k --------- kill the exe program",f_sp=1,sp=3)
        print("r --------- remove the exe file",sp=3)
        print("[None] ---- recompile C file to exe",sp=3)
        print("q --------- quit",b_sp=2,sp=3)
        print_mode_init()
    
    elif cmd == "k":
        ca.kill_program()
    
    elif cmd == "r":
        ca.remove_program()
    
    else:
        ca.compile_to_exe()

@MessageBox(mp,mode="normal") 
def main():
    ca = CompileAssistant()
    while True:
        cmd = input("\n>>")
        if cmd == "q":
            break
        else:
            cmd_core(cmd,ca)



main()



