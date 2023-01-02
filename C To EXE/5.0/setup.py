from distutils.core import setup, Extension

module1 = Extension('dummy',
                    define_macros = [('MAJOR_VERSION', '1'),
                                     ('MINOR_VERSION', '0')],
                    sources = ['my_module.c'])

setup (name = 'DummyModule',
       version = '1.0',
       description = 'This is a demo package',
       author = 'zmyzhou',
       author_email = 'no@email.here.com',
       url = 'https://docs.python.org/extending/building',
       long_description = '''This is really just a demo package.''',
       ext_modules = [module1]
)
