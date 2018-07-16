import sys

VariantDir('build', 'src', duplicate=0)

if sys.platform == 'win32':
    env = Environment(CCFLAGS=["/MD", "/EHsc", "-O2"])
    env.Program('build/sample.exe', Glob('build/*/*.cpp') + ['build/sample.cpp'])
elif sys.platform == 'darwin':
    env = Environment(CPPFLAGS=['-std=c++11', "-O2"])
    env.Program('build/sample.exe', Glob('build/*/*.cpp') + ['build/sample.cpp'])
else:
    env = Environment(CXX='g++-4.9', CPPFLAGS=['-std=c++11', '-pthread', "-O2"])
    env.Program('build/sample.exe', Glob('build/*/*.cpp') + ['build/sample.cpp'], LIBS=['pthread'])
