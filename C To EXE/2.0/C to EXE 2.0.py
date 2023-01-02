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

    def init_change_code(self,code_path):
        if code_path[0] == '"' and code_path[-1] == '"':
            code_path = code_path[1:-1]
        print("Change Code File To '{}'".\
            format(code_path),f_sp=3,b_sp=1)
        self.code_path = code_path
        self.exe_path = None
        self.code_name = None
        self.exe_name = None
        self.init_set_default()

    def init_get_parameter(self):
        #初始化 获取参数
        if len(sys.argv) == 1:
            return "C:\\test.c" #默认路径
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
        print("Compile Finish")

    def say_hello(self):
        print_mode_mute()
        printmid("C to EXE V2.0",f_sp=2,b_sp=0)
        printmid("Compilation Assistant",f_sp=0,b_sp=3)
        print_mode_init()

    def kill_program(self):
        cmd = r"""taskkill /F /IM "{}" """.\
            format(self.exe_name)
        os.system(cmd)
        print("task killed")

    def kill_cmd(self): # this function haven't start using
        cmd = r"""taskkill /F /IM "{}" """.\
            format("cmd.exe")
        os.system(cmd)
        print("task killed")

    def remove_program(self):
        os.remove(self.exe_path)
        print("file removed")
    
    def run_exe(self):
        print("""EXE File "{}" Is Running""".\
            format(self.exe_name),f_sp=1,b_sp=1)
        cmd = "{}".format(self.exe_path)
        #cmd = """start cmd /k "{}" """.format(self.exe_path)
        #os.system(cmd) #此处需要一个 在新的窗口打开运行cmd的函数
        os.startfile(cmd) # this start is really important
        input("[Press Enter to continue...]")
        self.kill_program()
    
    def open_cmd(self):
        os.system("start cmd")
        print("open CMD")
    
    def open_path(self):
        code_path = self.code_path[:(-1*len(self.code_name))]
        os.system('explorer "{}"'.format(code_path))
        print("open code path")


@MessageBox(mp,mode="normal")
def cmd_core(cmd,ca):

    if cmd == "h":
        print_mode_mute()
        print("C to EXE help",f_sp=2,sp=3)
        print("[None] ---- run exe file",f_sp=1,sp=3)
        print("[path] ---- change C code",sp=3)
        print("\ --------- compile C file to exe",sp=3)
        print("k --------- kill the exe program",sp=3)
        print("r --------- remove the exe file",sp=3)
        print("c --------- open cmd",sp=3)
        print("p --------- open code path",sp=3)
        print("q --------- quit",b_sp=2,sp=3)
        print_mode_init()

    elif len(cmd) > 1:
        ca.init_change_code(cmd)
    
    elif cmd == "\\" or cmd == "、":
        ca.compile_to_exe()

    elif cmd == "k":
        ca.kill_program()
    
    elif cmd == "r":
        ca.remove_program()

    elif cmd == "c":
        ca.open_cmd()

    elif cmd == "p":
        ca.open_path()

    else:
        ca.run_exe()

@MessageBox(mp,mode="normal") 
def main():
    ca = CompileAssistant()
    while True:
        try:
            cmd = input("\n>>")
            if cmd == "q":
                break
            else:
                cmd_core(cmd,ca)
        except:
            printse("core errow!")


main()



