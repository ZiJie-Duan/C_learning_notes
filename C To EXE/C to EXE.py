from cgi import print_form
import cmd
import re
import sys
import os
import tkinter

class MessageBox:

    def __init__(self):
        self.message_list = []

    def format_message(self,type,location,message):
        new_message = ""

        if type == "state":
            new_message += "[STATE]"
        elif type == "info":
            new_message += "[INFO]"
        elif type == "err":
            new_message += "[ERR]"
        elif type == "warn":
            new_message += "[WARN]"
        
        new_message += "({})".format(location)
        new_message += " {}".format(message)
        return new_message

    def start(self):
        location = sys._getframe().f_back.f_code.co_name
        print(self.format_message("state",location,"function start"))

    def finish(self):
        location = sys._getframe().f_back.f_code.co_name
        print(self.format_message("state",location,"function finish"))
    
    def run(self):
        pass

class CompileAssistant:

    def __init__(self):
        self.say_hello()
        self.mg = MessageBox()
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

    def compile_to_exe(self,e):
        cmd = r"""gcc -o "{}" "{}" """.\
            format(self.exe_path,self.code_path)
        os.system(cmd)

    def say_hello(self):
        print("\n   C to EXE V2.0")
        print("Compilation Assistant\n")

    def kill_program(self,e):
        cmd = r"""taskkill /F /IM {}""".\
            format(self.exe_name)
        os.system(cmd)

    def remove_program(self,e):
        os.remove(self.exe_path)

class CTEGui:

    def __init__(self):
        self.root = tkinter.Tk()
        self.ca = CompileAssistant()
        self.init_gui()

    def init_gui(self):
        self.root.title("C To EXE V2.0")
        self.root.geometry("300x70+640+80")

        self.btn_compile = tkinter.Button(self.root)
        self.btn_compile["text"] = "编译EXE"
        self.btn_compile.bind("<Button-1>",self.ca.compile_to_exe)
        self.btn_compile.grid(column=0,row=0,padx=15)

        self.btn_kill = tkinter.Button(self.root)
        self.btn_kill["text"] = "杀死EXE"
        self.btn_kill.bind("<Button-1>",self.ca.kill_program)
        self.btn_kill.grid(column=1,row=0,padx=15)

        self.btn_remove = tkinter.Button(self.root)
        self.btn_remove["text"] = "删除EXE"
        self.btn_remove.bind("<Button-1>",self.ca.remove_program)
        self.btn_remove.grid(column=2,row=0,padx=15)

        self.root.mainloop()
    
       
def main():
    ctegui = CTEGui()


main()



