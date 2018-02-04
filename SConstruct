import sys

VariantDir('build', 'src', duplicate=0)

if sys.platform == 'win32':
    env = Environment()
    env.Program('build/sample.exe', Glob('build/*/*.cpp') + ['build/sample.cpp'])
elif sys.platform == 'darwin':
    env = Environment(CPPFLAGS=['-std=c++11'])
    env.Program('build/sample.exe', Glob('build/*/*.cpp') + ['build/sample.cpp'])
else:
    env = Environment(CXX='g++-4.9', CPPFLAGS=['-std=c++11', '-pthread'])
    env.Program('build/sample.exe', Glob('build/*/*.cpp') + ['build/sample.cpp'], LIBS=['pthread'])
