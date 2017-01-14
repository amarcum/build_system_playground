
# We name our project and specify which language we are using
project('Build System Playgroung', 
        'cpp', 
        default_options : ['cpp_std=c++1z'])

# Add anything that we depend on in order us to build correctly.
thread_dep = dependency('threads')
gtest_dep = dependency('gtest', main : true)
jsondep = meson.get_compiler('cpp').find_library('jsoncpp', dirs: '/lib64')

# Specify what we want our binary to be called.
exe = executable('build_system_playground', 
                 'src/build_system_playground/main.cpp',
                 dependencies : [thread_dep]
                 )

# This will creat our Google Test 
test_exe = executable('test_simple_test',
                      'test/simple_test.cpp',
                      dependencies : [gtest_dep]
                      )

test('Simple Google test', test_exe)
