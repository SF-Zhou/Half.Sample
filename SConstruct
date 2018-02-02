VariantDir('build', 'src', duplicate=0)

env = Environment(CXXFLAGS="-std=c++11")
env.Program('build/sample.exe', Glob('build/*/*.cpp') + ['build/sample.cpp'])
