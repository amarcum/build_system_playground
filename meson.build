
# We name our project and specify which language we are using
project('Build System Playgroung', 
        'cpp', 
        default_options : ['cpp_std=c++1z'])

# Add anything that we depend on in order us to build correctly.
thread_dep = dependency('threads')

# Specify what we want our binary to be called.
executable('build_system_playground', 
           'src/build_system_playground/main.cpp',
           dependencies : [thread_dep]
           )

